#include "TrainingData.h"
#include <iostream>
using namespace std;

int main()
{
        TrainingData data("./train.txt", 7);
        data.disp();

        return 0;
}
