//aqui estuvo: 
#ifdef _MSC_VER ///this is so VS lets you use printf instead of s_printf, and so on
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tigr.h"
#include "OperationManager.h"
#include "Vertex.h"
#include "Dijkstra.h"
#include "Mouse.h"
#define BACKSPACE 8
#define BG_COLOR tigrRGB(200, 200, 220)
#define SELECTED_VERTEX_COLOR tigrRGB(200, 100, 100)
#define VERTEX_COLOR tigrRGB(30, 30, 30)
#define	EDGE_COLOR tigrRGB(100, 100, 200)
#define INDEX_COLOR tigrRGB(255, 255, 255)
#define WEIGHT_COLOR tigrRGB(255, 165, 0)
#define DIJKSTRA_RESULT_COLOR tigrRGB(30, 200, 200)
#define DEFAULT_WEIGHT 1
#define VERTEX_RADIUS 8
#define EDGE_WIDTH 4
#define DIJKSTRA_RESULT_MAX_LEN 1000
#define DIJKSTRA_LINE_MAX_LEN 50

////Draw weighted edges between vertices
void DrawEdges(Tigr* screen, int vertexCount, const Vertex vertexList[]);

///Draw indexed vertices
void DrawVertices(Tigr* screen, int selectedVertex, int vertexCount, const Vertex vertexList[]);


int main(int argc, char* argv[])
{
    Tigr* screen = tigrWindow(320, 240, "Graph Maker", 0); //create a bitmap window

    //tigrClear(screen, screenColor);
    int mouseX, mouseY, mousePressed;
    int selectedVertex = NO_VERTEX;
    char dijkstraResult[DIJKSTRA_RESULT_MAX_LEN] = "Select a Vertex\nand press D to\nperform dijkstra";
    
    while (!tigrClosed(screen))
    {
            const int vertexCount = GetVertexCount();
            const Vertex * vertexList = GetVertexList();
            tigrMouse(screen, &mouseX, &mouseY, &mousePressed); //get mouse input
            int operation = GetOperation(screen, mouseX, mouseY, selectedVertex);

            if (operation == SELECT_VERTEX) {
                selectedVertex = GetVertexAtPosition(mouseX, mouseY);
            }
            else if (operation == DESELECT_VERTEX) {
                selectedVertex = NO_VERTEX;
            }
            else if (operation == ADD_VERTEX) {
                AddVertex(mouseX, mouseY);
            }
            else if (operation == SELECT_EDGE)
            {
                int edge[2] = { GetEdgeAtPosition(mouseX, mouseY)[0], GetEdgeAtPosition(mouseX, mouseY)[1] };

                int weight = 0;
                int key;
                SetWeight(edge, 0);
                //allow user to change an edge's weight
                while ((key = tigrReadChar(screen)) != '\n' && !tigrClosed(screen) && !MouseClick(screen)) {

                    if (key >= '0' && key <= '9') {
                        int newWeight = weight * 10 + (key - '0');
                        if (newWeight > weight) { //check for overflow
                            weight = newWeight;
                        }
                    }
                    else if (key == BACKSPACE) {
                        weight /= 10;
                    }

                    tigrClear(screen, BG_COLOR);
                    tigrPrint(screen, tfont, 0, 0, tigrRGB(240, 100, 200), "--Enter New Weight--\n");
                    SetWeight(edge, weight);
                    DrawEdges(screen, vertexCount, vertexList);
                    DrawVertices(screen, selectedVertex, vertexCount, vertexList);
                    tigrUpdate(screen);
                }

            }
            else if (operation == ADD_EDGE) {
                AddEdge(selectedVertex, GetVertexAtPosition(mouseX,mouseY), DEFAULT_WEIGHT);
            }
            else if (operation == RUN_DIJKSTRA) {
                int * shortestDistances = calloc(vertexCount,sizeof(int));
                if (shortestDistances == NULL) {
                    perror("Allocation failure :( sorry");
                }
                else {
                    Dijkstra(shortestDistances, selectedVertex, vertexList, vertexCount);

                    sprintf(dijkstraResult, "Vert | Dis\n");
                    //store result in tabulated form
                    for (int ver = 0; ver < vertexCount; ver++) {
                        char newLine[DIJKSTRA_LINE_MAX_LEN];
                        sprintf(newLine, "  v%d | %d\n", ver, (shortestDistances[ver] == INFINITE_DISTANCE || shortestDistances[ver] < 0 ? -1 : shortestDistances[ver]));
                        strcat(dijkstraResult, newLine);
                    }
                    free(shortestDistances);
                }
            }

       tigrClear(screen, BG_COLOR);
       DrawEdges(screen, vertexCount, vertexList);
       DrawVertices(screen, selectedVertex, vertexCount, vertexList);
       tigrPrint(screen, tfont, 0, 0, DIJKSTRA_RESULT_COLOR, dijkstraResult);

       tigrUpdate(screen);

    }
    
    tigrFree(screen);
    VertexFree();
    return 0;
}

void DrawVertices(Tigr* screen, int selectedVertex, int vertexCount, const Vertex vertexList[]) {
    int offset = -3;
    for (int i = 0; i < vertexCount; i++) {
        tigrFillCircle(screen, vertexList[i].xPosition, vertexList[i].yPosition, VERTEX_RADIUS, i == selectedVertex ? SELECTED_VERTEX_COLOR : VERTEX_COLOR);
        tigrPrint(screen, tfont, vertexList[i].xPosition +offset, vertexList[i].yPosition + offset, INDEX_COLOR, "%d", i);
    }

}

void DrawEdges(Tigr* screen, int vertexCount, const Vertex vertexList[]) {

    for (int ver = 0; ver < vertexCount; ver++)
    {
        for (int con = 0; con < vertexList[ver].connectionCount; con++) {

            if (vertexList[ver].connectedVertices[con].index > ver) { //only draw edges once

                //distance between vertices
                int xDistance = abs(vertexList[ver].xPosition - vertexList[ver].connectedVertices[con].xPosition);
                int yDistance = abs(vertexList[ver].yPosition - vertexList[ver].connectedVertices[con].yPosition);

                //middle point between vertices
                int midX = (vertexList[ver].xPosition + vertexList[ver].connectedVertices[con].xPosition) / 2;
                int midY = (vertexList[ver].yPosition + vertexList[ver].connectedVertices[con].yPosition) / 2;

                //draw diagonal rectangle between vertices using a bunch of lines.
                //if edge is more horizontal than vertical, draw EDGE_WIDTH lines taking steps along the y-axis, and vice-versa.
                int xStep = 0;//
                int yStep = 0;
                int* lines = xDistance > yDistance ? &xStep : &yStep;

                while (*lines < EDGE_WIDTH)
                {
                    tigrLine(screen, vertexList[ver].xPosition + yStep, vertexList[ver].yPosition + xStep,
                        vertexList[ver].connectedVertices[con].xPosition + yStep, vertexList[ver].connectedVertices[con].yPosition + xStep, EDGE_COLOR);
                    (*lines)++;
                }

                tigrPrint(screen, tfont, midX, midY, WEIGHT_COLOR, "%d", vertexList[ver].weights[con]);
            }

        }

    }

}