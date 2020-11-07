// John Pinto
// CSCI311.04
// Project 1
// HeapSort.h
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "TimePiece.h"
#include "Sort.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename TYPE>
class HeapSort : public Sort<TYPE> {
  private:
    void internal_sort(int index, int len);
    int LEFT(int index);
    int RIGHT(int index);
  public:
    HeapSort(int size);
    ~HeapSort();
    void sort();
};

template<typename TYPE>
HeapSort<TYPE>::HeapSort(int size) : Sort<TYPE>(size)
{
}

template<typename TYPE>
HeapSort<TYPE>::~HeapSort() {

}

template<typename TYPE>
int HeapSort<TYPE>::LEFT(int index) {
    int i=2*index+1;
    return i;
}

template<typename TYPE>
int HeapSort<TYPE>::RIGHT(int index) {
    int i=2*index+2;
    return i;
}

template<typename TYPE>
void HeapSort<TYPE>::internal_sort(int index, int len) {
  int left = LEFT(index);
  int right = RIGHT(index);
  if(right<len) { // right node exists which implies that left node exists as well since left node index is one less than right node index
              
    if(this->array[left]>this->array[index] && this->array[left]>=this->array[right]) { //replaced > with >=. avoids glitch if left and right node equal each other while left is greater than parent
      swap(this->array[left], this->array[index]);
      internal_sort(left, len);
    }
    
    else if(this->array[right]>this->array[index] && this->array[right]>this->array[left]) {
      swap(this->array[right], this->array[index]);
      internal_sort(right, len);
    }
  }
// if program goes past this point on a function call, then parent has either no child nodes or only a left child node
  else if(left<len && this->array[left]>this->array[index]) {
    swap(this->array[left], this->array[index]);
    internal_sort(left, len);
  }
    
}

template<typename TYPE>
void HeapSort<TYPE>::sort() {
  for(int i=this->count/2; i>=0; --i) internal_sort(i, this->count);
  
  if(this->count>1) { //count must be greater than 1 to have something to swap with
  swap(this->array[0], this->array[this->count-1]);
  for(int j=this->count-1; j>1; j--) { //j is the updated count, must be more than one to have something to swap with
    internal_sort(0, j);
    swap(this->array[0], this->array[j-1]);
  }
}

}
#endif

