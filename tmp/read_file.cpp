#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
using namespace std;

void readFile(string file_path, vector<string> &flavors, vector<string> &time_sequence)
{
        ifstream inf(file_path.c_str());
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

void getAllFlavors(vector<string> &flavors, vector<string> &time_sequence, vector< vector<int> > &types)
{
        string yesterday = time_sequence[0];
        int    flavor    = atoi(flavors[0].c_str());
        //int    flavor    = stoi(flavors[0]);
        int    duration  = 0;
        for (int i = 0; i < types.size(); i++) {
                int amount = 0;
                if (i == flavor - 1) {
                        amount = 1;
                }
                types[i].push_back(amount);
        }

        for (int i = 1; i < time_sequence.size(); i++) {
                string today = time_sequence[i];
                int    len   = types[0].size();
                if (!today.compare(yesterday)) {
                        int row = atoi(flavors[i].c_str()) - 1;
                        if (row > 15) continue;
                        types[row][len - 1]++;
                } else {
                        for (int j = 0; j < types.size(); j++) {
                                int amount = 0;
                                if (j == flavor - 1) {
                                        amount = 1;
                                }
                                types[j].push_back(amount);
                        }
                        yesterday = today;
                }
        }

        return ;
}

int main()
{
        vector<string> flavors, time_sequence;
        readFile("train.txt", flavors, time_sequence);
        vector< vector<int> > types;
        for (int i = 0; i < 16; i++) {
                vector<int> t;
                types.push_back(t);
        }
        getAllFlavors(flavors, time_sequence, types);
        //for (int i = 0; i < types[14].size(); i++) {
        //        cout<<types[14][i]<<" ";
        //}cout<<endl;
        for (int i = 0; i < types.size(); i++) {
                for (int j = 0; j < types[i].size(); j++) {
                        cout<<types[i][j]<<" ";
                }cout<<endl;
        }
        return 0;
}
