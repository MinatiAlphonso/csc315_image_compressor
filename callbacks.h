/***************************************************************************//**
 * @file
 ******************************************************************************/
#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <GL/freeglut.h>
#include "util.h"
#include "display.h"
#include "mouse.h"
#include "keyboard.h"
#include "reshape.h"

/// Callback for the display event
void display();
/// Callback for the keyboard event
void keyboard(unsigned char key, int x, int y);
/// Callback for the mouseClick event
void mouseClick(int button, int state, int x, int y);
/// Callback for the mouseDrag event
void reshape(const int x, const int y);

#endif
