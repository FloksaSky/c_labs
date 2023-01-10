#include <stdio.h>
#include <math.h>

int main()
{
    double x, x1, pi = 3.1415926;
    printf("Enter x { 19.8 <= x <= 31.5 } -> ");
    scanf("%lf", &x);
    if (19.8 <= x && x <= 31.5)
    {
        x1=x*pi/180;
        double y = sqrt(sin(2.0*x1)) + sqrt(sin(3.0*x1));
        double z = pow(log(tan(y-pi/8)), 1.0/4.0);
        printf("y(x) = %lf\nz(y) = %lf\n", y, z);
    }
    else
        printf("x value is incorrect!\n");
    return 0;
}