// John Pinto
// CSCI311.04
// Assignment 3
// PartitionSort.cpp
#include "PartitionSort.h"
#include <iostream>
using namespace std;

PartitionSort::PartitionSort(int size) : Sort(size)
{
}

PartitionSort::~PartitionSort() {
  count = 0;
  delete [] array;
}

int PartitionSort::partition(float* fp, int len)
{
  int pivot = len-1;
  if(len>1) {
    int j;
    for(int i=len-2;i>=0;i--) {
      if (fp[pivot] <= fp[i]) {
        int temp=fp[i];
        for(j=i; j<len-1; j++) fp[j] = fp[j+1];
        fp[j]=temp;
        pivot--;
      }
    }
  }
  return pivot;
}

void PartitionSort::internal_sort(float* fp, int len) {
  if(len>0) {
    int partition_index=partition(fp, len);
    internal_sort(fp, partition_index);
    internal_sort(fp + partition_index + 1, len-partition_index-1);
  }
}

void PartitionSort::sort()
{
  if(count>0)
    internal_sort(array, count);
}




