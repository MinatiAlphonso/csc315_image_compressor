/**
 * @file canvas.h
 * Holds the Canvas struct and some supporting types
 */

#ifndef CANVAS_H
#define CANVAS_H
#include "imageio.h"
#include "graphics.h"
#include "alloc2d.h"
#include "energy.h"
#include <algorithm>
#include <stack>
#include <cstring>
#include <limits>
#include <vector>
#include "graphics.h"

using namespace std;

///a typedef of unsigned char because that's too long to type out
typedef unsigned char byte;

///used interally to specify which type of image to display
enum ImageType {ORIGINAL, ENERGY};
///used interally to specify which type of seam to calculate and display
enum SeamType {VERTICAL, HORIZONTAL};

/**
 * @authors Minati Alphonso, Dustin Richards
 * @brief holds all the information about the image we're working on as well as
 * most of the functions that act on it to calculate and remove seams
 */
struct Canvas
{
   unsigned width; ///<the current width of the image, used for calculating seams
   unsigned height; ///<the current height of the image, used for calculating seams and drawing
   unsigned originalWidth; ///<the original width of the image, only used for drawing
   byte **imageRGB; ///<an array that holds the color version of the image
   int **imageEnergy; ///<an array that holds the energy version of the image
   byte **imageMono; ///<an array the holds the scaled energy version of the image (to draw on the screen)
   int **totalEnergy; ///<an array used in finding a seam
   ImageType imageType; ///<stores whether the image to draw is the original or the scaled energy
   SeamType seamType; ///<stores the current seam type to use
   vector<int> path; ///<stores the current least energy path
   
   void display(); 
   Canvas();
   ~Canvas();

public:
   void findHorizontalSeam();
   void findVerticalSeam();
   void removeSeam();
   void mergeHPixels(int index, int row, byte** imageRGB);
   void mergeVPixels(int index, int col, byte** imageRGB);
};

#endif 
