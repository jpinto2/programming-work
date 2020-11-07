// John Pinto
// CSCI311.04
// Project 1
// project1.cpp
#include "TimePiece.h"
#include "Sort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include<iostream>
using namespace std;

int main()
{
  Sort<TimePiece> *sp;
  int choice, count;
  TimePiece num;
  cin >> choice >> count;
  
  if(choice==1) sp=new QuickSort<TimePiece>(count);
  
  else if(choice==2) sp=new HeapSort<TimePiece>(count);
  
  else if(choice==3) sp=new MergeSort<TimePiece>(count);
  
  else if(choice==4) sp=new InsertionSort<TimePiece>(count);
  
  else {
       cerr << "Error: invalid choice." << endl;
       return 1;
  }

  for(int i=0; i<count; ++i)
  {
    cin >> num;
    sp->add(num);
  }
  sp->display();
  sp->sort();
  sp->display();
  delete sp;
  return 0;

}


