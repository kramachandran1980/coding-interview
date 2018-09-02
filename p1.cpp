// Given a vector xs of length ​ n​, design an algorithm of choice to sort its integers from
// lowest to highest value. Please avoid using in-built sort methods.

// Assumptions:
// The vector of integers will contain randomly sorted integers
// The vector of integers will fit in memory

#include "p1.h"

/*
partition() returns the index of the pivot
The pivot point will be greater than elements to the right and 
less than elements to the left.
*/
int partition(vector <int> &v, int start, int end) {
    
    //the pivot point used will be at end
    int pivot = v[end];
    
    //swapIdx will be where elements lower than the pivot value will be put
    int swapIdx = start;
     
    //for every element from start to end index
    for(int i = start; i < end; i++) {
        
        //if value at i is less than the pivot, then swap v[i] with swapIdx
        if(v[i] <= pivot) {
            swap(v[swapIdx], v[i]);
            
            //since an element lower than the pivot was swapped, iterate swapIdx
            swapIdx++;
        }
    }
    
    //now the pivot point at end will be swapped with swapIdx
    swap(v[end], v[swapIdx]);
    
    /*
    After the above swap, swapIdx is now the index of the pivot point. 
    
    The value at swapIdx will be greater than elements to the right and 
    less than elements to the left.
    
    Now this pivot index (swapIdx) is returned
    */
    
    return swapIdx;
}

//quicksort() is called recursively
void quicksort(vector <int> &v, int start, int end) {
    if(end <= start) {
        return;
    }
    
    /*
    all elements in the vector are partitioned to the left and right of 
    the pivot point returned by partition. 
    */
    int pivot = partition(v, start, end);
    quicksort(v, start, pivot - 1);
    quicksort(v, pivot + 1, end);
}

//sorting method used is quicksort
//quicksort will sort the given vector in place
void quicksort(vector <int> &v) {
    quicksort(v, 0, v.size()-1);
}