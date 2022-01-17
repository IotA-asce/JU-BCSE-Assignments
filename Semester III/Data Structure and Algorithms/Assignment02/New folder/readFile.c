#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char c;
    char cod[50];
    int k = 1, i;
    fp = fopen("test","r");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    c = getc(fp);
    cod[0] = c;
    while (c != EOF)
    {
        putchar(c);
        printf("\n");
        c = getc(fp);
        cod[k] = c;
        k++;
    }

    fclose(fp);

    return 0;
}