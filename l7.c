#include <stdio.h>

void fill(int n, int m, int a[n][m])
{
    int i, j;
    for (i = 0; i < n; i++) 
        for (j=0; j<m; j++) 
            a[i][j] = rand () % 11;
    
    
}


void Vivod(int n, int m, int A[n][m])
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j=0; j<m; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
}


int Transpose(int n, int m,  int A[n][m], int A1[m][n])
{
    int i, j;
    for (i = 0; i < n+abs(n-m); i++) {
        for (j=0; j<m+abs(n-m); j++)
            A1[i][j]=A[j][i];
    
        printf("\n");
    }
    return A1[m][n];
}


void Proiz(int n, int m, int n_min,int A[n][m], int A1[m][n], int P[n_min][n_min])
{
    int i, j, r=0;
    
    
    int B[n_min][n_min];
    

    for (i = 0; i<n; i++) 
    {   
        
        for (j=0; j<m; j++){
            r+=A[i][j] * A1[j][i];
            }
        B[i][j]=r;
       
    }

    
}





int main()
{
    int n, m; 
    printf("Vvedite n -> ");
    scanf("%d", &n);
    printf("Vvedite m -> ");
    scanf("%d", &m);
    int A[n][m], A1[m][n];
    fill(n, m, A);
    printf("Matrix A\n");
    Vivod(n,m,A);
    Transpose(n,m,A,A1);
    printf("Matrix A (transrose)\n");
    Vivod(m,n,A1);

    int n_min;
    if (n < m) {
        n_min = n;
    } else {
        n_min = m;
     }
    int P[n_min][n_min];

    
    Proiz(n,m,n_min,A,A1,P);
    printf("Proizvedenie \n");
    Vivod(n_min,n_min,P);
    
}





