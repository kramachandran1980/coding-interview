#ifndef P1_H_
#define P1_H_

#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

/*
partition() returns the index of the pivot
The pivot point will be greater than elements to the right and 
less than elements to the left.
*/
int partition(vector <int> &v, int start, int end);
void quicksort(vector <int> &v, int start, int end);
void quicksort(vector <int> &v);

#endif