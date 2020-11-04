# Build Shared Obejct
> g++ -shared -fPIC open_close_wrapper.cpp -o open_close_wrapper.so -ldl


# Run Test Code
> g++ test.cpp  
> LD_PRELOAD=./open_close_wrapper.so ./a.out
