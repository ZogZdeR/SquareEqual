#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "test_function.h"

void solver_test ()
{
    Square_eqw_test arr[7] = {
        {0,  0 , 0 , NAN, NAN, fuckin_many},
        {0,  0 , 1 , NAN, NAN,        none},
        {1,  0 , 1 , NAN, NAN,        none},
        {1,  2 , 1 , -1 , NAN,         one},
        {1,  5 , 6 , -3 , -2 ,         two},
        {0,  1 , 5 , -5 , NAN,         one},
        {2, -14, 24,  3 ,  4 ,         two}
    };

    float test_x1 = NAN;
    float test_x2 = NAN;
    Quantity test_quantity;
    bool perfect = true;
    for (unsigned i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        test_x1 = NAN;
        test_x2 = NAN;
        test_quantity = square_equation_solver (arr[i].a, arr[i].b, arr[i].c, &test_x1, &test_x2);
        if (float_equal (test_quantity, arr[i].quantity)
            && float_equal (test_x1, arr[i].x1)
            && float_equal (test_x2, arr[i].x2))
        {
            perfect = perfect;
        }
        else
        {
            perfect = false;
            printf (red "a = %f, b = %f, c = %f, x1 = %f, x2 = %f, quantity = %d\t(correct is x1 = %f, x2 = %f, quantity = %d)" normal "\n", arr[i].a, arr[i].b, arr[i].c, test_x1, test_x2, test_quantity, arr[i].x1, arr[i].x2, arr[i].quantity);
        }
    }
    if (perfect)
        printf(green "Every test is correct" normal "\n");
}


