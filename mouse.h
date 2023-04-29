#ifndef MOUSE_H
#define MOUSE_H

#include "location.h"

class MouseEvent : public LocationEvent
{
   int button;
   int state;
public:
   MouseEvent(int, int, int, int);
   void doAction(Canvas &);
};

#endif
