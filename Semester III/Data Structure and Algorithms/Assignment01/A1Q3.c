#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sortArrayInt(int arr[], int count)
{
    int i, j;
    for(i = 0; i < count; i++)
    {
        for (j = 1; j < count; j++)
        {
            if(arr[j-1] > arr[j])
            {
                arr[j-1] = arr[j-1] + arr[j];
                arr[j] = arr[j-1]-arr[j];
                arr[j-1] = arr[j-1]-arr[j];
            }
        }
        
    }
}

void sortArrayString(char ***arr, int count)
{
    int i, j;
    for(i = 0; i < count; i++)
    {
        for (j = 1; j < count; j++)
        {
            if(arr[j-1] > arr[j])
            {
                char temp[10];
                strcpy(temp,arr[j]);
                strcpy(arr[j],arr[j-1]);
                strcpy(arr[j-1],temp);
            }
        }
        
    }
}


void sortArrayFloat(float arr[], int count)
{
    int i, j;
    for(i = 0; i < count; i++)
    {
        for (j = 1; j < count; j++)
        {
            if(arr[j-1] > arr[j])
            {
                arr[j-1] = arr[j-1] + arr[j];
                arr[j] = arr[j-1]-arr[j];
                arr[j-1] = arr[j-1]-arr[j];
            }
        }
        
    }
}

void linearSearchInt(int arrL[], int c, int searchElementInt)
{
    int i, flag = 0;
    for ( i = 0; i < c; i++)
    {
        if(searchElementInt == arrL[i])
        {
            flag++;
        }
    }
    switch (flag)
    {
    case 0:
        printf("\nSearch Element does not exist in the array\n\n");
        exit(0);
        break;
    
    default:
        printf("\nSearch element found! Exists within the array\n\n");
        exit(0);
        break;
    }
    
}

void linearSearchFloat(float arrL[], int c, float searchElementFloat)
{
    int i, flag = 0;
    for ( i = 0; i < c; i++)
    {
        if(searchElementFloat == arrL[i])
        {
            flag++;
        }
    }
    switch (flag)
    {
    case 0:
        printf("\nSearch Element does not exist in the array\n\n");
        exit(0);
        break;
    
    default:
        printf("\nSearch element found! Exists within the array\n\n");
        exit(0);
        break;
    }
    
}

void linearSearchChar(char ***arr, int c, char *searchChar)
{
    int i, flag = 0;
    for ( i = 0; i < c; i++)
    {
        if(strcmp(searchChar,arr) == 0)
        {
            flag++;
        }
    }
    switch (flag)
    {
    case 0:
        printf("\nSearch Element does not exist in the array\n\n");
        exit(0);
        break;
    
    default:
        printf("\nSearch element found! Exists within the array\n\n");
        exit(0);
        break;
    }
    
}

void binarySearchInt(int arrB[], int first, int last, int searchElementInt)
{
    if(last > first){
        int middle = (first + last)/2;
        if(searchElementInt == arrB[middle])
        {
            printf("\nElement found successfully\n\n");
            exit(0);
        }
        else if(searchElementInt > arrB[middle])
        {
            binarySearchInt(arrB, middle, last, searchElementInt);
        }
        else if(searchElementInt < arrB[middle])
        {
            binarySearchInt(arrB, first, middle, searchElementInt);
        }
    }
    else if (last == first && searchElementInt != arrB[first])
    {   

        printf("Element not found \n\n");
        exit(0);    
    }
}

void binarySearchFloat(float arrB[], int first, int last, float searchElementfloat)
{
    if(last > first){
        int middle = (first + last)/2;
        if(searchElementfloat == arrB[middle])
        {
            printf("\nElement found successfully\n\n");
            exit(0);
        }
        else if(searchElementfloat > arrB[middle])
        {
            binarySearchFloat(arrB, middle, last, searchElementfloat);
        }
        else if(searchElementfloat < arrB[middle])
        {
            binarySearchFloat(arrB, first, middle, searchElementfloat);
        }
    }
    else if (last == first && searchElementfloat != arrB[first])
    {   

        printf("Element not found \n\n");
        exit(0);    
    }
}


int main(void)
{
    int *integerArray;
    float *floatArray;
    char **charArray;
    int count, i, searchElementInt, choice, choiceType, flag = 0;
    float searchElementFLoat;
    char tempChar[10];

    printf("Enter the choice type :\n1 = int array\n2 =float array\n3 = string\n");
    scanf("%d",&choiceType);

    switch(choiceType)
    {
        case 1:
            printf("Enter the number of elements : ");
            scanf("%d",&count);

            integerArray = (int *)malloc(count * sizeof(int));

            for(i = 0; i < count; i++)
            {
                printf("Enter element no %d : ",i+1);
                scanf("%d",&integerArray[i]);
            }
            sortArrayInt(integerArray, count);

            printf("Enter the number you wanna search : ");
            scanf("%d",&searchElementInt);
            printf("enter search choice :\n0 = linear\n1 = binary\n");
            scanf("%d",&choice);
            switch (choice)
            {
                case 0:
                    linearSearchInt(integerArray, count, searchElementInt);
                    break;
    
                case 1:
                    binarySearchInt(integerArray, 0, count, searchElementInt);
                    break;

                default:
                    printf("choice not valid\n\n");
                    break;
            }        
            break;

        case 2:
            printf("Enter the number of elements : ");
            scanf("%d",&count);

            floatArray = (float *)malloc(count * sizeof(float));

            for(i = 0; i < count; i++)
            {
                printf("Enter element no %d : ",i+1);
                scanf("%f",&floatArray[i]);
            }
            sortArrayFloat(floatArray, count);

            printf("Enter the number you wanna search : ");
            scanf("%f",&searchElementFLoat);
            printf("enter search choice :\n0 = linear\n1 = binary\n");
            scanf("%d",&choice);
            switch (choice)
            {
                case 0:
                    linearSearchFloat(floatArray, count, searchElementFLoat);
                    break;
    
                case 1:
                    binarySearchFloat(floatArray, 0, count, searchElementFLoat);
                    break;

                default:
                    printf("choice not valid\n\n");
                    break;
            }        
            break;
        case 3:
            printf("Enter the number of elements : ");
            scanf("%d",&count);

            charArray = (int **)malloc(count * sizeof(char *));
            for ( i = 0; i < count; i++)
            {
                charArray[i] = (char *)malloc(10 * sizeof(char));
            }
            

            for(i = 0; i < count; i++)
            {
                printf("Enter element no %d : ",i+1);
                fflush(stdin);
                gets(charArray[i]);
            }
            sortArrayChar(charArray, count);

            printf("Enter the number you wanna search : ");
            fflush(stdin);
            gets(tempChar);

            printf("enter search choice :\n0 = linear\n1 = binary\n");
            scanf("%d",&choice);
            switch (choice)
            {
                case 0:
                    linearSearchInt(charArray, count, tempChar);
                    break;
    
                case 1:
                    binarySearchInt(charArray, 0, count, tempChar);
                    break;

                default:
                    printf("choice not valid\n\n");
                    break;
            }        
            break;


        default:
            printf("\n\nSelected choice not valid\n");
            exit(0);
            break;
    }
    

}