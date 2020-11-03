#include <dlfcn.h>
#include <stdio.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int (*open_ptr)(const char*, int flags);

void print_backtrace()
{
        static const int STACK_DEPTH = 40;
        int nptrs = 0;
        void *buffer[STACK_DEPTH];
        char **strings;

        nptrs = backtrace(buffer, STACK_DEPTH);

        strings = backtrace_symbols(buffer, nptrs);
        if (strings != NULL) {
                for (int i = 0; i < nptrs; i++) {
                        printf("%s\n", strings[i]);
                }
        }
}


extern "C" int open(const char* pathname, int flags, ...)
{

        open_ptr ori_open = (open_ptr)dlsym(RTLD_NEXT, "open");
        print_backtrace();
        //printf("%s\n", pathname);
        return ori_open(pathname, flags);
}
