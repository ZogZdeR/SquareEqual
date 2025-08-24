#include <TXLib.h>
#include <stdio.h>
#include <math.h>

enum Quantity {
    none = 0,
    one = 1,
    two = 2,
    fuckin_many = -1
};

// FIXME с большой буквы(код стайл) и название более конкретное
struct Square_eqw_test
{
    float a;
    float b;
    float c;
    float x1;
    float x2;
    Quantity quantity;
};

bool float_equal(float a, float b);
void solver_test();
Quantity linear (float b, float c, float *x1);
Quantity parabolic (float a, float b, float c, float *x1, float *x2);
void clear_buffer ();
int enter_coeff (float *a, float *b, float *c, char *check);
Quantity square_equation_solver (float a, float b, float c, float* x1, float* x2);
void print_solve(float x1, float x2, Quantity quantity);
bool is_zero (float n);

/* Решение квадратного уравнения*/
int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    char check = 'n';
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
        solver_test ();

        printf ("Хотите выйте из программы? Да - введите y, нет - введите n\n");
        clear_buffer();
        check = getchar();
    }
    return 0;
}

bool is_zero(float n)
{
    assert (!(isnan(n)));

    const float delta = 0.0000001;
    return (fabs(n) < delta);
}

void clear_buffer ()
{
    int c = '\0';
    do
    {
        c = getchar();
    }
    while (c != '\n' and c != EOF);
}

int enter_coeff (float *a, float *b, float *c, char *check)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    assert (check != NULL);

    do
    {
        int leave = 0;
        printf ("Введите коэффициенты a, b, c уравнения ax^2 + bx + c\n ");
        switch (scanf ("%f %f %f", a, b, c))
        {
            case 3:
                leave++;
                break;
            case EOF:
                printf ("Конец ввода\n");
                return 1;
            default:
                clear_buffer ();
                printf ("Некорректный ввод параметров. Хотите выйти из программы? Да - введите y, Нет - введите n\n");
        }
        if (leave) break;
        *check = getchar();
    }
    while (*check != 'y');
    return 0;
}

Quantity square_equation_solver (float a, float b, float c, float* x1, float* x2)
{
    assert (!(isnan(a)));
    assert (!(isnan(b)));
    assert (!(isnan(c)));
    assert (x1 != NULL);
    assert (x2 != NULL);

    if (a == 0) return linear(b, c, x1);
    else return parabolic (a, b, c, x1, x2);
}

void print_solve (float x1, float x2, Quantity quantity)
{
    switch (quantity)
    {
        case one: printf ("У уравнения один корень, равный %f\n", x1);
                break;
        case two:
                assert (x1 != x2);
                printf ("У уравнения 2 корня, равные %f и %f\n", x1, x2);
                break;
        case none: printf ("У уравнения отсутсвуют корни\n");
                break;
        case fuckin_many: printf ("У уравнения бесконечно-много корней\n");
        default : break;
    }
 }

Quantity linear (float b, float c, float *x1)
{
    if (b == 0)
    {
        return ((c == 0) ? fuckin_many : none);
    }
    else
    {
        *x1 = (-1) * c / b  ;
        return one;
    }
}

Quantity parabolic (float a, float b, float c, float *x1, float *x2)
{
    float discr = b * b - (4 * a * c);/*Найдем дискриминант уравнения*/

    /* Проверка наличия корней и их подсчет с дальшейшим выводом при наличии */
    if (is_zero(discr))
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
        *x1 = ((-1) * b - sqrt(discr)) / (2 * a);
        *x2 = ((-1) * b + sqrt(discr)) / (2 * a);
        return two;
    }
}

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
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
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
            printf ("a = %f, b = %f, c = %f, x1 = %f, x2 = %f, quantity = %d\t(correct is x1 = %f, x2 = %f, quantity = %d)\n", arr[i].a, arr[i].b, arr[i].c, test_x1, test_x2, test_quantity, arr[i].x1, arr[i].x2, arr[i].quantity);
        }
    }
    if (perfect)
        printf("Every test is correct\n");
}

bool float_equal (float a, float b)
{
   const float delta = 0.0000001;
   return (fabs (a - b) < 2 * delta || (isnan(a) && isnan(b)) );
}
