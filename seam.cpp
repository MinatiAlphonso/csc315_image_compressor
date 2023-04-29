/***************************************************************************\\**
 * @file seam.cpp
 ******************************************************************************/
/**************************************************************************//**
 * @file seam.cpp
 *
 * @brief Contains functions for the canvas class that deal with the 
 * removal of seams.
 *
 * @author: Minati Alphonso
 * 			Dustin Richards
 *
 * @par Class:
 * CSC315 Data Structures
 *
 * @date: Fall 2019
 *
 ******************************************************************************/
#include "canvas.h"

/**************************************************************************//**
 * @author Dustin Richards, Minati Alphonso
 * @brief Function to remove the vertical and horizontal seam
 *
 ******************************************************************************/
void Canvas::removeSeam()
{
	int index;
	int col = width*3 - 3;
	int row = height-1;
	int i;
	
	//removal of horizontal seam
	if(seamType == HORIZONTAL)
	{	
		for(i = 0; i < path.size(); i++)
		{
			index = path[i];
			mergeVPixels(index,col,imageRGB);//Red pixel 
			mergeVPixels(index,col+1,imageRGB);//Green pixel
			mergeVPixels(index,col+2,imageRGB);//Blue pixel
			col-=3;
		}
		height--; //updating height of image
	}
	//removal of vertical seam
	else if(seamType == VERTICAL)
	{
		for(i = 0; i < path.size(); i++)
		{
			index = path[i]*3;
			mergeHPixels(index,row,imageRGB);
			row--;
		}
		width--; //updating width of image
   }

	//recalculating the energy map with the updated dimensions
   free2D_32(imageEnergy);
	imageEnergy = calcEnergy(width,height,imageRGB);
	
	//finding the vertical seam again and redrawing it
   if (seamType == VERTICAL)
   {
      findVerticalSeam();
      drawVSeam(path);
   }
   
   //finding the horizontal seam again and redrawing it
   else if (seamType == HORIZONTAL)
   {
      findHorizontalSeam();
      drawHSeam(path);
   }
}

/**************************************************************************//**
 * @author Dustin Richards, Minati Alphonso
 * @brief Function to merge all the pixels to the right of the seam when 
 * the vertical seam is removed. 
 *
 ******************************************************************************/
void Canvas::mergeHPixels(int index, int row, byte** imageRGB)
{
	//merging the horizontal pixels from right to left
   for(int i = index; i < width*3-3; i++)
   {
	   imageRGB[row][i] = imageRGB[row][i+3];
   }

	//set the pixels on the right edge to black 
   for (int r = 0; r < height; r++)
   {
      imageRGB[r][width*3-3] = 0;
      imageRGB[r][width*3-2] = 0;
      imageRGB[r][width*3-1] = 0;
   }
}

/**************************************************************************//**
 * @author Minati Alphonso, Dustin Richards
 * @brief Function to merge all the pixels above the seam when 
 * the horizontal seam is removed. 
 *
 ******************************************************************************/
void Canvas::mergeVPixels(int index, int col, byte** imageRGB)
{
	//merging the vertical pixels from top to bottom
	for(int i = index; i < height-1; i++)
	{
		imageRGB[i][col] = imageRGB[i+1][col];
	}
}
