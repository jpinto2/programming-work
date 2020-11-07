// John Pinto
// CSCI311.04
// Lab 3
// lab03.cpp
#include<iostream>
using namespace std;

float* merge(float* la, int ls, 
    float* ra, int rs)
{
  float* results= new float[ls+rs];
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


int main()
{
  int count;
  cin >> count;
  float* mylist=new float[count];
  for(int i=0; i<count; i++) cin >> mylist[i];
  float* sortedlist = merge(mylist, count, NULL, 0);
  for(int i=0; i<count; i++) {
    cout << sortedlist[i];
    if (i<count-1) cout << " ";
  }
  cout << endl;
  delete [] sortedlist;
  return 0;
}
