#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    int A[10][10];
    int B[10];
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            A[i][j] = rand() % 20 - 10;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        int max = A[i][0];
        for (j = 0; j < 10; j++)
        {
            if (abs(A[i][j]) > abs(max))
            {
                max = A[i][j];
            }
        }
        B[i] = max;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
    return 0;
}