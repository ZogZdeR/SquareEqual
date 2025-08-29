#include <stdio.h>
#include <math.h>

#include "counting_function.h"
#include "test_function.h"
#include "io_function.h"
#include "colour.h"

int main()
{
    file_test ();

    float a = 0;
    float b = 0;
    float c = 0;
    int check = 'n';
    while (check != 'y')
    {
        switch (enter_coeff (&a, &b, &c, &check))
        {
            case 1:
                return 0;
            case 0:
                if (check == 'y')
                {
                    printf ("Завершение программы\n");
                    return 0;
                }
            default: break;
        }
        float x1 = NAN;
        float x2 = NAN;
        Quantity quantity = square_equation_solver (a, b, c, &x1, &x2);
        print_solve (x1, x2, quantity);

        out_check(&check);

    }
    return 0;
}

