#include "TrainingData.h"
#include "LinearRegression.h"
#include <iostream>
#include "utils.h"
using namespace std;

int main()
{
        TrainingData data("./train.txt", 7);
        //data.disp();

        vector< vector<int> > X;
        vector<int> Y;
        data.getXY(14, X, Y);


        int prediction_time = 14;

        //showVec(Y);
        //for (int i = 0; i < X.size(); i ++) {
        //showVec(X[i]);
        //}
        double alpha     = 0.01;
        double dimensions = 7;
        double num_iter  = 500;
        LinearRegression lr(dimensions, num_iter, alpha);
        lr.fit(X, Y);

        lr.dispParas();
        double s = 0.0;
        for (int i = 0; i < dimensions + 1; i++) {
                s += lr.coef(i, 0);
        }
        cout<<s<<endl;

        //cout<<"cost function history: ";
        //for (int i = 0; i < lr.J_hist.size(); i++) {
        //        cout<< lr.J_hist[i]<<" ";
        //}  cout<<endl;

        //for (int flavor = 0; flavor < 15; flavor++) {
        //        cout<<"This is for flavor"<<flavor<<":"<<endl;
        //        for (int i = 0; i < prediction_time; i++) {
        //                vector<int> x;
        //                //data.getLastx(flavor, x);
        //                data.preparex(flavor, x, data.cols + i);
        //                //showVec(x);
        //                int pred_y = lr.predict(x);
        //                cout<<pred_y<<" ";
        //                data.writeBack(flavor, pred_y, data.cols + i);
        //        }  cout<<endl;
        //}  cout<<endl;


        //for (int flavor = 0; flavor < 15; flavor++) {
        //        for (int i = data.cols; i < data.cols + prediction_time; i++) {
        //                cout<<data.table[flavor][i]<<" ";
        //        }  cout<<endl;
        //}

        //while(true) {}

        return 0;
}
