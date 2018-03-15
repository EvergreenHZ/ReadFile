#ifndef UTILS_H
#define UTILS_H

#include <vector>
void showVec(std::vector<int> &x);

double dot(std::vector<double> &x, std::vector<int> &y);

void showMat(std::vector< std::vector<int> > &matrix);

void train(const char* , double alpha, int dimensions, int num_iter, \
           int duration, std::vector<int> &flavors, \
           std::vector<int> &results);

#endif
