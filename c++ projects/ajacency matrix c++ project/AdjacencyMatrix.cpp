// John Pinto
// CSCI311.04
// Lab 9
// AdjacencyMatrix.cpp
#include "AdjacencyMatrix.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

AdjacencyMatrix::AdjacencyMatrix()
{
}

AdjacencyMatrix::AdjacencyMatrix(unsigned int vertices) : matrix(vertices)
{
  unsigned int i;
  for (i=0; i<matrix.size(); ++i) matrix[i].resize(vertices, 0); 
}

int AdjacencyMatrix::weight(unsigned int src, unsigned int dst)
{
    return matrix[src][dst];
}

void AdjacencyMatrix::add_edge(unsigned int v1, unsigned int v2, int weight)
{
  if (v1<matrix.size() && v2<matrix.size() && v1 != v2) { //checks that both vertexes exist and don't have same value
    if (matrix[v1][v2] == 0) {
      matrix[v1][v2] = weight;
      matrix[v2][v1] = weight;
    }
  }
}

void AdjacencyMatrix::display()
{
  Graph::display();
  unsigned int i, j;
  for (i=0; i<matrix.size(); ++i) 
    for (j=i+1; j<matrix[i].size(); ++j)
      if (matrix[i][j] != 0) cout << "(" << i << ", " << j << ")" << endl; // if edge is found, it is displayed
}

void AdjacencyMatrix::remove_edge(unsigned int v1, unsigned int v2)
{
  if (v1<matrix.size() && v2<matrix.size() && v1 != v2) {
    if (matrix[v1][v2] != 0) {
      matrix[v1][v2] = 0;
      matrix[v2][v1] = 0;
    }
  }

}     

unsigned int AdjacencyMatrix::add_vertex()
{
  matrix.resize(matrix.size() + 1);
  unsigned int i;
  for (i=0; i<matrix.size(); ++i) matrix[i].resize(matrix.size(), 0);
  return matrix.size();
}

unsigned int AdjacencyMatrix::degree(unsigned int i) {
  unsigned int total, j;
  total=0;
  for(j=0; j<matrix[i].size(); j++) if(matrix[i][j] != 0) total++;

  return total;
}

unsigned int AdjacencyMatrix::size() {
  unsigned int total = 0;
  unsigned int i, j;
  for (i=0; i<matrix.size(); ++i) 
    for (j=i+1; j<matrix[i].size(); ++j)
      if (matrix[i][j] != 0) total++;

  return total;
}

unsigned int AdjacencyMatrix::order() {
  return matrix.size();
}


void AdjacencyMatrix::remove_vertex(unsigned int v1)
{
  if (v1<matrix.size()) {
    unsigned int i;
    if (v1 == matrix.size() - 1) { //this situation is for when the vertex is the last vertex. then we don't need to swap any vectors
      matrix[v1].clear();
      matrix.resize(matrix.size() - 1);
      for (i=0; i<matrix.size(); ++i) matrix[i].erase(matrix[i].begin() + v1);
    }

    else { //else the vertex being removed isn't the last one
      unsigned int last = matrix.size()-1;
      for (i=0; i<matrix.size(); ++i) matrix[i].erase(matrix[i].begin() + last);

      matrix[last][v1] = 0; //update new v1 position for last vector to be 0 to avoid self loop
      for (i=0; i<last; ++i) matrix[i][v1] = matrix[last][i]; //update v1 column for new values
      matrix[v1].swap(matrix[last]); //swap v1 vector with vector for last vertex
      matrix[last].clear(); //clear the old contents of v1
      matrix.resize(matrix.size() - 1); // resize matrix

    }
  }

}

set<unsigned int> AdjacencyMatrix::neighbors(unsigned int p) {
      set<unsigned int> myset;
      unsigned int i;
      for(i=0; i<matrix[p].size(); ++i) if(matrix[p][i] != 0) myset.insert(i);
      return myset;
} 

