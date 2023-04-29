#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "location.h"
#include "alloc2d.h"

#define ESCAPE_KEY 27

class KeyboardEvent : public LocationEvent
{
   unsigned char key;
public:
   KeyboardEvent(unsigned char, int, int);
   void doAction(Canvas &);
};

#endif
