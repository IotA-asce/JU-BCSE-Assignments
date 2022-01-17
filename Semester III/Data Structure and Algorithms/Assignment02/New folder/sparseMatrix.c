#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include<stdint.h>

int main()
{
    int matrix[3][3];

    printf("%td", PTRDIFF_MIN);

    int i;
    int j;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("Enter element no %d %d : ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
        
    }

    int countNonZero = 0;
    int countZero = 0;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
            {
                countZero++;
            }
            else if (matrix[i][j] != 0)
            {
                countNonZero++;
            }
            
        }
        
    }

    printf("Non-zero elements : %d",countNonZero);
    printf("Zero elements : %d",countZero);
    printf("\n\n");

    if (countNonZero > countZero)
    {
        printf("Case is sparse matrix");

    }
    else if (countNonZero <= countZero)
    {
        printf("Case is non-sparse matrix\n");

        // sparse matrix creation
        // row    __
        // column __        
        // value  __

        int **sparseMatrix;
        sparseMatrix = (int **)malloc(3 * sizeof(int *));
        for ( i = 0; i < 3; i++)
        {
            sparseMatrix[i] = (int *)malloc(countNonZero * sizeof(int));
        }

        i = 0;
        j = 0;
        int k = 0;
        
        for ( i = 0; i < 3; i++)
        {
            for ( j = 0; j < 3; j++)
            {
                if (matrix[i][j] != 0)
                {
                    sparseMatrix[0][k] = i;
                    sparseMatrix[1][k] = j;
                    sparseMatrix[2][k] = matrix[i][j];
                    k++;
                }
                
            }
            
        }

        for ( i = 0; i < countNonZero; i++)
        {
            printf("%d\t", sparseMatrix[0][i]);
        }

        printf("\n");

        for ( i = 0; i < countNonZero; i++)
        {
            printf("%d\t", sparseMatrix[1][i]);
        }

        printf("\n");

        for ( i = 0; i < countNonZero; i++)
        {
            printf("%d\t", sparseMatrix[2][i]);
        }

    }

}



/*
multiplication operation algorithm below

a   b   c         1   2   3        a-1 + b-4 + c-7      a-2 + b-5 + c-8      a-3 + b-6 + c-9

d   e   f    X    4   5   6   =    d-1 + e-4 + f-7      d-2 + e-4 + f-8      d-3 + e-6 + f-9

g   h   i         7   8   9        g-1 + h-4 + i-7      g-2 + h-4 + i-8      g-3 + h-6 + f-9


use keymap for the process of mapping the multiplication

a + 1

for i in range 0-5  
    if sparseMatrix[i][j] != 0;
    search for similar i and j in sparse matrix 2 and if not fount temp = 0;
    3rd matrix  = similar add the elements here

    after adding remember the positiona and add the next elemnt after 
    storing the elements here we go guys

    the eleements 
    are as follows 
    as per the multipluication part its pretty complex and we dont wanna screw it up 
    for transpose lets see

    1-1,1     2-2,2     3-3,3             1-1,1       4-2       7-3
    4-4,4     5-5,5     6-6,6     T   =   2-4       5-5       8-6
    7-7,7     8-8,8     9-9,9             3-7       6-8       9-9

*/

// now again create header file for matrix operation
// list of operations on a sparse matrix
// 1. sparse matrix addition
// 2. transpose
// 3. multiplication
// 3. this is getting tough now real tough and i dont know how it will be 
// what its gonna be dude
// how am i gonna do this good i mean any good from now
// this is good 
// now to get this now
// 
