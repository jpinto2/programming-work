/* This file, openmpgauss.c was written by John Pinto. The purpose of this file is
   to write a c program to perform gaussian elimination with partial
   pivoting in parallel using openmp. 
   */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <omp.h>

void fill(int n, double** A, double** a, double* B, double* b);
void partialpivot(int n, double** a, double* b, int current);
void back(int n, double** a, double* b, double* x);

int main(int argc, char** argv){

  int n; // size of A matrix
  int i, j, k; // for loop variables
  srand48(time(0)); // seed random generator	
  int numthreads;
  int numproc = omp_get_num_procs();
#pragma omp parallel
  {
    numthreads = omp_get_num_threads();
  }

  double start, end, total; // time variables
  double r[n]; // residual vector for L2 norm
  double norm = 0; //L2 norm
  for(i=0; i<n; i++) r[i] = 0; // initializing to zero

  // Allocate memory for matrixes/arrays
  // create separate array for b so I could make arrays pointers to pass into functions
  double* A = (double*) malloc(sizeof(double)*n*n); // original A
  double* a = (double*) malloc(sizeof(double)*n*n); // A used for gaussian
  double* B = (double*) malloc(sizeof(double)*n); // original b
  double* b = (double*) malloc(sizeof(double)*n); // b
  double* x = (double*) malloc(sizeof(double)*n); // x

  fill(n, A, a, B, b); //Fill in
  double factor;

  //Gaussian Elimination
  omp_set_nested(1); // prevents nested parallelism. came up in research 
  start = omp_get_wtime();
  for (int j=0; j<n-1; j++){
    partialpivot(n, a, b, j);
    // 
#pragma omp parallel default(none) num_threads(numthreads) shared(n,a,b,j) private(i,k,factor)
    {
#pragma omp for schedule(static)
      for (int k=j+1; k<n; k++) {
        factor = a[k][j]/a[j][j];
        for (i=j; i<n; i++){
          a[k][i] = a[k][i] - (factor * a[j][i]);
        }
        b[k] = b[k] - (factor * b[j]);
      }
    }
  }

  /* Back substitution*/
  end = omp_get_wtime();
  total = end-start;
  back(n, a, b, x);	//tried doing this part in parallel but had issues
  getrusage(RUSAGE_SELF, &usage);

  printf("cores: %d\n", numproc);
  printf("threads: %d\n", numthreads);
  printf("time elased in sec: %.10e\n", total);

  // print original augmented matrix for size smaller than 11
  if (n<11) {
    printf("User CPU time in seconds: %.10e\n", (double) usage.ru_utime.tv_sec + 
        (double) usage.ru_utime.tv_usec/1000000);
    printf("System CPU time in seconds: %.10e\n", (double) usage.ru_stime.tv_sec + 
        (double) usage.ru_stime.tv_usec/1000000);
    printf("Maximum resident size: %ld\n", usage.ru_maxrss);
    printf("Minor page faults: %ld\n", usage.ru_minflt);
    printf("Major page faults: %ld\n", usage.ru_majflt);
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        printf("%.10e ", A[i][j]);
      }
      printf("%.10e ", B[i];
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
          r[i] -= B[i];
          }

          //create L-2 norm
          for(i=0; i<n; i++) norm += r[i]*r[i];
          norm = sqrt(norm);
          printf("L2 norm = %.10e\n", norm);

          return 0;
}

void partialpivot(int n, double** a, double* b, int current) {

  int i, k;
  int pivot = current;
  double temp;
  double largest = fabs(a[current][current]);

  for(i=current+1; i<n; i++) {
    if (fabs(a[i][current]) > largest) { // set new largest pivot
      pivot = i;
      largest = fabs(a[i][current]);
    }	
  }

  if (pivot != current) { // pivot only if largest is below current row in i
    for(k=0; k<n; k++) {
      temp = a[pivot][k];
      a[pivot][k] = a[current][k];
      a[current][k] = temp;
    }
    temp = b[pivot];
    b[pivot] = b[current];
    b[current] = temp;
  }
}

void fill(int n, double** A, double** a, double* B, double* b) {
  int i, j;
  if (n<11) {
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        if(!scanf("%lf", &A[i][j])) printf("error\n");
        a[i][j] = A[i][j];
      }
      if(!scanf("%lf", &B[i])) printf("error\n");
      b[i] = B[i];
    }
  }
  else {
    for(i=0; i<n; i++) {
      for(j=0; j<n; j++) {
        A[i][j] = -1 + (drand48()*2.e6);
        a[i][j] = A[i][j];
      }
      B[i] = -1 + (drand48()*2.e6);
      b[i] = B[i];
    }		
  }
}

void back(int n, double** a, double* b, double* x) {
  int i,j;
  for(i=n-1; i>=0; i--) {
    x[i] = b[i];
    for(j=i+1; j<n; j++) {
      x[i] -= a[i][j]*x[j];
    }
    x[i] = x[i]/a[i][i];
  }	
}




