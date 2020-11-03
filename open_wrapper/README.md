# Build Shared Obejct
> g++ -shared -fPIC inspect_open.cpp -o inspect_open.so -ldl


# Run Test Code
> g++ test.cpp
> LD_PRELOAD=./inspect_open.so ./a.out
