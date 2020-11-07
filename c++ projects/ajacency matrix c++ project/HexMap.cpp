#include "HexMap.h"
#include<iostream>
#include<utility>
using std::cout;
using std::endl;
typedef std::pair<unsigned int, unsigned int> Coord;
Coord hex_to_pair(unsigned int hexID)
{
  unsigned int x=hexID/100;
  unsigned int y=hexID%100;
  return(Coord(40+(x-2)*49, 40+(y-1)*56-(x%2)*56/2));
}

HexMap::HexMap(unsigned int startingHexID)
{
  path.push(startingHexID);
}

void HexMap::add(unsigned int hexID)
{
  path.push(hexID);
}

HexMap::~HexMap()
{
  cout.precision(3);
  cout << std::fixed;

  cout << "<!DOCTYPE html>" << endl;
  cout << "<html>" << endl;
  cout << "<title>Hex Map Pathfinding</title>" << endl;
  cout << "<style>" << endl;
  cout << "body { " << endl;
  cout << "background-image: url(hex_map.jpg); " << endl;
  cout << "background-repeat: no-repeat; " << endl;
  cout << "}" << endl;
  cout << "</style>" << endl;
  cout << "<body>" << endl;

  cout << "<svg width=\"775\" height=\"573\">" << endl;

  cout << "<polyline points=\"";
  while(!path.empty())
  {
    Coord point=hex_to_pair(path.front());
    path.pop();
    cout << point.first << "," << point.second << " ";
  }
  cout << '\"' << endl;
  cout << "style=\"fill:none;stroke:blue;stroke-width:6\" />" << endl;
  cout << "</svg>" << endl;
  cout << "</body>" << endl;
  cout << "</html>" << endl;
}
