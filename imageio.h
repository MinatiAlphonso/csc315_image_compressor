#ifndef IMAGE_H
#define IMAGE_H

#include <cmath>

typedef unsigned char byte;

byte** alloc2D( int nrows, int ncols );
void free2D( byte** image );
byte** readPNG( char* filename, unsigned& width, unsigned& height);
byte** grayscale( unsigned width, unsigned height, byte** imgRGB );
void initOpenGL( const char *filename, unsigned w, unsigned h, byte** imgRGB, byte** imgGray );

#endif
