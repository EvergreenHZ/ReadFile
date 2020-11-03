#include <dlfcn.h>
#include <stdio.h>

typedef int (*open_ptr)(const char*, int flags);

extern "C" int open(const char* pathname, int flags, ...)
{
        open_ptr ori_open = (open_ptr)dlsym(RTLD_NEXT, "open");
        printf("%s\n", pathname);
        return ori_open(pathname, flags);
}
