/**
 * @file alloc2d.cpp
 */

/*
                ***** alloc2d.cpp *****

Routines for dynamic 2-D array (de)allocation.

Author: John M. Weiss, Ph.D.
Author: Paul J. Hinker, Ph.D.
Class:  CSC 315 Data Structures & Algorithms
Date:   Spring 2018
Updated:Fall 2019
*/

#include <cstring>
#include "alloc2d.h"

// allocate 2-D array of integers
int** alloc2D_32( int nrows, int ncols )
{
    // allocate a row of pointers
    int** image = new int* [nrows];
    if ( image == NULL ) return NULL;

    // allocate array elements
    int* pixels = new int [ nrows * ncols ];
    if ( pixels == NULL ) { delete [] image; return NULL; }

    // zero out array elements
    memset( pixels, 0, nrows * ncols * sizeof (int) );

    // point the row pointers at each row of the 2-D array
    for ( int row = 0; row < nrows; ++row, pixels += ncols )
        image[ row ] = pixels;

    // and return...
    return image;
}

// deallocate 2-D array of bytes (unsigned char)
byte** alloc2D( int nrows, int ncols )
{
    // allocate a row of pointers
    byte** image = new byte* [nrows];
    if ( image == NULL ) return NULL;

    // allocate array elements
    byte* pixels = new byte [ nrows * ncols ];
    if ( pixels == NULL ) { delete [] image; return NULL; }

    // zero out array elements
    memset( pixels, 0, nrows * ncols * sizeof (byte) );

    // point the row pointers at each row of the 2-D array
    for ( int row = 0; row < nrows; ++row, pixels += ncols )
        image[ row ] = pixels;

    // and return...
    return image;
}

// deallocate 2-D array of bytes
void free2D( byte** image )
{
    if ( image )
    {
        delete [] *image;
        delete [] image;
    }
}

/**
 * @author Dustin Richards
 * @brief adapted from free2D, frees a 2-D array of ints
 *
 * @param[in] image - a pointer to the 2-D array to free
 */
void free2D_32(int** image)
{
   if (image)
   {
      delete [] *image;
      delete [] image;
   }
}
