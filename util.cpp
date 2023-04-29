/***************************************************************************//**
 * @file
 ******************************************************************************/
#include <iostream>
#include "util.h"
#include "init.h"

using namespace std;

/***************************************************************************//**
 * @brief utilityCentral
 *
 * @par Description
 *    This function is the central location that collects events of all types
 * and maintains a persistent storage for them.  This application requires that
 * a certain number of the events be kept and reported after each new event
 * is sent.
 *
 * @param[in] obj - a pointer to an object of abstract base class type myBase
 ******************************************************************************/
void utilityCentral(Event* obj)
{
   // Canvas is where we're holding pointers to the various images
   static Canvas canvas;

   obj->doAction(canvas);

   delete(obj);
}

/***************************************************************************//**
 * @brief initOpenGL
 *
 * @param[in] argc - number of command line arguments
 * @param[in] argv - array of C strings representing the command line arguments
 *
 ******************************************************************************/
void initOpenGL(char *filename) 
{
   utilityCentral(new InitEvent(filename));
}
