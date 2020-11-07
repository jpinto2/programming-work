// John Pinto
// CSCI311.04
// Project 1
// Sort.h
#ifndef SORT_H
#define SORT_H
#include "TimePiece.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename TYPE>
class Sort {
  public:
    Sort(int size);
    void add(TYPE b);
    virtual void sort(void)=0;
    void display(void);
    virtual ~Sort();
  protected:
    TYPE* array;
    int count;
    const int max;
    virtual void internal_sort(int index, int len) {}
    virtual int LEFT(int index) {}
    virtual int RIGHT(int index) {}
    virtual void internal_sort(TYPE* fp, int len) {}
    virtual int partition(TYPE* fp, int len) {}
    virtual TYPE* merge(TYPE* la, int ls, TYPE* ra, int rs) {}
};

template<typename TYPE>
Sort<TYPE>::Sort(int size) : array(new TYPE[size]), count(0), max(size)
{
}

template<typename TYPE>
Sort<TYPE>::~Sort()
{
  count = 0;
  delete [] array;
}

template<typename TYPE>
void Sort<TYPE>::add(TYPE b) {
  array[count] = b;
  count++;
}

template<typename TYPE>
void Sort<TYPE>::display() {
  for(int i=0; i<count; i++) {
    cout << array[i];
    if (i<count-1) cout << " ";
  }
  cout << endl;
}

#endif
