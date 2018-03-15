#include "utils.h"
#include <iostream>
#include <vector>
#include "LinearRegression.h"
#include "TrainingData.h"
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

void train(const char* train_file_path, double alpha, int dimensions, \
                int num_iter, int duration, vector<int> &flavors, \
                vector<int> &results)
{
        TrainingData data(train_file_path, dimensions);
        vector< vector< vector<int> > > Xs;
        vector< vector<int> > Ys;
        cout<<"Preparing Data:"<<endl;
        for (int i = 0; i < flavors.size(); i++) {
                int flavor = flavors[i];
                vector< vector<int> > X;
                vector<int> Y;
                data.getXY(flavor, X, Y);
                Xs.push_back(X);
                Ys.push_back(Y);
        }
        cout<<"flavors: "<<flavors.size()<<endl;

        cout<<"Start Training:"<<endl;
        for (int i = 0; i < flavors.size();i ++) {
                int flavor = flavors[i];
                cout<<"For flavor "<<flavor<<endl;
                LinearRegression lr(dimensions, num_iter, alpha);
                lr.fit(Xs[i], Ys[i]);  // train

                //lr.dispParas();

                data.prediction(flavor, duration, lr);  // predict
                cout<<endl<<endl;
        }

        for (int i = 0; i < flavors.size(); i++) {  // get the result
                int flavor = flavors[i];
                results.push_back( data.calculateSum(flavor, data.cols, data.cols + duration - 1) );

        }
}
