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


// void setAsubB(int setA[], int setB[], int setResult);