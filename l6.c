#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void IndexesOfSame(int* arr, int n, int* first_index, int* second_index) {
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(arr[i] == arr[j]) {
                *first_index = i;
                *second_index = j;
                return;
            }
        }
    }
    *first_index = -1;
    *second_index = -1;
}
 
int Sum(int* arr, int from, int to) {
    int sum = 0;
    for(int i = from + 1; i < to; ++i) {
        sum += arr[i];
    }
    return sum;
}
 
int Mult(int* arr, int from, int to) {
    int mult = 1;
    for(int i = from + 1; i < to; ++i) {
        mult *= arr[i];
    }
    return mult;
}
 
void Procced(int*arr, int n) {
    int first_index = 0;
    int second_index = 0;
    IndexesOfSame(arr, n, &first_index, &second_index);
    int sum = Sum(arr, first_index, second_index);
    int mult = Mult(arr, first_index, second_index);
    arr[first_index] = sum;
    arr[second_index] = mult;
}
 
int* CreateArr(int n) {
    int* arr = calloc(n, sizeof(int));
    for(int i = 0; i < n; ++i) {
        arr[i] = rand() % 10 + 1;
    }
    return arr;
}
 
void PrintArr(int* arr, int n) {
    for(int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}
 
int main()
{
    srand(time(NULL));
    printf("Insert n\n");
    int n;
    scanf("%d", &n);
    int* arr = CreateArr(n);
    PrintArr(arr, n);
    printf("\n");
    Procced(arr, n);
    PrintArr(arr, n);
    free(arr);
    return 0;
}