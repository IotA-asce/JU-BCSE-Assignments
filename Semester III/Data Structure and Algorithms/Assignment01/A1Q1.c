#include<stdio.h>
#include<stdlib.h>

int factorRecrInt(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return n * factorRecrInt(n -1);
}

long long factRecrLong(long long n)
{
    if(n == 0)
    {
        return 1;
    }

    return n * factRecrLong(n - 1);
}

int factorIttrInt(int n)
{
    int factorialHolder = 1,i;
    for(i = 2; i <= n; i++)
    {
        factorialHolder *= i;
    }
    return factorialHolder;
}

long long factorialIttrlong(long long n)
{
    long long factorialH0lder, i;
    for ( i = 2; i <= n; i++)
    {
        factorialH0lder *= i;
    }
    return factorialH0lder;
    
}

int main()
{   
    int intRecrHolder, intIttrHolder, i, j, choice = 0;
    long long longRecrHolder, longIttrHolder;

    printf("Enter the choice ::\n 1 for recursive approach ::\n 2 for itterative approach :: \n");
    scanf("%d",&choice);
    system("cls");
    switch (choice)
    {
    case 1:
        for(i = 1; i <= 50; i++)
        {   
            intRecrHolder = i;
            longRecrHolder = i;

            intRecrHolder = factorRecrInt(intRecrHolder);
            longRecrHolder = factRecrLong(longRecrHolder);

            printf("\n%d\t:\t%d\t::\t%lld", i, intRecrHolder, longRecrHolder);
        }
        break;
    
    case 2:
        for(i = 1; i <= 50; i++)
        {   
            intIttrHolder = i;
            longRecrHolder = i;

            intIttrHolder = factorIttrInt(intIttrHolder);
            longIttrHolder = factorialIttrlong(longIttrHolder);
            printf("\n%d\t:\t%d\t::\t%lld", i, intIttrHolder, longIttrHolder);
        }
        break;

    default:
        printf("\nEnter the valid choice");
        break;
    }
    
}