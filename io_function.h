//! @file
#ifndef IO_FUNCTION
#define IO_FUNCTION
#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "counting_function.h"
#include "colour.h"

void clear_buffer ();

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐----------------------
//! sets coefficients a, b, c of square equation ax^2 + bx + c = 0
//! @param [out] a a - coefficient
//! @param [out] b b - second integer
//! @param [out] c c - third integer
//! @param [out] check check - flag parameter needed to keep program run
//!
//! @return 1 in case of end of file , 0 in other situations
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐----------------------
int enter_coeff (float *a, float *b, float *c, int *check);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐----------------
//! prints a solution of the square equation
//! @param [in] x1 x1 - first root(if declared, if not - NAN)
//! @param [in] x2 x2 - second root(if declared, if not - NAN)
//! @param [in] quantity quantity - quantity of roots
//!
//! @return 1 in case of end of file , 0 in other situations
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐----------------
void print_solve (float x1, float x2, Quantity quantity);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐-------------------------
//! function nneded to check uder's intention to leave a programm
//! @param [in] check check - flag parameter needed to get user's intention
//! @param [in] quantity quantity - quantity of roots
//!
//! @return 1 in case of end of file , 0 in other situations
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐-------------------------
void out_check (int * check);

#endif // IO_FUNCTION
