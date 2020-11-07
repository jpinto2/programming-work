
//returns map to previous, 'best/shortest' vertex
std::map<unsigned int, unsigned int> astar(
    unsigned int start, 
    unsigned int finish, 
    AdjacencyMatrix& am)
{
  set<unsigned int> closed; //holds vertices we no longer process
  priority_queue<...> open; //holds vertices we still need to process
  set<unsigned int> visited; //another helper set for vertices we've seen

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

  //get ready to loop
  est_tot_dist[start]=0;
  open.push(start); //add our starting point to the priority queue
  visited.insert(start); //add to our helper set

  //start the loop
  while(!open.empty())
  {
    current=open.top()
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
      if(visited.count(nbor)==0)  
      {
        //add nbor to visited
        //add nbor to the priority queue "open"
      }
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
     //end for loop
   //end while loop
   return parent;

  }
