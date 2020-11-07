/* This file, gauss.c was written by John Pinto. The purpose of this file is
   to write a c program to serially perform gaussian elimination with partial
   pivoting. 

   gcc -O1 -Wall -W -Werror -o gaussian gaussian.c -lm */

#include <sys/time.h>
#include <sys/resource.h>   
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
  int n; // size of A matrix
  int i, j, k; // for loop variables
  int pivot; // row with largest absolute value for current A column
  double largest; // value of first active column in the pivot row
  double temp; // temp variable used in pivot row swap
  double sum; // used to sum up Ax for all known x's in back substitution
  srand48(time(0)); // seed random generator
  if (!scanf("%d", &n)) printf("error\n"); // get size of A by from user
  double A[n][n+1]; //orginal augmented matrix. stores A|b
  double x[n]; // vector for x
  double a[n][n+1]; //augmented matrix used to perform Gaussian with pivot. A|b
  double r[n]; // residual vector for L2 norm
  double norm = 0; //L2 norm
  struct rusage usage; // the struct rusage needed for getrusage call
  for(i=0; i<n; i++) r[i] = 0; // initializing to zero

  /* The if else statement below is for assigning values to the A matrix based on 
     size, n,  given by user. Values are read from user if n<11. Otherwise, a 
     random call is done to get a random value in [-1.0,1.0) range */

  if (n<11) {
    for(i=0; i<n; i++) {
      for(j=0; j<=n; j++) {
        if(!scanf("%lf", &A[i][j])) printf("error\n");
        a[i][j] = A[i][j];
      }
    }
  }
  else {
    for(i=0; i<n; i++) {
      for(j=0; j<=n; j++) {
        A[i][j] = -1 + (drand48()*2.e6);
        a[i][j] = A[i][j];
      }
    }		
  }

  /* Gaussian Elimination with Partial pivoting */	
  for(i=0; i<n; i++) {
    pivot = i;
    largest = fabs(a[i][i]);
    for(j=i+1; j<n; j++) {
      if (fabs(a[j][i]) > largest) { // set new largest pivot
        pivot = j;
        largest = fabs(a[j][i]);
      }	
    }
    if (pivot != i) { // pivot only if largest is below current row in i
      for(k=0; k<=n; k++) {
        temp = a[pivot][k];
        a[pivot][k] = a[i][k];
        a[i][k] = temp;
      }
    }
    //pivoting is done for current row. now perform gaussian elimination		
    for(j=i+1; j<n; j++) {
      double factor = a[j][i]/a[i][i];
      for(k=i+1; k<=n; k++) {
        a[j][k] -= a[i][k]*factor;
      }
    }
  }

  /* Back substitution*/	
  x[n-1] = a[n-1][n]/a[n-1][n-1];
  for(i=n-2; i>=0; i--) {
    sum = 0;
    for(j=i+1; j<n; j++) {
      sum += a[i][j]*x[j];
    }
    x[i]=(a[i][n]-sum)/a[i][i];
  }

  getrusage(RUSAGE_SELF, &usage);

  printf("User CPU time in seconds: %.10e\n", (double) usage.ru_utime.tv_sec + 
      (double) usage.ru_utime.tv_usec/1000000);
  printf("System CPU time in seconds: %.10e\n", (double) usage.ru_stime.tv_sec + 
      (double) usage.ru_stime.tv_usec/1000000);
  printf("Maximum resident size: %ld\n", usage.ru_maxrss);
  printf("Minor page faults: %ld\n", usage.ru_minflt);
  printf("Major page faults: %ld\n", usage.ru_majflt);

  // print original augmented matrix for size smaller than 11
  if (n<11) {
    for(i=0; i<n; i++) {
      for(j=0; j<=n; j++) {
        printf("%.10e ", A[i][j]);
      }
      printf("\n");
    }
    for(i=0; i<n; i++) printf("%.10e ", x[i]);
  }
  printf("\n");

  // create residual vector r = Ax-b
  for(i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      r[i] += A[i][j]*x[j];

    }
    r[i] -= A[i][n]; // A[i][n] = b[i]
  }

  //create L-2 norm
  for(i=0; i<n; i++) norm += r[i]*r[i];
  norm = sqrt(norm);
  printf("L2 norm = %.10e\n", norm);

  return 0;
}
