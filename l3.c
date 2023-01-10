#include <stdio.h>
#include <math.h>

int main()
{
    long double f, h, x=0;
    printf("Enter step h -> ");
    scanf("%lf", &h);
    printf("x\tf(x)\n");

    while (x<=3)  {
        if (x<=1.5) {
            f=pow(2, x) - 2 + pow(x, 2);
            printf("%f\t%f\n", x,f);
            }
        else {
            f=sqrt(x)*exp(pow(-x,2));
            printf("%f\t%f\n", x,f); 
            }    
        x=x+h;
        }
    return 0;
}