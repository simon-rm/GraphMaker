#include "Mouse.h"
#include "tigr.h"
#include "stdio.h"
int MouseClick(Tigr* screen) {
    int xPos, yPos, newPress;
    static int mousePressed = 0;
    int mouseClicked = 0; 

    tigrMouse(screen, &xPos, &yPos, &newPress); //get mouse input
    if (newPress && !mousePressed) { //when the user clicks...
        mousePressed = 1;
        mouseClicked = 1;
    }
    else if (mousePressed &&!newPress) { //when the user unclicks...
        mousePressed = 0;
    }

    return mouseClicked;
}