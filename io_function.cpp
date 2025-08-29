#include "io_function.h"
#include <stdio.h>
#include <math.h>

void clear_buffer () // skip all chars that are isspace(c), and ungetc(file, c) the first one that isn't
{
    int c = '\0';
    do
    {
        c = getchar ();
    }
    while (c != '\n' and c != EOF);
}


int enter_coeff (float *a, float *b, float *c, int *check)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    assert (check != NULL);

    do
    {
        int leave = 0;
        printf (cyan "Введите коэффициенты a, b, c уравнения ax^2 + bx + c" normal "\n");
        switch (scanf ("%f %f %f", a, b, c))
        {
            case 3:
                leave++;
                break;
            case EOF:
                printf (red "Конец ввода" normal "\n");
                return 1;
            default:
                clear_buffer ();
                printf (magenta "Некорректный ввод параметров. Хотите выйти из программы? Да - введите y, Нет - введите n" normal "\n");
        }
        if (leave) break;
        *check = getchar ();
    }
    while (*check != 'y');
    return 0;
}

void print_solve (float x1, float x2, Quantity quantity)
{
    switch (quantity)
    {
        case one:
            printf (green "У уравнения один корень, равный %f" normal "\n", x1);
            break;
        case two:
            printf (green "У уравнения 2 корня, равные %f и %f" normal "\n", x1, x2);
            break;
        case none: 
            printf (red "У уравнения отсутсвуют корни" normal "\n");
            break;
        case fuckin_many:
            printf (white "У уравнения бесконечно-много корней" normal "\n");
            break;
        default:
            assert (0);
            break;
    }
 }

 void out_check (int * check)
 {
    printf ("Вы хотите выйте из программы? yes - введите y, нет - введите n\n");
    clear_buffer ();
    *check = getchar ();
    if (*check != 'y' and *check != 'n') 
    {
        printf (red "Некорректный ввод. Попробуйте еще раз" normal "\n");
        out_check (check);
    }
 }
