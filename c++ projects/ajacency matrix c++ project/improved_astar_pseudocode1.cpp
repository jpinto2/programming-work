
//returns map to previous, 'best/shortest' vertex
std::map<unsigned int, unsigned int> astar(unsigned int start, unsigned int finish, AdjacencyMatrix& am)
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
