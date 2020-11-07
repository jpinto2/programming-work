// John Pinto
// CSCI311:04
// P3
#include "AdjacencyMatrix.h"
#include "distance_between_hexes.h"
#include"HexMap.h"
#include"Graph.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<map>
#include<fstream>
#include <vector>
#include <limits> 
using namespace std;

bool which_is_closer(unsigned int a, unsigned int b)
{
 return est_tot_dist[a] > est_tot_dist[b];
}


vector<int> est_tot_dist;
map<unsigned int, unsigned int> hexToVertex;
map<unsigned int, unsigned int> vertexToHex;

map<unsigned int, unsigned int> astar(unsigned int start, unsigned int finish, AdjacencyMatrix& am)
{
  unsigned int num_vert = am.order();
  const unsigned int inf=std::numeric_limits<unsigned int>::max();
  set<unsigned int> closed; //holds vertices we no longer process
  vector<unsigned int> open; //holds vertices we still need to process XXX
  // XXX no longer needed: set<unsigned int> visited;

  map<unsigned int, unsigned int> parent;//what is returned

  //should be number of vertices
  //holds the distance already traveled for each vertex
  vector<int> distance_traveled(num_vert, inf);

  //recall, total_est_dist is a global variable
  //Here, initialize it to infinity for all entries. # entries
  //equals number of vertices
  est_tot_dist.resize(num_vert, inf); 
  //BTW, total_est_dist for a vertex i is: 
  //  distance_traveled[i]+distance_between_hexes(starthex, i)


  //get ready to loop
  distance_traveled[start]=0; //XXX
  est_tot_dist[start]=distance_traveled[start] + distance_between_hexes(vertexToHex[start], vertexToHex[start]); //XXX
  open.push_back(start);
  make_heap(open.begin(), open.end(), which_is_closer); //add our starting point to 
//XXX no longer needed  visited.insert(start); //add to our helper set

  //start the loop
  while(!open.empty())
  {
    unsigned int current;
    pop_heap(open.begin(), open.end());
    current=open.back();
    open.pop_back();
    //XXX
    //use pop_heap on open vector. then current=open.back(), then pop_back to remove it
    
    if(current==finish)//stopping condition
      return parent;
    //now don't forget to pop it off of open
    closed.insert(current); 
       //make sure that we don't see this vertex again.
    set<unsigned int> n = neighbors(current);
    for(auto nbor = n.begin(); iter != n.end(); ++nbor) {
        
        if(closed.find(*nbor) != closed.end()) //don't do it again. We've done it before
          continue;
      //set a tentative distance traveled for the nbor
      int d_nbor = distance_traveled[current] + myAdjacencyMatrix.weight(current, *nbor);
      if(closed.find(*nbor) == closed.end())  
      {
       closed.insert(*nbor);
       open.push_back(*nbor);
       make_heap(open.begin(), open.end(), which_is_closer);
      }
      vector<unsigned int>::iterator it;
      it = find(open.begin(), open.end(), *nbor);
      if (it == open.end()) {
             open.push_back(*nbor);
             make_heap(open.begin(), open.end(), which_is_closer);
      }
      else if(d_nbor >= distance_traveled[*nbor])
      {
        continue; //Nope, visit next neighbor
      }
      parent[*nbor]=current; //best predecessor for this neighbor
      distance_traveled[*nbor]= d_nbor;
      est_tot_dist[*nbor]=distance_traveled[*nbor]+ distance_between_hexes(vertexToHex[*nbor], vertexToHex[finish]);
        //note that nbor and finish are vertices, 
        //but, distance_between_hexes takes two hex numbers.
        //Be sure to use vertexToHex for nbor and finish
     make_heap(open.begin(), open.end(), which_is_closer);
     }
   }
   return parent;

  }                                 
}

int main()
{
    
    map<char, int> cost;
    char t;
    int c = 0;
    ifstream file1("terrain_costs.data");
    AdjacencyMatrix matrix;
    while(file1 >> t >> c)
    {
               cost[t]=c;
    }
    file1.close();
    int hex1 = 0, 
    int hex2 = 0;
    string weight;
    int w;
    ifstream file2("mapedges.data");
    while(file >> hex1 >> hex2 >> weight)
    {
        if(hexToVertex.count(hex1)==0)
        {
            unsigned int v1=matrix.add_vertex();
            hexToVertex[hex1]=v1;
            vertexToHex[v1]=hex1;
        }
        if(hexToVertex.count(hex2)==0)
        {
            unsigned int v2=matrix.add_vertex();
            hexToVertex[hex2]=v2;
            vertexToHex[v2]=hex2;
        }
        
        w=0; // resets w to 0;
        for (string::iterator it=weight.begin(); it!=weight.end(); ++it)
        {
            w+= cost[*it]; //adds the cost of the current terrain character to w
        }
        // w is now at total weight for the edge
        matrix.add_edge(hexToVertex[hex1], hexToVertex[hex2], w);
    }
    
    file2.close();
    
    Graph *g = new AdjacencyList(hexToVertex.size());
    for(int i =0; i < matrix.order(); i++)
    {
        set<unsigned int> neighbor = matrix.neighbors(i);
        for(auto iter = neighbor.begin(); iter != neighbor.end(); ++iter)
        {
            g->add_edge(i, *iter);
        }
    }
    
    unsigned int start = hexToVertex[1605];
    unsigned int end = hexToVertex[309];
    map<unsigned int, unsigned int> ast;
    HexMap hex(309);
    ast = astar(start, end, matrix);
    
    while(ast.count(endVertex)==1)
    {
        int h = vertexToHex[endVertex];
        hexMap.add(h); 
        endVertex=ast[endVertex]; 
    }
    
    return 0;
}
