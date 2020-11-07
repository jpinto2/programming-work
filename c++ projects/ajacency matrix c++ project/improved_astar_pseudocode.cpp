
//returns map to previous, 'best/shortest' vertex
std::map<unsigned int, unsigned int> astar(unsigned int start, unsigned int finish, AdjacencyMatrix& am)
{
                  
  unsigned int num_vert = am.order();
  set<unsigned int> closed; //holds vertices we no longer process
  vector<unsigned int> open; //holds vertices we still need to process XXX
  // XXX no longer needed: set<unsigned int> visited;

  std::map<unsigned int, unsigned int> parent;//what is returned

  //should be number of vertices
  //holds the distance already traveled for each vertex
  std::vector<int> distance_traveled(...)

  //recall, total_est_dist is a global variable
  //Here, initialize it to infinity for all entries. # entries
  //equals number of vertices
  total_est_dist...
  //BTW, total_est_dist for a vertex i is: 
  //  distance_traveled[i]+distance_between_hexes(starthex, i)

  //also, initialize to infinity: XXX
  distance_traveled...

  //get ready to loop
  distance_traveled[start]=0; //XXX
  est_tot_dist[start]=distance_traveled + distance_between_hexes; //XXX
  open.push_back(start); //add our starting point to 
//XXX no longer needed  visited.insert(start); //add to our helper set

  //start the loop
  while(!open.empty())
  {
    //XXX
    //use pop_heap on open vector. then current=open.back(), then pop_back to remove it
    
    if(current==finish)//stopping condition
      return parent;
    //now don't forget to pop it off of open
    closed.insert(current); 
       //make sure that we don't see this vertex again.
    for(loop on nbor: neighbors of current):
        if(nbor is in closed) //don't do it again. We've done it before
          continue;
      set a tentative distance traveled for the nbor
        =distance_traveled[current] +
         myAdjacencyMatrix.weight(current, nbor);
//XXX      if(visited.count(nbor)==0)  
//XXX      {
//XXX        //add nbor to visited
//XXX        //add nbor to the priority queue "open"
//XXX      }
      if nbor isn't in open vector
             //add nbor to open vector
             //(re)make the heap
      else if(tentative_dist_traveled >= distance_traveled[nbor])
      {
        continue; //Nope, visit next neighbor
      }
      parent[nbor]=current; //best predecessor for this neighbor
      distance_traveled[nbor]= tentative distance traveled
        est_tot_dist[nbor]=distance_traveled[nbor]+
                           distance_between_hexes(nbor, finish)
        //note that nbor and finish are vertices, 
        //but, distance_between_hexes takes two hex numbers.
        //Be sure to use vertexToHex for nbor and finish
//XXX  here, (re)make_heap
     //end for loop
   //end while loop
   return parent;

  }
