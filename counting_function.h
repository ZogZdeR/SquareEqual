//! @file

#ifndef COUNTING_FUNCTION
#define COUNTING_FUNCTION

#include <assert.h>
#include <stdio.h>
#include <math.h>

//! @brief Number of roons
enum Quantity {
    none = 0,
    one = 1,
    two = 2,
    fuckin_many = -1
};

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐---------------------------
//! Indicates that two parameters are equal
//! @param [in] a - first integer
//! @param [in] b - second integer
//!
//! @return true in case a and b are equal, false in the other case
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐---------------------------
bool float_equal (float a, float b);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐---------------------------
//! Indicates that a parameter is zero
//!
//! @param [in] n - integer
//!
//! @return true in case integer is zero, false in case integer is not a zero
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐---------------------------
bool is_zero (float n);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐-
//! Solves a square equation ax2 + bx + c = 0
//!
//! @param [in] a a - coefficient
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns fuckin_many
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
enum Quantity square_equation_solver (float a, float b, float c, float* x1, float* x2);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a linear equation bx + c = 0
//!
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//! @param [out] x1 Pointer to the root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns fuckin_many
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
enum Quantity linear (float b, float c, float *x1);

//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! Solves a square equation ax^2 + bx + c = 0
//! @param [in] a a - coefficient
//! @param [in] b b - coefficient
//! @param [in] c c - coefficient
//! @param [out] x1 Pointer to the first root
//! @param [out] x2 Pointer to the second root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns fuckin_many
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
enum Quantity parabolic (float a, float b, float c, float *x1, float *x2);

#endif // COUNTING_FUNCTION
