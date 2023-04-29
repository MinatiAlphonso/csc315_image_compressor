/**
 * @file energy.h
 */

#ifndef ENERGY_H_
#define ENERGY_H_

///a typedef of unsigned char because that's too long to type out
typedef unsigned char byte;

int** calcEnergy(int, int, byte**);
byte** convertMono(int, int, int, int**);

#endif
