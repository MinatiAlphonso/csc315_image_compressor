/**
 * @file energy.cpp
 */

#include "energy.h"
#include "alloc2d.h"

/**
 * @authors Dustin Richards, Minati Alphonso
 * @brief takes an RGB image and generates an greyscale energy image for least-energy path calculations
 *
 * @param[in] width - the width of the RGB image in pixels, also the width of the output
 * @param[in] height - the height of the RGB image in pixels, also the height of the output
 * @param[in] img - a pointer to the 2-D array of bytes that represents the RGB image
 *
 * @returns a pointer to the 2-D array of ints that represents the energy of the original image
 */
int** calcEnergy(int width, int height, byte** img)
{
   width *= 3;

   int xRedDiff, xGreenDiff, xBlueDiff;
   int yRedDiff, yGreenDiff, yBlueDiff;
   int xGradient, yGradient;

	//allocating a 2-D array of integers
   int** energy = alloc2D_32(height, width / 3);

	//calculating the energy map
   for (int r = 0; r < height; r++)
   {
      for (int c = 0; c < width; c += 3)
      {
		  //calculating the x-gradient
		  
		  //finding the difference between the RGB pixels
         if (c == 0) //if first column, then wrap around
         {
            xRedDiff = img[r][width - 3] - img[r][3];
            xGreenDiff = img[r][width - 2] - img[r][4];
            xBlueDiff = img[r][width - 1] - img[r][5];
         }
         else if (c == width - 3) //if last column, then wrap around
         {
            xRedDiff = img[r][width - 6] - img[r][0];
            xGreenDiff = img[r][width - 5] - img[r][1];
            xBlueDiff = img[r][width - 4] - img[r][2];
         }
         else // general case
         {
            xRedDiff = img[r][c - 3] - img[r][c + 3];
            xGreenDiff = img[r][c - 2] - img[r][c + 4];
            xBlueDiff = img[r][c - 1] - img[r][c + 5];
         }
		 
		//squaring the differences
         xRedDiff *= xRedDiff;
         xGreenDiff *= xGreenDiff;
         xBlueDiff *= xBlueDiff;
		 
		 //adding the squared differences
         xGradient = xRedDiff + xGreenDiff + xBlueDiff; //x-gradient


		//calculating the y-gradient
		
		//finding the difference between the RGB pixels
         if (r == 0) //if first row, then wrap around
         {
            yRedDiff = img[height - 1][c] - img[1][c];
            yGreenDiff = img[height - 1][c + 1] - img[1][c + 1];
            yBlueDiff = img[height - 1][c + 2] - img[1][c + 2];
         }
         else if (r == height - 1) //if last row, then wrap around
         {
            yRedDiff = img[height - 2][c] - img[0][c];
            yGreenDiff = img[height - 2][c + 1] - img[0][c + 1];
            yBlueDiff = img[height - 2][c + 2] - img[0][c + 2];
         }
         else //general case
         {
            yRedDiff = img[r - 1][c] - img[r + 1][c];
            yGreenDiff = img[r - 1][c + 1] - img[r + 1][c + 1];
            yBlueDiff = img[r - 1][c + 2] - img[r + 1][c + 2];
         }
	
		//squaring the differences
         yRedDiff *= yRedDiff;
         yGreenDiff *= yGreenDiff;
         yBlueDiff *= yBlueDiff;
		 
		 //adding the squared differences
         yGradient = yRedDiff + yGreenDiff + yBlueDiff; //y-gradient

         energy[r][c / 3] = xGradient + yGradient; //adding the x & y gradients together
      }
   }

   return energy; //the energy map
}

/**
 * @authors Minati Alphonso, Dustin Richards
 * @brief scales down every pixel in an energy image to the range of [0..255] so it can be displayed easily
 *
 * @param[in] width - the current width of the energy image
 * @param[in] originalWidth - the width of the image when it was initially loaded and processed by imageio.cpp
 * @param[in] height - the current height of the energy image
 * @param[in] energy - a pointer to a 2-D array of ints that represents the energy image
 *
 * @returns a pointer to a 2-D array of bytes with the scaled down energy image
 */
byte** convertMono(int width, int originalWidth, int height, int** energy)
{
   //this is a scaling factor to bring the values of an energy map down to
   //  the range of [0..255]
	double scalar = 1.0/765;
	byte** convert = alloc2D(height,originalWidth);
	
	//scaling every pixel in the energy image
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			convert[i][j] = energy[i][j] * scalar;
		}
	}

	return convert; //the scaled down energy image
}
