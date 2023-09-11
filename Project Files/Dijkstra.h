#ifndef DIJKSTRA
#define DIJKSTRA
#include <limits.h>
#include "Vertex.h"
#define INFINITE_DISTANCE INT_MAX
//perform dijkstra's algorithm on a given vertex and put the result in "shortestDistances[]".
void Dijkstra(int shortestDistances[], int sourceIndex, const Vertex vertexList[], int vertexCount);

//Update Distances for which a shorter path was found through the newly visited vertex.
void FindShorterPaths(Vertex newlyVisited, int shortestDistances[]);

//gets closest vertex to source and marks it as visited.
int VisitClosest(int shortestDistances[], int visited[], int vertexCount);

#endif