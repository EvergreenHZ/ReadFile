#include <dlfcn.h>
#include <stdio.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <map>
#include <string>


static std::map<int, std::string> fd_info_map;
static pthread_mutex_t mutex;
static bool mutex_inited = false;
static const int STACK_DEPTH = 40;

void save_backtrace(int fd)
{
        if (!mutex_inited)
                pthread_mutex_init(&mutex, NULL);

        int nptrs = 0;
        void *buffer[STACK_DEPTH];
        char **strings;

        nptrs = backtrace(buffer, STACK_DEPTH);

        strings = backtrace_symbols(buffer, nptrs);
        std::string bt;
        if (strings != NULL) {
                for (int i = 0; i < nptrs; i++) {
                        bt += strings[i];
                        bt += "\n";
                }
        }

        pthread_mutex_lock(&mutex);
        fd_info_map[fd] = bt;
        pthread_mutex_unlock(&mutex);
}

extern "C" void print_fd_info_map()
{
        printf("print_fd_info_map");
        if (!mutex_inited)
                pthread_mutex_init(&mutex, NULL);
        pthread_mutex_lock(&mutex);
        for (std::map<int, std::string>::iterator it = fd_info_map.begin(); it != fd_info_map.end(); it++) {
                printf("fd: %d, bt: %s\n", it->first, (it->second).c_str());
        }
        pthread_mutex_unlock(&mutex);
}

typedef int (*open_ptr)(const char*, int flags);
extern "C" int open(const char* pathname, int flags, ...)
{
        int fd = -1;

        open_ptr ori_open = (open_ptr)dlsym(RTLD_NEXT, "open");
        fd = ori_open(pathname, flags);

        printf("open: %d\n", fd);

        save_backtrace(fd);
        return fd;
}

typedef int (*close_ptr)(int);
extern "C" int close(int fd)
{
        if (fd_info_map.find(fd) != fd_info_map.end()) {
                fd_info_map.erase(fd);
        }
        printf("close fd: %d\n", fd);
        close_ptr ori_close = (close_ptr)dlsym(RTLD_NEXT, "close");
        return ori_close(fd);
}
