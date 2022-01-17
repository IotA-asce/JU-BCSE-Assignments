void checkCopy(int setArr[], int *n)
{
    int i,j,k,flag = 0;
    for(i = 0; i < *n; i++)
    {
        for(j = i+1; j < *n; j++)
        {
            if(setArr[i] == setArr[j])
            {
                flag++;
                for(k = j; k < *n-flag; k++)
                {
                    setArr[k] = setArr[k+1];
                }
                setArr[*n-flag] = '\0';
            }
        }
    }
    *n=*n-flag;
}