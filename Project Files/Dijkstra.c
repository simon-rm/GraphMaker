#include "Dijkstra.h"
#include <stdlib.h>
#include <stdio.h>

void FindShorterPaths(Vertex newlyVisited, int shortestDistances[]){

	for (int i = 0; i < newlyVisited.connectionCount; i++) { 
		int distanceTraveled = shortestDistances[newlyVisited.index];
		int connectedVertex = newlyVisited.connectedVertices[i].index; 
		int distanceToConnectedVertex = newlyVisited.weights[i];

		if (distanceTraveled + distanceToConnectedVertex < shortestDistances[connectedVertex]) {
			shortestDistances[connectedVertex] = distanceTraveled + distanceToConnectedVertex; 
		}

	}

}

int VisitClosest(int shortestDistances[], int* visited, int vertexCount) {

	int minIndex = 0, min = INFINITE_DISTANCE;

	for (int i = 0; i < vertexCount; i++) {
		if ((min >= shortestDistances[i]) && !visited[i]) { 
			min = shortestDistances[i]; 
			minIndex = i;
		}

	}
	visited[minIndex] = 1;
	return minIndex;
}

void Dijkstra(int shortestDistances[], int sourceIndex, const Vertex vertexList[], int vertexCount) {

	Vertex source = vertexList[sourceIndex]; 

	int* visited = calloc(vertexCount, sizeof(int)); //vertices whose shortest path is found are marked as "visited"

    RETURN_IF_MALLOC_FAILED(visited);

	for (int i = 0; i < vertexCount; i++) shortestDistances[i] = INFINITE_DISTANCE; //a distance is set to infinite until a path to it is found
	shortestDistances[source.index] = 0; 

	for (int i = 0; i < vertexCount; i++) {

		int newlyVisited = VisitClosest(shortestDistances, visited, vertexCount); // 1: visit the closest vertex
		FindShorterPaths(vertexList[newlyVisited], shortestDistances);			  // 2: find new --shorter-- paths through it
	}																			  // 3: repeat

	free(visited); 

}

