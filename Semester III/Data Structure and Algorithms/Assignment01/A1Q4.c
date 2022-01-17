#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

#define MAX 100000

int main(void)
{
    int i,j;
    long long randomInts[MAX],randomIndex,randomTemp,x = 1;
    time_t t; 
    srand((unsigned)time(&t));
    FILE *filePointer;
    filePointer = fopen("RandomInteger.txt", "w");

    for(i = 0; i < MAX; i++)
    {
        randomInts[i] = i+1;
    } 
   
    for(i = 0; i < MAX; i++){
       
        int d1=rand()%10;
	    int d2=rand()%10;
        int d3=rand()%10;
	    int d4=rand()%10;
	    int d5=rand()%10; 
	    randomIndex = d1+(d2*10)+(d3*100)+(d4*1000)+(d5*10000);
        
        randomTemp = randomInts[i];
        randomInts[i] = randomInts[randomIndex];
        randomInts[randomIndex] = randomTemp;

        printf("%d\t::\t%ld\n",i,randomInts[i]);
    }
    for(i=0;i<MAX;i++)
    {
  	    fprintf(filePointer,"%d",randomInts[i]);
  	    fprintf(filePointer,"\n");
	}

    fclose(filePointer);
}