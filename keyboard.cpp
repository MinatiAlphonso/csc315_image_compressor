#include "keyboard.h"

KeyboardEvent::KeyboardEvent(unsigned char k, int x, int y) : LocationEvent(x, y), key(k) {}

void KeyboardEvent::doAction(Canvas &canvas)
{
	//condition to exit program
   if (key == ESCAPE_KEY || key == 'q')
      glutLeaveMainLoop();

	//condition to view the original image
   if (key == 'o' || key == 'O')
      canvas.imageType = ORIGINAL;

	//condition to view the energy image
   if (key == 'e' || key == 'E')
      canvas.imageType = ENERGY;

	//condition to view vertical seam
   if (key == 'v' || key == 'V')
   {
	   canvas.seamType = VERTICAL;
	   canvas.findVerticalSeam();
   }

	//condition to view horizontal seam
   if (key == 'h' || key == 'H')
   {
	   canvas.seamType = HORIZONTAL;
	   canvas.findHorizontalSeam();
   }
   
   //condition to delete a seam
   if(key == '-')
	   canvas.removeSeam();

   glutPostRedisplay();
}
