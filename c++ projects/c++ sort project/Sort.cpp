// John Pinto
// CSCI311.04
// Assignment 4
// HeapSort.cpp
#include "Sort.h"
#include <iostream>
#include <algorithm>
using namespace std;

Sort::Sort(int size) : array(new float[size]), count(0), max(size)
{
}

Sort::~Sort()
{
}

void Sort::add(float b) {
  array[count] = b;
  count++;
}

void Sort::display() {
  for(int i=0; i<count; i++) {
    cout << array[i];
    if (i<count-1) cout << " ";
  }
  cout << endl;
}




