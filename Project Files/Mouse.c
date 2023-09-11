#include "Mouse.h"
#include "tigr.h"
#include "stdio.h"
int MouseClick(Tigr* screen) {
    int xPos, yPos, newPress;
    static int mousePressed = 0;
    int mouseClicked = 0; // = tigrTouch(screen, &point, 1);// get mouse input

    tigrMouse(screen, &xPos, &yPos, &newPress);
    if (newPress && !mousePressed) { //when the user clicks...
        mousePressed = 1;
        mouseClicked = 1;
    }
    else if (mousePressed &&!newPress) { //when the user unclicks...
        mousePressed = 0;
    }

    return mouseClicked;
}