/***************************************************************************//**
 * @file util.h
 ******************************************************************************/
#ifndef UTIL_H
#define UTIL_H

typedef unsigned char byte;

#include <GL/freeglut.h>
#include "callbacks.h"
#include "event.h"
#include "lodepng.h"

void utilityCentral(Event *);
void initOpenGL(char *);
#endif
