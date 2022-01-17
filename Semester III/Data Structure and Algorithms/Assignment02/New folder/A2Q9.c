#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define SIZE2 20
    
void compare();

int main(void)
{
    int array1[SIZE],array2[SIZE],i,j,k = 1;
    int catenatedArray[SIZE2];
    
    for (i = 0; i < SIZE; i++)
    {
        array1[i] = i+3+k;
        k = k + 2;
        //i++;
    }

    for (i = 0; i < SIZE; i++)
    {
        array2[i] = i+6;
    }

    for ( i = 0; i < SIZE; i++)
    {
        printf("%d\t",array1[i]);
    }
    printf("\n");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%d\t",array2[i]);
    }
    

    
}