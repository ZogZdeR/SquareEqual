#ifndef COUNTING_FUNCTION
#define COUNTING_FUNCTION

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

enum Quantity {
    none = 0,
    one = 1,
    two = 2,
    fuckin_many = -1
};
bool float_equal (float a, float b);
bool is_zero (float n);
enum Quantity square_equation_solver (float a, float b, float c, float* x1, float* x2);
enum Quantity linear (float b, float c, float *x1);
enum Quantity parabolic (float a, float b, float c, float *x1, float *x2);

#endif // COUNTING_FUNCTION
