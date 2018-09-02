#ifndef P3_H_
#define P3_H_

#include <vector>
#include <unordered_map>
#include <algorithm>//for max()

using namespace std;

int rob_max_value(vector<int> houses);
int rob_max_value_(vector<int> houses, int start, unordered_map<int, int> &table);


#endif