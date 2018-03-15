#include "TrainingData.h"
#include "LinearRegression.h"
#include <iostream>
#include "utils.h"
using namespace std;

int main(int argc, char* argv[])
{
        
        vector<int> flavors;
        flavors.push_back(0);  // here for all kinds of types


        // set paras
        int duration   = 14;
        double alpha   = 0.01;
        int dimensions = 7;
        int num_iter   = 500;
        vector<int> results;

        train("./train.txt", alpha, dimensions, num_iter, duration, flavors, results);



        //for (int i = 0; i < results.size(); i++) {
                //cout<<results[i]<<endl;
        //}

        return 0;
}
