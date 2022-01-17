/*
7. Write an application for adding, subtracting and multiplying 
very large numbers, say more than 70-digit integers,using 
(a) arrays and 
(b) linked liststo represent the large integers
*/

#include<stdio.h>

int large_no_1[100];
int large_no_2[100];
int large_no_add[200];
void temp_add(int a[], int b[]);
void print_number(int a[]);

int main(void)
{
    int i, j;
    
    // first number in 
    int index = 1;

    printf("Enter the first number :\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d index =\t",index);
        scanf("%d",large_no_1+i);
        index *= 10;
    }
    index = 1;

    printf("\nEnter the second number :\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d index =\t",index);
        scanf("%d",large_no_2+i);
        index *= 10;
    }

    temp_add(large_no_1,large_no_2);

    return 0;
}

void print_number(int a[])
{
    int i;
    for ( i = 0; i < 6; i++)
    {
        printf("%d",large_no_add[i]);
    }
    
}

void temp_add(int a[], int b[])
{
    int i;
    int temp;
    for ( i = 0; i < 5; i++)
    {
        temp = a[i] + b[i];
        large_no_add[i] += temp%10;
        temp = temp/10;
        large_no_add[i+1] = temp;
    }
    
}