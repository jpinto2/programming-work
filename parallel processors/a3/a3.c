/*
John Pinto
Assignment 3: MPI matrix multiplication
file: a3.c
use pacheco code as reference.

Input:
<form>
<flag>
<n>
<A>
<B>

where <form> is one of ijk, ikj, or kij
<flag> is one of R => Random generation of matrices, I => Input matrices
<n> specifies the size - each matrix is to to be n x n
<A> is an n x n matrix in row major order (only present if flag=I)
<B> is an n x n matrix in row major order (only present if flag=I) 

example output: the matrix is only printed for I flag
running on 1 processors
elapsed time = t seconds
19 3
18 2

Comments: Initially tried separating parts into functions but kept getting
errors when trying to pass arrays as parameter. After a lot of trial and
error, decided to store matrixes in one dimensional arrays. coding went
more smoothly after that.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <time.h>




int main(void) {
  int n; // matrix size
  char flag;
  char form[4];
  int myrank, commsz;
  double start, finish, elapsed; // variables for recording time
  int i, j, k;
  long int *a; // storing the matrixes in a 1D array
  long int *b;
  long int *c;

  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &commsz);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

  if (myrank == 0) {
    scanf("%s", form);
    scanf(" %c", &flag);
    scanf("%d", &n);

    if (n%commsz != 0) { // check is matrix size is valid. end program if it isn't.
      printf("Matrix size is not divisible by the number of processors\n");
      MPI_Finalize();
      exit(-1);
    }

    //allocate memory now that we will be doing program
    a = (long int*)malloc(sizeof(long int)*n*n);
    b = (long int*)malloc(sizeof(long int)*n*n);
    c = (long int*)malloc(sizeof(long int)*n*n);

    srand(time(NULL));
    if (flag == 'I') {
      for(i=0; i<n*n; i++) scanf("%ld", &a[i]);
      for(i=0; i<n*n; i++) scanf("%ld", &b[i]);
    }

    else { //random input
      for(i=0; i<n*n; i++) a[i] = rand()%100;
      for(i=0; i<n*n; i++) b[i]= rand()%100;
    }	 
  }

  // start timing  
  MPI_Barrier(MPI_COMM_WORLD);
  if (myrank == 0) start = MPI_Wtime();

  // send form and n to other processes
  MPI_Bcast(&form, 4, MPI_CHAR, 0, MPI_COMM_WORLD);
  MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

  // use the n to allocate memory for B and C in non 0 processes
  if (myrank != 0) {
    b = (long int *)malloc(sizeof(long int)*n*n);
    c = (long int *)malloc(sizeof(long int)*n*n);
  }

  // broadcast the b array created at 0 process	
  MPI_Bcast(b, n*n, MPI_LONG, 0, MPI_COMM_WORLD);

  long int *locala = (long int *)malloc(sizeof(long int)*n*n/commsz);
  long int *localc = (long int *)malloc(sizeof(long int)*n*n/commsz);

  // send the parts of a into each processes locala
  MPI_Scatter(a, n*n/commsz, MPI_LONG, locala, n*n/commsz, MPI_LONG, 0, 
      MPI_COMM_WORLD);
// got 0 for all values in the ijk matrix when i tried to do it without sum variable
  int sum = 0;				 
  if (strcmp(form, "ijk") == 0) {
    for (i=0; i<n/commsz; i++) {
      for (j=0; j<n; j++) {
        sum=0;

        for (k=0; k<n; k++) {
          sum += locala[i*n+k]*b[k*n+j];
        }
        localc[i*n+j] = sum;
      }
    }         
  }

  else if (strcmp(form, "ikj") == 0) {
    for (i=0; i<n*n/commsz; i++) localc[i] = 0;
    for (i=0; i<n/commsz; i++)
      for (k=0; k<n; k++) 
        for (j=0; j<n; j++) localc[i*n+j] += locala[i*n+k]*b[k*n+j];
  }

  else if (strcmp(form, "kij") == 0) {
    for (i=0; i<n*n/commsz; i++) localc[i] = 0;
    for (k=0; k<n; k++) 
      for (i=0; i<n/commsz; i++) 
        for (j=0; j<n; j++) localc[i*n+j] += locala[i*n+k]*b[k*n+j];
  }

  MPI_Gather (localc, n*n/commsz, MPI_LONG, c, n*n/commsz, MPI_LONG, 0, 
      MPI_COMM_WORLD);

  if (myrank == 0) {
    finish =  MPI_Wtime();
    elapsed = finish-start;
    printf("Running on %d processors\n", commsz);
    printf("elapsed time = %f seconds\n", elapsed);
    if (flag == 'I') {
	 for(i=0; i<n; i++) {
      for(j=0; j<n; j++) printf("%ld ", c[i*n+j]);
      printf("\n");
    }
}
  }

  free(b);
  free(c);
  free(locala);
  free(localc);
  MPI_Finalize();
  return 0;

}





