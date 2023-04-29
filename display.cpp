#include "display.h"

void DisplayEvent::doAction(Canvas &canvas) 
{
   glClear(GL_COLOR_BUFFER_BIT);

   canvas.display();   

   glFlush();
}
