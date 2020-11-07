#include"Graph.h"
#include<iostream>
#include <map>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

void Graph::display()
{
  cout << "Graph with " << order() << " nodes and " << size() << " edges." << endl;
}

Graph::~Graph()
{
}

map<unsigned int, unsigned int> Graph::breadth_first_search(unsigned int p) {
             
map<unsigned int, unsigned int> mymap;
queue<unsigned int> myqueue;
const unsigned int inf=std::numeric_limits<unsigned int>::max();
vector<unsigned int> distance(this->order(), inf);

int i =0;
unsigned int cur = p;         
myqueue.push(p);
distance[cur] = 0;  

while(!myqueue.empty()) {

    cur = myqueue.front();
    myqueue.pop();      
      
    set<unsigned int> nbor = neighbors(cur);
    for(auto iter = nbor.begin(); iter != nbor.end(); iter++) {
             i++;
        if(distance[*iter] == inf) {
             distance[*iter] = distance[cur] + 1;
             myqueue.push(*iter);
             mymap[*iter] = cur;
             }
             
        }
             
}
        
        return mymap;
}
