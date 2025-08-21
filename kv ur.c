#include <TXLib.h>
#include <stdio.h>
#include <math.h>
/* Решение квадратного уравнения*/





int main()
{
    float a, b, c;
    char check = 'a';

    do
    {
    printf("Введите коэффициенты a, b, c уравнения ax^2 + bx + c\n ");
    if (scanf (" %f%f%f", &a, &b, &c) == 3) break;
    else printf ("Некорректный ввод параметров, введите q для выхода из программы или любой другой символ для повторной попытки ввода коэффициентов\n");
    fflush(stdin);
    check = getchar();

    }
   while (check != 'q');




    float discr, x1, x2;
    discr = x1 = x2 = 0.0;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0) printf ("У уравнения бесконечно-много корней");
            else printf ("У уравнения отсутствуют корни");
        }
        else
        {
            x1 = x2 = (-1) * c / b  ;
            printf( " У уравнения один корень %.6f\n", x1);
        }
    }
    else
    {
        /*Найдем дискриминант уравнения*/
        discr = b * b - (4 * a * c);

        /* Проверка наличия корней и их подсчет с дальшейшим выводом при наличии */

        if (discr < 0)
        {
            printf("У уравнения отсутствуют корни\n");
        }
        else if (discr == 0)
        {
            x2 = x1 = (-1) * b / (2 * a);
            printf("У уравнения один корень, равный\t %.6f\n", x1);
        }
        else
        {
            x1 = ((-1) * b - sqrt(discr)) / (2 * a);
            x2 = ((-1) * b + sqrt(discr)) / (2 * a);
            printf("Корни уравнения равны %.6f\t %.6f\n", x1, x2);
        }
    }


    return 0;
}


