#include "init.h"

InitEvent::InitEvent(char *f) : fileName(f) {}

void InitEvent::doAction(Canvas &canvas)
{
   // Read the PNG image and point to it with canvas.imageRGB
   canvas.imageRGB = readPNG(fileName, canvas.width, canvas.height);
   canvas.originalWidth = canvas.width;

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(canvas.width, canvas.height);
   glutInitWindowPosition(0, 0);
   glutCreateWindow(fileName);
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouseClick);
   glutReshapeFunc(reshape);
}
