#include "counting_function.h"

#include <stdio.h>
#include <math.h>

Quantity square_equation_solver (float a, float b, float c, float* x1, float* x2)
{
    assert (!(isnan (a)));
    assert (!(isnan (b)));
    assert (!(isnan (c)));
    assert (x1 != NULL);
    assert (x2 != NULL);

    if (float_equal (a, 0)) return linear (b, c, x1);
    else return parabolic (a, b, c, x1, x2);
}

Quantity linear (float b, float c, float *x1)
{
    if (float_equal (0, b))
    {
        return (float_equal (c, 0) ? fuckin_many : none);
    }
    else
    {
        *x1 = (-1) * c / b  ;
        return one;
    }
}

Quantity parabolic (float a, float b, float c, float *x1, float *x2)
{
    float discr = b * b - (4 * a * c);  
    if (is_zero (discr))
    {
        *x1 = (-1) * b / (2 * a);
        return one;
    }
    else if (discr < 0)
    {
         return none;
    }
    else
    {
        *x1 = ((-1) * b - sqrtf (discr)) / (2 * a);
        *x2 = ((-1) * b + sqrtf (discr)) / (2 * a);
        return two;
    }
}

bool is_zero (float n)
{
    assert (!(isnan (n)));

    const float delta = 0.0000001f;
    return (fabs (n) < delta);
}

bool float_equal (float a, float b)
{
   const float delta = 0.0000001f;
   return (fabs (a - b) < 2 * delta || (isnan (a) && isnan (b)) );
}
