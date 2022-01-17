#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int sortCheckAorD(int arrayUnknown[], int c);
void ascendingCheck();
void descendingCheck();

int main(void)
{
    int arrayUnknown[MAX], count = 1, i;
    printf("Enter data :\n");
    for ( i = 0; i < MAX; i++)
    {
        arrayUnknown[i] = i;   
    }

    count = sortCheckAorD(arrayUnknown, count);
    
    switch (count)
    {
    case 2:
        ascendingCheck(arrayUnknown);
        break;
    case 0:
        descendingCheck(arrayUnknown);
        break;
    default:
        break;
    }
}


int sortCheckAorD(int arrayUnknown[], int c)
{
    int i;
    for ( i = 1; i < MAX; i++)
    {
        if (arrayUnknown[i]>=arrayUnknown[i-1])
        {
            c++;
            return c;                           // call function from here
        }
        else if(arrayUnknown[i]<=arrayUnknown[i-1])
        {
            c--;
            return c;
        }
        
    }
    
}

void ascendingCheck(int arrayUk[])
{
    int i, flag = 0;
    for (i = 1; i < MAX; i++)
    {
        if (arrayUk[i]<arrayUk[i-1])
        {
            flag++;
        }
        
    }
    if(flag != 0)
    {
        printf("\nArray not sorted\n");
    }
    else
    {
        printf("\nArray sorted in ascending order\n");
    }
    
}


void descendingCheck(int arrayUk[])
{
    int i, flag = 0;
    for (i = 1; i < MAX; i++)
    {
        if (arrayUk[i]>arrayUk[i-1])
        {
            flag++;
        }
        
    }
    if(flag != 0)
    {
        printf("\nArray not sorted\n");
    }
    else
    {
        printf("\nArray sorted in descending order\n");
    }
}


