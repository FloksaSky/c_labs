#include <stdio.h>
#include <math.h>

int main() 
{
    double power(double a, int b)
    {
        if (b > 0) return a*power(a, b-1);
        if (b < 0) return 1.0 / power(a, -b);
        return 1; // if b == 0
    }

    double a, f1, f2=1, i;
    int b;
    printf("Введите число а \t");
    scanf("%lf", &a);
    printf("\nВведите степень b \t");
    scanf("%d", &b);
    f1=power(a,b);
    printf("Результат работы рекурсии: %lf \n", f1);

    for (i=1; i<=b; i++)
        f2*=a;
    printf("Результат работы цикла: %lf", f2);

}