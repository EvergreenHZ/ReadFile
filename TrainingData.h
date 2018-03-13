#ifndef TRAININGDATA_H
#define TRAININGDATA_H
#include<string>
#include<vector>
using namespace std;
class TrainingData {
        public:
                std::vector< std::vector<int> > table;
                //int **matrix;
                int num_flavor;
                int cols;
                int dimensions;
                int last_index;

        public:
                TrainingData(const char* , int);
                
                void getLastx(int flavor, vector<int> &x);

                void getXY(int flavor, vector< vector<int> > &X, vector<int> &Y);

                void  writeBack(int flavor, int pred_y);

                int calculateSum(int flavor, int begin, int end);

                void disp();

        private:
                void readFile(const char*);

                void getMatrix();
        private:
                vector<std::string> flavors, time_sequence;
};

#endif