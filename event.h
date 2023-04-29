/***************************************************************************//**
 * @file event.h
 ******************************************************************************/
#ifndef EVENT_H
#define EVENT_H

#include <GL/freeglut.h>
#include "canvas.h"

/***************************************************************************//**
 * @class Event
 * 
 * @brief Abstract base class for events
 ******************************************************************************/
class Event
{

public:
   virtual void doAction(Canvas &) = 0;
   virtual ~Event();
};

#endif
