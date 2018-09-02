#include "p3.h"
//ASSUMPTIONS:
//A valid list of integer houses will be passed in as a vector

int rob_max_value_(vector<int> houses, int start, unordered_map<int, int> &table) {
    
    //if rob_max_value() was already called with the current start value, 
    //then return the previously recorded answer
    if(table.find(start) != table.end()) {
        return table[start];
    }
    
    //return 0 if start is past the size of houses
    if(start > houses.size() - 1) {
        return 0;
    }
    
    //if start is at idx of the last hosue, return its value
    if(start == houses.size() - 1) {
        return houses[start];
    }
    
    //first option is to rob the starting house and skip the next house
    int option1 = houses[start] + rob_max_value_(houses, start + 2, table);
    
    //second option is to skip the starting house and rob the next hosue
    int option2 = rob_max_value_(houses, start + 1, table);
    
    //maxVal will be the most valuable option
    int maxVal = max(option1, option2);
    
    //record the return value in the table with start as the key
    table[start] = maxVal;
    
    return maxVal;
}

//this is the function to call
int rob_max_value(vector<int> houses) {
    unordered_map<int, int> table;
    
    //houses is a vector of housese and their values
    //0 is passed in to denote that we want to get the max value starting from house 0
    //table is a map used for memoization of the rob_max_value function
    return rob_max_value_(houses, 0, table);
}