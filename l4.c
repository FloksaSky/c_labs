#include <stdio.h>
#include <math.h>
 
int main()
{
    long double a, b, f, e, h, s=0, dn=0, s1=0, x=0, i=0;
    int n=2;
    printf("Enter precision e -> ");
    scanf("%Lf", &e);
    a=0;
    b=M_PI;
    h=M_PI/n;

    long double I(int n) {
        for (i=0; i<=n-1; i++) {
            x=a+i*h;
            if (x<=1.57)
                f=pow(2, x+h/2) - 2 + pow(x+h/2, 2);
            else {
                if (x<=3.14)
                    f=sqrt(x+h/2)*exp(pow(-(x+h/2),2));
            s=s+f;
            }
        s=s*h;
        }
    }
    
    for (i=0; i<=(2*n); i++) {
        x=a+i*h;
        if (x<=1.57)
            f=pow(2, x+h/2) - 2 + pow(x+h/2, 2);
        else {
            if (x<=3.14)
                f=sqrt(x+h/2)*exp(pow(-(x+h/2),2));
        s1=s1+f;
        }
    }
    s1=s1*h;
 
    dn=(s1-s)/3
    if (dn>=e) {
        n=2*n
    }