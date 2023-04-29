#include "mouse.h"

// Right now doesn't do anything, here in case we want to use the mouse
// to highlight image areas for removal or preservation
MouseEvent::MouseEvent(int b, int s, int x, int y) : LocationEvent(x, y), button(b), state(s) {}

void MouseEvent::doAction(Canvas &canvas) {}
