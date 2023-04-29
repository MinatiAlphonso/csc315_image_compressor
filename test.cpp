#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "alloc2D.h"
#include "energy.h"
#include "canvas.h"
// convenience type
typedef unsigned char byte;

// Create a pretend 24-bit image from a 1-d array of bytes
byte **fillImage()
{
   byte pixels[] {
      255, 101, 51, 255, 101, 153, 255, 101, 255,
      255, 153, 51, 255, 153, 153, 255, 153, 255,
      255, 203, 51, 255, 204, 153, 255, 205, 255,
   };
   byte **image = alloc2D(3, 3*3);
   byte *img = *image;
   int count = 0;
   for (unsigned row = 0 ; row < 3 ; ++row)
   {
      for (unsigned col = 0 ; col < 3 ; ++col)
      {
        *img++ = pixels[count++];
        *img++ = pixels[count++];
        *img++ = pixels[count++];
      }
   }
   return image;
}

TEST_CASE("Assign an image to the canvas - Calculate dual gradient")
{
	Canvas canvas;
	canvas.height = 3;
	canvas.width = 3;
    canvas.imageRGB = fillImage();
   
   canvas.imageEnergy = calcEnergy(3, 3, canvas.imageRGB);
   

   REQUIRE(canvas.imageEnergy[0][0] == 12904);
   REQUIRE(canvas.imageEnergy[0][1] == 44217);
   REQUIRE(canvas.imageEnergy[0][2] == 13108);
   REQUIRE(canvas.imageEnergy[1][0] == 20808);
   REQUIRE(canvas.imageEnergy[1][1] == 52225);
   REQUIRE(canvas.imageEnergy[1][2] == 21220);
   REQUIRE(canvas.imageEnergy[2][0] == 13109);
   REQUIRE(canvas.imageEnergy[2][1] == 44324);
   REQUIRE(canvas.imageEnergy[2][2] == 13109);
   
   canvas.findVerticalSeam();
   //REQUIRE(canvas.totalEnergy[0][0] == 12904);
}
