#ifndef ALLOC2D_H
#define ALLOC2D_H

typedef unsigned char byte;

byte** alloc2D( int nrows, int ncols );
int** alloc2D_32(int nrow, int ncols);
void free2D( byte** image );
void free2D_32(int** image);
#endif
