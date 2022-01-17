/*Define an ADT for Set.
Write C data representation and functions 
for the operations on the Set in a Header file, with
array as the base data structure.
Write a menu-driven main program in a separate file for 
testing the different operations and
include the above header file.*/

#include<stdio.h>
#include<stdlib.h>
#include "set.h"

int main(void)
{
    int i,n = 6;
    int *setTemp;
    int *set;
    setTemp = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        scanf("%d",&setTemp[i]);
    }
    checkCopy(setTemp, &n);
    set = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
        set[i] = setTemp[i];
    }
    //free(setTemp);
    for(i = 0; i < n+1; i++)
    {
        printf("%d\t",setTemp[i]);
    }
    //done ri8 here 
    //change value of n using reference and 
    //malloc another array to store there
}