/***************************************************************************//**
 * @file locationEvent.h
 ******************************************************************************/
#ifndef LOCATIONEVENT_H
#define LOCATIONEVENT_H

#include "event.h"

/***************************************************************************//**
 * @class LocationEvent
 * 
 * @brief Event that includes screen coordinates
 ******************************************************************************/
class LocationEvent : public Event
{
protected:
   int xLoc, yLoc;

public:
   LocationEvent(int, int);
   virtual void doAction(Canvas &) = 0;
   virtual ~LocationEvent();
};

#endif
