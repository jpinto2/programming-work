// John Pinto
// CSCI311.04
// Lab 9
// AdjacencyMatrix.h
#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class AdjacencyMatrix : public Graph {
  public:
    AdjacencyMatrix();
    AdjacencyMatrix(unsigned int vertices);
    int weight(unsigned int src, unsigned int dst);
    void add_edge(unsigned int v1, unsigned int v2, int weight);
    void display();
    void remove_edge(unsigned int v1, unsigned int v2);
    unsigned int add_vertex();
    void remove_vertex(unsigned int v1);
    unsigned int degree(unsigned int i);
    unsigned int size();
    unsigned int order();
    set<unsigned int> neighbors(unsigned int p);
  private:
    vector < vector <unsigned int> > matrix;
};
#endif
