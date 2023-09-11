#include "Vertex.h"
#include <stdlib.h>
#include <stdio.h>
//list of vertices
static Vertex vertexList[MAX_VERTICES];
//number of vertices
static int vertexCount = 0;

Vertex* GetVertexList() { return vertexList; }
int GetVertexCount() { return vertexCount; }

void AddVertex(int xPos, int yPos) { //adds a vertex to the list

    Vertex newVertex = { xPos, yPos, vertexCount, 0, NULL, NULL};
    vertexList[vertexCount++] = newVertex;
}

void AddEdge(int vertexIndex1, int vertexIndex2, int weight) {
    //warning! vertices connect to COPIES of other vertices.
    // Do not try to access Vertex fields that might change.
    //note: turning * connectedVertices into a ptr to ptr could resolve this issue.
    int edge[2] = {vertexIndex1, vertexIndex2};

    for (int i = 0; i <= 1; i++){
        Vertex * vertex = &vertexList[edge[i]];
        Vertex connectedVertex = vertexList[edge[1-i]];

        if(vertex->connectedVertices ==NULL){
            vertex->connectedVertices = malloc(1*sizeof(Vertex));
            vertex->weights = malloc(1*sizeof(int));
            RETURN_IF_MALLOC_FAILED(vertex->connectedVertices);
            RETURN_IF_MALLOC_FAILED(vertex->weights);
        }
        else{
            Vertex * newConnectedVertices = realloc(vertex->connectedVertices, (vertex->connectionCount+1) * sizeof(Vertex));
            int * newWeights = realloc(vertex->weights, (vertex->connectionCount+ 1) * sizeof(int));
            RETURN_IF_MALLOC_FAILED(newWeights);
            RETURN_IF_MALLOC_FAILED(newConnectedVertices);
            vertex->connectedVertices = newConnectedVertices;
            vertex->weights = newWeights;
        }
        vertex->connectedVertices[vertex->connectionCount] = connectedVertex;
        vertex->weights[vertex->connectionCount] = weight;
        vertex->connectionCount++;
    }

}

void SetWeight(int edge[2], int weight) {

	//loops twice, once for each vertex
	for (int ver = 0; ver <= 1; ver++) { 
		int vertex1 = edge[ver];
		int vertex2 = edge[1 - ver];

		for (int con = 0; con < vertexList[vertex1].connectionCount; con++) {
			if (vertexList[vertex1].connectedVertices[con].index == vertex2) {
				vertexList[vertex1].weights[con] = weight;
			}
		}
	}
}

void VertexFree() {
	for (int ver = 0; ver < vertexCount; ver++) {
		free(vertexList[ver].connectedVertices);
		free(vertexList[ver].weights);
	}
}

int Connected(int vertexIndex1, int vertexIndex2) {

	for (int con = 0; con < vertexList[vertexIndex1].connectionCount; con++) {
		if (vertexList[vertexIndex1].connectedVertices[con].index == vertexIndex2) {
			return 1;
		}
	}
	return 0;
}

int GetVertexAtPosition(int xPos, int yPos) {

	for (int ver = 0; ver < vertexCount; ver++) {
		int xDistance = xPos - vertexList[ver].xPosition;
		int yDistance = yPos - vertexList[ver].yPosition;
		int selectionRadius = VERTEX_RADIUS*2;

		if (xDistance*xDistance + yDistance*yDistance < selectionRadius*selectionRadius) //x^2 + y^2 < r^2
		{
			return ver;
		}
	}
	return -1;
}
int* GetEdgeAtPosition(int xPos, int yPos) {
	for (int ver = 0; ver < vertexCount; ver++) {
		for (int con = 0; con < vertexList[ver].connectionCount; con++) {
			if (vertexList[ver].connectedVertices[con].index > ver) {
				int edgeX = (vertexList[ver].xPosition + vertexList[ver].connectedVertices[con].xPosition) / 2;
				int edgeY = (vertexList[ver].yPosition + vertexList[ver].connectedVertices[con].yPosition) / 2;
				int xDistance = xPos - edgeX;
				int yDistance = yPos - edgeY;
				int selectionRadius = VERTEX_RADIUS*2; 

				if (xDistance * xDistance + yDistance * yDistance < selectionRadius * selectionRadius) 
				{
                    static int edge[2];
                    edge[0] = ver;
                    edge[1] = vertexList[ver].connectedVertices[con].index;
					return edge;
				}
			}
		}
	}
	return NULL;
}