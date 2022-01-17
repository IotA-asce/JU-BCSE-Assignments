#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void)
{
    char nameString[10], surnameString[15];
    int nameLen, surnameLen, i;
    long long nameInt = 0, surnameInt = 0;
    
    printf("Enter Your first Name : ");
    fflush(stdin);
    gets(nameString);

    printf("Enter Your surname : ");
    fflush(stdin);
    gets(surnameString);

    nameLen = strlen(nameString);
    surnameLen = strlen(surnameString);

    int *nameIntArr;
    nameIntArr = (int *)malloc(nameLen * sizeof(int));
    int *surnameIntArr; 
    surnameIntArr = (int *)malloc(surnameLen * sizeof(int));


    for(i = 0; i < nameLen; i++)
    {
        nameIntArr[i] = nameString[i];
    }

    for ( i = 0; i < surnameLen; i++)
    {
        surnameIntArr[i] = surnameString[i];
    }

    
    for(i = nameLen; i > 0; i--)
    {
        nameInt += (long long)(pow(100,i))*nameIntArr[i];
        printf("\n%lld\n",nameInt);
    }
    
    printf("\n%lld\n",nameInt);

    for(i = surnameLen; i > 0; i--)
    {
        surnameInt += (long long)(pow(100,i))*surnameIntArr[i];
        printf("\n%lld\n",surnameInt);
    }
    
    printf("\n%lld\n",surnameInt);


















    // TESTING SHIT

    puts(nameString);
    puts(surnameString);

    for(i = 0; i < nameLen; i++)
    {
        printf("%d ",nameIntArr[i]);
    }
    printf("\n");

    for ( i = 0; i < surnameLen; i++)
    {
        printf("%d ",surnameIntArr[i]);
    }
    printf("\n");
}