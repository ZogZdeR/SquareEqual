#ifndef IO_FUNCTION
#define IO_FUNCTION

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "counting_function.h"
#include "colour.h"

void clear_buffer ();
int enter_coeff (float *a, float *b, float *c, int *check);
void print_solve(float x1, float x2, Quantity quantity);

#endif // IO_FUNCTION
