#ifndef VERTEX_H
#define VERTEX_H
#include <stdio.h>
#define VERTEX_RADIUS 8
#define MAX_VERTICES 1000
#define RETURN_IF_MALLOC_FAILED(arr) if(arr == NULL) {perror("Allocation failed. This is bad"); return;}

//indexed vertices which connect to other vertices through weighted edges.
typedef struct Vertex{

	int xPosition, yPosition;
	int index;
	int connectionCount; 
	struct Vertex* connectedVertices; //list of vertices connected to vertex
	int* weights; //list of edge weights. weight[i] corresponds to connectedVertices[i].

} Vertex;

//connect two vertices. Assign a weight to said connection.
void AddEdge(int vertexIndex1, int vertexIndex2, int weight);
//assign a weight to an existing edge.
void SetWeight(int vertices[2], int weight);
//Add a vertex to the vertex list
void AddVertex(int xPos, int yPos);
//free all vertex-related memory. Don't forget to use it! 
void VertexFree();
//returns 1 if vertices share a connection, 0 otherwise.
int Connected(int vertexIndex1, int vertexIndex2);
//gets vertex at specified position
int GetVertexAtPosition(int xPos, int yPos);
//get edge at specified position
int* GetEdgeAtPosition(int xPos, int yPos);
//get list of vertices. to be used sparingly
Vertex* GetVertexList();
//get number of vertices. to be used sparingly
int GetVertexCount();

#endif