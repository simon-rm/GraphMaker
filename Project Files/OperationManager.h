#ifndef OPERATION_MANAGER_H
#define OPERATION_MANAGER_H
#define NO_VERTEX -1

//operations the user can perform
enum Operation { NONE, ADD_VERTEX, SELECT_VERTEX, DESELECT_VERTEX, SELECT_EDGE, ADD_EDGE, RUN_DIJKSTRA };

//Returns the operation requested by the user, or NONE (0) if no operation was requested.
int GetOperation(Tigr* screen, int mouseX, int mouseY, int selectedVertex);


#endif