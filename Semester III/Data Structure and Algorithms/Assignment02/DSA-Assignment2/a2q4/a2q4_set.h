#ifndef _A2Q4_SET_
#define _A2Q4_SET_

#ifdef __cplusplus
extern "C" {
#endif

void setFiter( int set[], int * count )
{
    int i;
    int j;
    int k;
    for ( i = 0; i <= *count; i++)
    {
        for ( j = i+1; j < *count;)
        {
            if (set[j] == set[i])
            {
               for ( k = j; k < *count; k++)
               {
                   set[k] = set[k+1];
               }
               --*count;
            }
            else
            {
                j++;
            }   
        }   
    } 
}

int setIntersection(int set1[], int set2[], int setOut[], int count1, int count2)
{
    int k = 0;
    int i,j;

    for ( i = 0; i < count1; i++)
    {
        for ( j = 0; j < count2; j++)
        {
            if (set1[i] == set2[j])
            {
                setOut[k] = set1[i];
                k++;
            }   
        }   
    }
    return k;
}

int setUnion(int set1[], int set2[], int setOut[], int count1, int count2)
{
    int k = 0;
    int l = 0;
    int countUnion;
    while (k != (count1 + count2))
    {
        if (k < count1)
        {
            setOut[k] = set1[k];
            k++;
        }
        else
        {
            setOut[k] = set2[l];
            l++;
            k++;
        }  
    }
    countUnion = count1 + count2;
    setFiter(setOut, &countUnion);
    return countUnion;
}

void getSet(int set[], int *count)
{
    printf("Enter the no of elements for set : ");
    scanf("%d",count);

    int i;

    printf("Enter elements for set : \n");
    for ( i = 0; i < *count; i++)
    {
        printf("Enter element no %d : ",i+1);
        scanf("%d",&set[i]);
    }
}

void displaySet(int set[], int *count)
{
    printf("\nThe elements goes as below\n\n");
    int i;
    for ( i = 0; i < *count; i++)
    {
        printf("%d\t",set[i]);
    }
    
}

void setAsubB(int setA[], int setB[], int countA, int countB, int setResult[],int *countR)
{
    int i;
    int j;
    int flag = 0;
    *countR = 0;

    /*
        here we are storing the substrand of A - B in setResult pre declared
        in the main() function
        countA is for setA
        countB is for SetB
        and countR is for setResult
        poniter used here removing the need for returning a certain value
    */

    for (size_t i = 0; i < countA; i++)
    {
        for (size_t j = 0; j < countB; j++)
        {
            // printf("%d",flag);
            if ( setA[i] == setB[j] )
            {
                flag++;
                printf("\ncaught %d\n",setA[i]);
            }
            
        }
        if (flag != 0)      
        {
            flag = 0;
            continue;            
        }
        
        if (flag == 0);     
        {
            setResult[*countR] = setA[i];
            ++*countR;
        }

    }
    
}


#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /* _A2Q4_SET_ */