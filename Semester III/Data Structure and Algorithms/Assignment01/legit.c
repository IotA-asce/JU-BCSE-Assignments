#include<stdio.h> 
#include<stdbool.h> 
#include<stdlib.h>
#include<time.h> 
#include<string.h>

#define MAX	100000
int main() 
{ 
  long long n=MAX,i; 
  int d1,d2,d3,d4,d5;
  bool arr[MAX]={0}; 
  long long array[MAX],p;
  FILE *filePointer;
  filePointer = fopen("text.txt","w");
  time_t t; 
  srand((unsigned)time(&t)); 
  // for(i=0;i<n;++i) 
  // { 
  //   int d1=rand()%10;
	//   int d2=rand()%10;
	//   int d3=rand()%10;
	//   int d4=rand()%10;
	//   int d5=rand()%10; 
	//   long long r = d1+(d2*10)+(d3*100)+(d4*1000)+(d5*10000);
    // if(!arr[r])
    {
		  array[i]=r;
    	printf("%d\t%d\n",i,r); 	
    }
	  // else 
      // i--; 
    // arr[r]=1;     
  
  for(i=0;i<MAX;i++){
  	fprintf(filePointer,"%d",array[i]);
  	fprintf(filePointer,"\n");
  	// p=i%10;
  	// if(p==0){
  	// 	fprintf(filePointer,"\n");
	  // }
	}
	//	fwrite("\n",filePointer);
  fclose(filePointer);
}
} 
