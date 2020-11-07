// John Pinto
// CSCI311.04
// Assignment 4
// HeapSort.cpp
#include "HeapSort.h"
#include <iostream>
#include <algorithm>
using namespace std;

HeapSort::HeapSort(int size) : Sort(size)
{
}

HeapSort::~HeapSort() {
  count = 0;
  delete [] array;
}

int HeapSort::LEFT(int index) {
    int i=2*index+1;
    return i;
}

int HeapSort::RIGHT(int index) {
    int i=2*index+2;
    return i;
}

void HeapSort::internal_sort(int index, int len) {
  int left = LEFT(index);
  int right = RIGHT(index);
  if(right<len) { // right node exists which implies that left node exists as well since left node index is one less than right node index
              
    if(array[left]>array[index] && array[left]>=array[right]) { //replaced > with >=. avoids glitch if left and right node equal each other while left is greater than parent
      swap(array[left], array[index]);
      internal_sort(left, len);
    }
    
    else if(array[right]>array[index] && array[right]>array[left]) {
      swap(array[right], array[index]);
      internal_sort(right, len);
    }
  }
// if program goes past this point on a function call, then parent has either no child nodes or only a left child node
  else if(left<len && array[left]>array[index]) {
    swap(array[left], array[index]);
    internal_sort(left, len);
  }
    
}

void HeapSort::sort() {
  for(int i=count/2; i>=0; --i) internal_sort(i, count);
  
  if(count>1) { //count must be greater than 1 to have something to swap with
  swap(array[0], array[count-1]);
  for(int j=count-1; j>1; j--) { //j is the updated count, must be more than one to have something to swap with
    internal_sort(0, j);
    swap(array[0], array[j-1]);
  }
}

}




