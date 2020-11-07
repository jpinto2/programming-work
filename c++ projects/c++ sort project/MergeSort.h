// John Pinto
// CSCI311.04
// Project 1
// MergeSort.h
#ifndef MERGESORT_H
#define MERGESORT_H
#include "TimePiece.h"
#include "Sort.h"
#include <iostream>
#include <algorithm>
using namespace std;

template<typename TYPE>
class MergeSort : public Sort<TYPE> {
  private:
    TYPE* merge(TYPE* la, int ls, TYPE* ra, int rs);
  public:
    MergeSort(int size);
    ~MergeSort();
    void sort();
};

template<typename TYPE>
MergeSort<TYPE>::MergeSort(int size) : Sort<TYPE>(size)
{
}

template<typename TYPE>
MergeSort<TYPE>::~MergeSort() {

}

template<typename TYPE>
TYPE* MergeSort<TYPE>::merge(TYPE* la, int ls, TYPE* ra, int rs)
{
  TYPE* results= new TYPE[ls+rs];
  if(ls>1)
  {
    //at this point, left_array is not sorted
    //sort left_array. How? Split left_array in half and call merge
    //at this point, left_array is still not sorted, so we need something like:
    //results=merge(1st half, 2nd half)
    la = merge(la, ls/2, la+ls/2, ls-ls/2);
  }

  if(rs>1) {
    ra = merge(ra, rs/2, ra+rs/2, rs-rs/2);
  }

  int lc=0; //left counter and right counter keep track of where I am in left and right array
  int rc=0;
  int current = 0; //keeps track of which spot I am at in the merged array
  int final = ls+rs; //when current reaches this value the mergesorted array is complete
  while(final>current) { // merge array process ends when there are no availabe array elements to merge
    if(la!=NULL && ra!=NULL && ls>lc && rs>rc) { //both arrays exist and have at least one element left to put in final array
      if(la[lc] < ra[rc]) {
        results[current] = la[lc];
        lc++;
      }
      else {
        results[current] = ra[rc];
        rc++;
      }
      current++; 
    }
    // if these else statement are reached, at least one array is finished or doesn't exist
    else if (la!=NULL && ls>lc) { 
      results[current] = la[lc];
      lc++;
      current++;
    }
    else {
      results[current] = ra[rc];
      rc++;
      current++;
    }
  } 
  if(rs>1)
    delete [] ra;
  if(ls>1)
    delete [] la;
  return results;                   

  //do the merging as described in the diagram
  //return results
}

template<typename TYPE>
void MergeSort<TYPE>::sort() {
  TYPE* mylist=new TYPE[this->count];
  for(int i=0; i<this->count; i++) mylist[i] = this->array[i]; 
  TYPE* sortedlist = merge(mylist, this->count, NULL, 0);
  for(int i=0; i<this->count; i++) this->array[i] = sortedlist[i];
  delete [] sortedlist;  
}
#endif

