#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROW 20000

int main(void)
{
    FILE *fr;
    fr = fopen("nameroll","r");

    char details[ROW];
    char c;
    char nl = '\n';
    char sp = ' '; 

    int i = 0;
    int j,k,l;

    if (fr == NULL)
    {
        printf("Error accessing file");
        exit(1);
    }

    rewind(fr);
    while(!feof(fr))
    {
        c = getc(fr);
        details[i] = c;
        i++;
    }
    fclose(fr);

    // printf("%d",i);
    int *len;
    len = (int *)malloc(i * sizeof(int));
    char **detArr;
    detArr = (char **)malloc(i*sizeof(char *));
    if (detArr == NULL)
    {
        printf("Error 41\n");
    }
    
    for(j = 0; j < i; j++)
    {
        detArr[i] = (char *)malloc(60*sizeof(char));
        if (detArr[i] == NULL)
        {
            printf("Error %d\n",j+44);
        }
        
    }
    for (j = 0; j < i; j++)
    {
        // puts(detArr[j]);
        printf("%c",details[j]);
    }

    j = 0;
    k = 0;
    l = 0;
    printf("\nline 47\t:\t%d\n",i);
    j=0;
    while (j <= i)
    {
        printf("\n%d\t:\t%d",j,i);
        if(details[j] == nl)
        {
            printf("at j = %d",j);
        }
        j++;
    }
    printf("\nline 58");
}
    