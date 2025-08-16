#include <TXLib.h>
#include <stdio.h>
#include <math.h>
/* Решение квадратного уравнения*/
int main()
{
    int x, y, z, a ,b ,c;
    printf("Введите коэффициенты a ,b ,c уравнения ax^2 + bx + c\n ");
    x = getchar();
    y = getchar();
    z = getchar();
    a = x - '0';
    b = y - '0';
    c = z - '0';
    printf (" %d\t %d\t %d\n", a, b, c);

    float d, x1, x2;
    d = x1= x2 = 0.0;

    if (a == 0)
    {

        x1 = x2 = (-1)*c/b  ;
        printf( " У уравнения один корень %f.2\n", x1);
    }
    else
    {
        /*Найдем дискриминант уравнения*/
        d = pow(b,2) - (4*a*c);

        /* Проверка наличия корней и их подсчет с дальшейшим выводом при наличии */

        if (d < 0)
        {
            printf("У уравнения отсутствуют корни\n");
        }
        else if (d ==0)
        {
            x2 = x1 = (-1)*b/(2*a);
            printf("У уравнения один корень, равный\t %.2f\n", x1);
        }
        else
        {
            x1 = (sqrt(d) - b)/(2*a);
            x2 = ((-1)*b - sqrt(d))/(2*a);
            printf("Корни уравнения равны %.2f\t %.2f\n",x1, x2 );
        }
    }

    return 0;
}
