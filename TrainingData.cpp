#include "TrainingData.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

TrainingData::TrainingData(const char* file_path, int dims)
{
        num_flavor = 15;
        for (int i = 0; i < num_flavor; i++) {
                vector<int> t;
                table.push_back(t);
        }

        readFile(file_path);
        getMatrix();

        cols = table[0].size();
        dimensions = dims;
        last_index = cols - 1;
}

void TrainingData::readFile(const char* file_path)
{
        ifstream inf(file_path);
        string line;
        while(getline(inf, line)) {

                stringstream ss(line);
                string item;
                vector<string> records;
                while(getline(ss, item, '\t')) {
                        records.push_back(item);
                }
                string str_flavor = records[1];

                stringstream tmp_ss(records[2]);
                getline(tmp_ss, item, ' ');
                string str_time = item;

                string num_flavor = str_flavor.substr(6, str_flavor.length() - 6);
                flavors.push_back(num_flavor);
                time_sequence.push_back(str_time);
        }
        return ;
}


void TrainingData::getMatrix()
{
        string yesterday = time_sequence[0];
        int    flavor    = atoi(flavors[0].c_str());
        int    duration  = 0;
        for (int i = 0; i < table.size(); i++) {
                int amount = 0;
                if (i == flavor - 1) {
                        amount = 1;
                }
                table[i].push_back(amount);
        }

        for (int i = 1; i < time_sequence.size(); i++) {
                string today = time_sequence[i];
                int    len   = table[0].size();
                if (!today.compare(yesterday)) {
                        int row = atoi(flavors[i].c_str()) - 1;
                        if (row > 15) continue;
                        table[row][len - 1]++;
                } else {
                        for (int j = 0; j < table.size(); j++) {
                                int amount = 0;
                                if (j == flavor - 1) {
                                        amount = 1;
                                }
                                table[j].push_back(amount);
                        }
                        yesterday = today;
                }
        }
        return ;
}

void TrainingData::disp()
{
        for (int flavor = 0; flavor < num_flavor; flavor ++) {
                for (int i = 0; i < cols; i++) {
                        cout<<table[flavor][i]<<" ";
                }  cout<<endl;
        }
        return ;
}

void TrainingData::getLastx(int flavor, vector<int> &x)
{
}

void TrainingData::getXY(int flavor, vector< vector<int> > &X, vector<int> &Y)
{
}

void TrainingData::writeBack(int flavor, int pred_y)
{
}

void calculateSum(int flavor, int begin, int end)
{
}
