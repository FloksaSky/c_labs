#include <stdio.h>
#include <math.h>
 
int main()
{
    float a, b, x,v;
    printf("Enter a -> ");
    scanf("%f", &a);
    printf("Enter b -> ");
    scanf("%f", &b);
    printf("Enter x -> ");
    scanf("%f", &x);
 
    if (a+b<x) 
        {v=(a+b)/x;
        printf("%.3f", v);}
    if (a+b>x)
        {v=x/(a+b);
        printf("%.3f",v);}
    else {
        v=b/x;
        printf("%.3f", v);}
}