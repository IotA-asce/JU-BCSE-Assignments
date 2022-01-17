#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100000

int main(void)
{
    char randomStrings[MAX][10];
    // char randomStrings[10][10];

    randomStrings[0][0] = 'A';
    randomStrings[0][1] = 'A';
    randomStrings[0][2] = 'A';
    randomStrings[0][3] = 'A';
    randomStrings[0][4] = 'A';
    randomStrings[0][5] = 'A';
    randomStrings[0][6] = 'A';
    randomStrings[0][7] = 'A';
    randomStrings[0][8] = 'A';
    randomStrings[0][9] = 'A';

    int i, j;
    int indexCount = 9;
    for (i = 1; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (j == indexCount)
            {
                randomStrings[i][j] = randomStrings[i - 1][j] + 1;
            }
            else
            {
                randomStrings[i][j] = randomStrings[i - 1][j];
            }
        }
    }

    printf("ooo la la la");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%c", randomStrings[i][j]);
        }
        printf("\n");
    }
}