#include "reshape.h"

// Right now does nothing but could tie this to the horizontal and vertical
// seam removal if we can make those operations fast enough
ReshapeEvent::ReshapeEvent(int x, int y) : LocationEvent(x, y){}

void ReshapeEvent::doAction(Canvas &canvas) {}
