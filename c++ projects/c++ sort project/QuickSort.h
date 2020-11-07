// John Pinto
// CSCI311.04
// Project 1
// QuickSort.h
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "TimePiece.h"
#include "Sort.h"
#include <iostream>
using namespace std;

template<typename TYPE>
class QuickSort : public Sort<TYPE> {
  private:
    void internal_sort(TYPE* fp, int len);
    int partition(TYPE* fp, int len);
  public:
    QuickSort(int size);
    ~QuickSort();
    void sort();
};

template<typename TYPE>
QuickSort<TYPE>::QuickSort(int size) : Sort<TYPE>(size)
{
}

template<typename TYPE>
QuickSort<TYPE>::~QuickSort() {

}

template<typename TYPE>
int QuickSort<TYPE>::partition(TYPE* fp, int len)
{
  int pivot = len-1;
  if(len>1) {
    int j;
    for(int i=len-2;i>=0;i--) {
      if (fp[pivot] <= fp[i]) {
        TYPE temp=fp[i];
        for(j=i; j<len-1; j++) fp[j] = fp[j+1];
        fp[j]=temp;
        pivot--;
      }
    }
  }
  return pivot;
}

template<typename TYPE>
void QuickSort<TYPE>::internal_sort(TYPE* fp, int len) {
  if(len>0) {
    int partition_index=partition(fp, len);
    internal_sort(fp, partition_index);
    internal_sort(fp + partition_index + 1, len-partition_index-1);
  }
}

template<typename TYPE>
void QuickSort<TYPE>::sort()
{
  if(this->count>0)
    internal_sort(this->array, this->count);
}
#endif

