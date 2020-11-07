// John Pinto
// CSCI311.04
// Project 1
// InsertionSort.h
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "TimePiece.h"
#include "Sort.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename TYPE>
class InsertionSort : public Sort<TYPE> {
  public:
    InsertionSort(int size);
    ~InsertionSort();
    void sort();
};

template<typename TYPE>
InsertionSort<TYPE>::InsertionSort(int size) : Sort<TYPE>(size) 
{
}

template<typename TYPE>
InsertionSort<TYPE>::~InsertionSort() {

}

template<typename TYPE>
void InsertionSort<TYPE>::sort() {
  int i, j;;
  for(i=0; i<this->count-1; i++) //this loop compares leftmost entity at time of check
    for(j=i+1; j<this->count; j++) if(this->array[i]>this->array[j]) swap(this->array[i], this->array[j]); // this loop is for checking every entity after the one currently being checked in the first loop
}
#endif

