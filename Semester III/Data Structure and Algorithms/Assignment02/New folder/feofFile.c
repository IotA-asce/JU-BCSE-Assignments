#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char c;
    FILE *in, *out;

    in = fopen("test", "r");
    out = fopen("file","w");
    
    if (in == NULL)
    {
        printf("Error");
        exit(1);
    }
    if (out == NULL)
    {
        printf("Error");
        exit(1);
    }
    

    while(!feof(in))
    {
        c = getc(in);
        if(!feof(in))
        {
            putc(c,out);
        }

    }
    fclose(in);
    fclose(out);

    return 0;
}