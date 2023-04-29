/**
 * @file canvas.cpp
 * Holds the implemention of the Canvas class functions
 */

#include "canvas.h"
#include <iostream>
#include "keyboard.h"
///Canvas constructor, starts out the program by displaying the original RGB image
Canvas::Canvas()
{
   imageType = ORIGINAL;
}

///Canvas destructor, frees up dynamically allocated memory
Canvas::~Canvas()
{
   free2D(imageRGB);
   free2D_32(imageEnergy);
   free2D(imageMono);
   free2D_32(totalEnergy);
}

/**
 * @authors Minati Alphonso, Dustin Richards
 * @brief displays the image and seam (if present) according to the imageType and seamType
 */
void Canvas::display()
{
   //display the original color image
   if (imageType == ORIGINAL)
      displayColor(0, 0, originalWidth, height, imageRGB);
  
   //calculate and display the scaled down energy image
   if (imageType == ENERGY)
   {
      //free memory before doing calculations to prevent memory leaks
      free2D_32(imageEnergy);
      free2D(imageMono);

      //calculate the energy image from the original
	   imageEnergy = calcEnergy(width,height, imageRGB);
      //calculate the scaled-down energy image
	   imageMono = convertMono(width, originalWidth, height, imageEnergy);
	   
      //display the scaled-down energy image
	   displayMonochrome(0, 0, originalWidth, height, imageMono);
   }
   
   //display a vertical seam
   if (seamType == VERTICAL)
   {
      //TODO: this recalculates the energy image every time if we're displaying the original
      //only calculate the energy image if necessary
	   if(imageType != ENERGY)
      {
         free2D_32(imageEnergy);
		   imageEnergy = calcEnergy(width,height,imageRGB);
      }

      //draw the seam over the currently displayed image
		drawVSeam(path);
   }
   //display a horizontal seam
   else if (seamType == HORIZONTAL)
   {
      //TODO: this recalculates the energy image every time if we're displaying the original
      //only calculate the energy image if necessary
	   if(imageType != ENERGY)
      {
         free2D_32(imageEnergy);
		   imageEnergy = calcEnergy(width,height,imageRGB);
      }

      //draw the seam over the currently displayed image
		drawHSeam(path);
   }
}

/**
 * @authors Minati Alphonso, Dustin Richards
 * @brief finds the least-energy horizontal seam in the imageEnergy array using a dynamic programming approach
 */
void Canvas::findHorizontalSeam()
{
	if(height < 1)
		glutLeaveMainLoop();
	
   //throw out the old totalEnergy array
   free2D_32(totalEnergy);
   //allocate some space for the new totalEnergy arrray
   totalEnergy = alloc2D_32(height,width);

   //set all pixels on the left side of the image to their own energy
   for (int r = 0; r < (int)height; r++)
      totalEnergy[r][0] = imageEnergy[r][0];
  
   //build up the totalEnergy array
   //loop through every column except the first
   for (int c = 1; c < (int)width; c++)
   {
      //loop through every pixel in the column
      for (int r = 0; r < (int)height; r++)
      {
         int min = numeric_limits<int>::max();
         //out of three pixels (one up, one directly left, and one down) in the
         //  column adjacent to the left, which one has the lowest value? 
         for (int i = -1; i <= 1; i++)
         {
            if (r + i >= 0 && r + i < (int)height)
            {
               if (totalEnergy[r+i][c-1] < min)
                  min = totalEnergy[r+i][c-1];
            }
         }
         //set the total lowest path energy of this pixel to the total energy
         //  of the previously found lowest total energy pixel plus this pixel's
         //  energy
         totalEnergy[r][c] = imageEnergy[r][c] + min;
      }
   }
   
   //out of all the pixels in the rightmost column, which one has the lowest
   //  total path energy?
   int minIndex = 0;
   int minEnergy = numeric_limits<int>::max();
   for (int r = 0; r < (int)height; r++)
   {
      if (totalEnergy[r][width - 1] < minEnergy)
      {
         minIndex = r;
         minEnergy = totalEnergy[r][width - 1];
      }
   }
   
   path.clear();
   //prime the path vector with the row index of the lowest total path energy
   //  pixel in the rightmost column
   path.push_back(minIndex);

   //working from right to left, find the least energy path from the starting
   //  pixel at path[0]
   for (int c = width - 1; c >= 1; c--)
   {
      minIndex = -99;
      int minVal = numeric_limits<int>::max();

      //out of the three pixels adjacent to the left, which has the lowest
      //  total path energy?
      for (int i = -1; i <= 1; i++)
      {
         if (path.back()+i > 0 && path.back()+i < (int)height-1 && totalEnergy[path.back()+i][c-1] < minVal)
         {
            minIndex = path.back()+i;
            minVal = totalEnergy[path.back()+i][c-1];
         }
      }

      //push the row index of that pixel on to the path, this will be the
      //  starting point for the next iteration of the for loop
      path.push_back(minIndex);
   }
}

/**
 * @authors Dustin Richards, Minati Alphonso
 * @brief finds the least-energy vertical seam in the imageEnergy array using a dynamic programming method
 */
void Canvas::findVerticalSeam()
{
	if(width == 0)
		glutLeaveMainLoop();
	
   //throw out the old totalEnergy array
   free2D_32(totalEnergy);
   //allocate some space for the new totalEnergy arrray
   totalEnergy = alloc2D_32(height, width);

   //set all pixels on the bottom of the image to their own energy
   for (int c = 0; c < (int)width; c++)
   {
      totalEnergy[0][c] = imageEnergy[0][c];
   }

   //build up the totalEnergy array
   //loop through every row except the bottom
   for (int r = 1; r < (int)height; r++)
   {
      //loop through every pixel in the row
      for (int c = 0; c < (int)width; c++)
      {
         int min = numeric_limits<int>::max(); 
         //out of three pixels (one left, one directly up, one right) in the
         //  row directly above, which one has the lowest value? 
         for (int i = -1; i <= 1; i++)
         {
            if (c + i >= 0 && c + i < (int)width)
            {
               if (totalEnergy[r-1][c+i] < min)
                  min = totalEnergy[r-1][c+i];
            }
         }
         //set the total lowest path energy of this pixel to the total energy
         //  of the previously found lowest total energy pixel plus this pixel's
         //  energy
         totalEnergy[r][c] = imageEnergy[r][c] + min;
      }
   }

   //out of all the pixels in the top row, which one has the lowest
   //  total path energy?
   int minIndex = 0;
   int minEnergy = numeric_limits<int>::max();
   for (int c = 0; c < (int)width; c++)
   {
      if (totalEnergy[height-1][c] < minEnergy)
      {
         minIndex = c;
         minEnergy = totalEnergy[height-1][c];
      }
   }

   path.clear();
   //prime the path vector with the column index of the lowest total path energy
   //  pixel in the top row
   path.push_back(minIndex);

   //working from top to bottom, find the least energy path from the starting
   //  pixel at path[0]
   for (int r = height - 1; r >= 1; r--)
   {
      minIndex = -99;
      int minVal = numeric_limits<int>::max();

      //out of the three pixels adjacent below, which has the lowest
      //  total path energy?
      for (int i = -1; i <= 1; i++)
      {
         if (path.back()+i > 0 && path.back()+i < (int)width-1 && totalEnergy[r-1][path.back()+i] < minVal )
         {
            minIndex = path.back()+i;
            minVal = totalEnergy[r-1][path.back()+i];
         }
      }

      //push the column index of that pixel on to the path, this will be the
      //  starting point for the next iteration of the for loop
      path.push_back(minIndex);
   }
}
