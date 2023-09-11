#include "Mouse.h"
#include <string.h>
#include "OperationManager.h"
#include "Vertex.h"

int GetOperation(Tigr* screen, int mouseX, int mouseY, int selectedVertex) {
    
    if (MouseClick(screen)) {
        int newlySelectedVertex = GetVertexAtPosition(mouseX, mouseY);

        if (GetEdgeAtPosition(mouseX,mouseY) != NULL) {
            return SELECT_EDGE;
        }

        else if (newlySelectedVertex >= 0 && selectedVertex == NO_VERTEX) {

            return SELECT_VERTEX;
        }

        else if (newlySelectedVertex >= 0 && selectedVertex >= 0 && !Connected(selectedVertex, newlySelectedVertex)) {
            return ADD_EDGE;
        }

        else if (newlySelectedVertex == NO_VERTEX && selectedVertex == NO_VERTEX) {
            return ADD_VERTEX;
        }
        else if (newlySelectedVertex == NO_VERTEX && selectedVertex >= 0) {
            return DESELECT_VERTEX;
        }
    }
    else if (tigrKeyDown(screen, 'D') && selectedVertex >= 0) {
        return RUN_DIJKSTRA;
    }
    return NONE;
}
