#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
using namespace std;

int main ()
{
        int fd = open("inspect_open.cpp", 0);
        cout << "fd is: " << fd << endl;

        return 0;
}
