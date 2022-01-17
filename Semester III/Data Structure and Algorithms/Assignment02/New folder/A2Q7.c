#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, matrix3x3[3][3], matrix5x5[5][5];
    int **Matrix;

    printf("Enter the size of the square matrix : ");
    scanf("%d",&n);

    Matrix = (int **)malloc(n*sizeof(int *));
    for ( i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            Matrix[i] = (int *)malloc(sizeof(int));
        }
    }

    for ( i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d\t",Matrix[i][j]);
        }
        printf("\n\n\n");
    }
    

}