//1013
//1069
#include<stdio.h>

// #define lwLt 1000000
// #define upLt 10000000

int main(void)
{
    long upLt = 10000000, lwLt = 1000000,L[90000000];
    long P = 1069,i;

    for(i = lwLt; i < upLt; i++)
    {
        L[i] = lwLt;
    }
    for(i = lwLt; i < upLt; i++)
    {
        printf("%ld\t::\t%ld\n",i,L[i]);
    }
}