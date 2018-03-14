#include "utils.h"
#include <iostream>
#include <vector>
using namespace std;

//void dot(vector<double> &x, vector<double> &y, vector<double> &z);
void showVec(vector<int> &x)
{
        for (int i = 0; i < x.size(); i++) {
                cout<<x[i]<< " ";
        }  cout<<endl;
}

void showMat(vector< vector<int> > &matrix)
{
        for (int i = 0; i < matrix.size(); i++) {
                showVec(matrix[i]);
        }
}

double dot(vector<double> &x, vector<int> &y)
{
        if (x.size() != y.size()) {
                cout<< "vector dims not match"<<endl;
        }

        double s = 0.;
        for (int i = 0; i < x.size(); i++) {
                s += x[i] * y[i];
        }
        return s;
}
