#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>

using namespace std;
typedef unsigned char byte;

void displayColor(int x, int y, int w, int h, byte **);
void displayMonochrome(int x, int y, int w, int h, byte **);
void drawHSeam(vector<int> path);
void drawVSeam(vector<int> path);

#endif
