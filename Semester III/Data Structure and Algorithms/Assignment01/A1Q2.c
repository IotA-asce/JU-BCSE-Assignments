#include<stdio.h>
#include<stdlib.h>

int fibInt(int n) 
{ 
   if (n <= 1) 
      return n; 
   return fibInt(n-1) + fibInt(n-2); 
}

long fibLong(long n)
{
    if(n <= 1)
        return n;
    return fibLong(n-1) + fibLong(n-2);
}

int main(void)
{
    int n, choice = 0;
    // printf("Enter the positional element no :: ");
    // scanf("%d",&n);

    printf("Enter the choice no :: \n0 : for iterative\n1 : for recursive\nChoice : ");
    scanf("%d",&choice);

    long long arrayForGraph[50];

    int i, j, fiboItrrInt, fiboRecrInt;
    int termInt01 = 0, termInt02 = 1;

    long long k, l, fiboItrrLong, fiboRecrLong;
    long long termLong01, termLong02;

    switch(choice)
    {   
        case 0:
            for ( i = 1; i <= 50; i++)
            {
                termInt01 = 0;
                termInt02 = 1;

                termLong01 = 0;
                termLong02 = 1;

                n = i;

                if(n == 1)
                {
                    fiboItrrInt = 0;
                    fiboItrrLong = 0;
                }
                else if (n == 2)
                {
                    fiboItrrInt = 1;
                    fiboItrrLong = 1;
                }
                else if (n > 2)
                {
                    for(j = 2; j < n; j++)
                    {
                        fiboItrrInt = termInt01 + termInt02;
                        termInt01 = termInt02;
                        termInt02 = fiboItrrInt;

                        fiboItrrLong = termLong01 + termLong02;
                        termLong01 = termLong02;
                        termLong02 = fiboItrrLong;
                    }
                }
                printf("\nFibonacci series Element n in iteration %d : int : %d\t::\tlong : %lld", i, fiboItrrInt, fiboItrrLong);
                arrayForGraph[i-1] = fiboItrrLong;
            }
            break;
    
        case 2:   

            for(i = 1; i <= 50; i++)
            {
                n = i;

                termInt01 = 0;
                termInt02 = 1;  

                termLong01 = 0;
                termLong02 = 1;

                if(n == 1)
                {
                    fiboRecrInt = 0;
                    fiboRecrLong = 0;
                }
                else if (n == 2)
                {
                    fiboRecrInt = 1;
                    fiboRecrLong = 1;
                }
                else
                {
                    n -= 1;
                    fiboRecrInt = fibInt(n);
                    fiboRecrLong = fibLong(n); 
                }

            printf("\nFibonacci series Element %d : int : %d\t:: long : %lld :", i, fiboRecrInt, fiboRecrLong);
            
            }
            break;   
    }
}