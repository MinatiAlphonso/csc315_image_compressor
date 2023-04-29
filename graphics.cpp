/**
 * @file graphics.cpp
 */

/*
                ***** graphics.cpp *****

OpenGL/GLUT graphics module for image display.

Author: John M. Weiss, Ph.D.
Class:  CSC 315 Data Structures & Algorithms
Date:   Spring 2018
*/

#include "graphics.h"
#include <cstdio>
#include <GL/glut.h>

// symbolic constants
const int ESC = 27;

/******************************************************************************/

// display 24-bit color image
void displayColor( int x, int y, int w, int h, byte** image )
{
    glRasterPos2i( x, y );
    glDrawPixels( w, h, GL_RGB, GL_UNSIGNED_BYTE, *image );
}

// display 8-bit monochrome image
void displayMonochrome( int x, int y, int w, int h, byte** image )
{
    glRasterPos2i( x, y );
    glDrawPixels( w, h, GL_LUMINANCE, GL_UNSIGNED_BYTE, *image );
}

// write a text string
void DrawTextString( char *string, int x, int y, byte r, byte g, byte b )
{
    glColor3ub( r, g, b );
    glRasterPos2i( x, y );
    while ( *string )
    {
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, *string );
        string++;
    }
}

/**
 * @authors Dustin Richards, Minati Alphonso
 * @brief draws a pre-calculated vertical seam
 *
 * @param[in] path - the path to draw. the index is the row and the value at that index is the column
 */
void drawVSeam(vector<int> path)
{
   glBegin(GL_POINTS);
      glPointSize(3);
      glColor3f(1, 0, 0);
      for (int y = 0; y < (int)path.size(); y++)
         glVertex2i(path[path.size() - 1 - y], y);
   glEnd();
}

/**
 * @authors Minati Alphonso, Dustin Richards
 * @brief draws a pre-calculated horizontal seam
 *
 * @param[in] path - the path to draw. the index is the column and the value at that index is the row
 */
void drawHSeam(vector<int> path)
{
   glBegin(GL_POINTS);
      glPointSize(3);
      glColor3f(1, 0, 0);
      for (int x = 0; x < (int)path.size(); x++)
         glVertex2i(x, path[path.size() - 1 - x]);
   glEnd();
}
