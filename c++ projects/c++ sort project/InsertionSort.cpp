// John Pinto
// CSCI311.04
// Assignment 1
// Sorter.cpp
#include "InsertionSort.h"
#include <iostream>
#include <algorithm>

using namespace std;

InsertionSort::InsertionSort(int size) : Sort(size) 
{
}

InsertionSort::~InsertionSort() {
  count = 0;
  delete [] array;
}



void InsertionSort::sort() {
  int i, j;;
  for(i=0; i<count-1; i++) //this loop compares leftmost entity at time of check
    for(j=i+1; j<count; j++) if(array[i]>array[j]) swap(array[i], array[j]); // this loop is for checking every entity after the one currently being checked in the first loop
}


