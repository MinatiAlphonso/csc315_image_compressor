#ifndef RESHAPE_H
#define RESHAPE_H

#include "location.h"

class ReshapeEvent : public LocationEvent
{
public:
   ReshapeEvent(int, int);
   void doAction(Canvas &);
};

#endif
