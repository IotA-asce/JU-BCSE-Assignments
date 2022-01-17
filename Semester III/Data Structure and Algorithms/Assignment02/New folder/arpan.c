#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct element{
int value,row,column;
};
void creatematrix(struct element**p,int*a,int*b,int*c){
int count=0;
printf("\n enter the no. of row and column of the matrix:");
scanf("%d %d",b,c);
printf("\n enter the no. of nonzero element:");
scanf("%d",a);
if((a)>(*b)(*c)){
    printf("\n wrong input \n");
    return 0;
}
struct element*e;
e=(struct element*)malloc((a)(sizeof(struct element)));
for(int i=0;i<*a;i++){
    count=0;
    printf("\n enter element no. %d:\n",i+1);
    printf("\n enter position of the element:\n");
    printf("\n enter row:");
    scanf("%d",&e[i].row);
    if(e[i].row>*b){
        printf("\n wrong input\n");
        i--;
        count++;
    }
    if(count==0){
        printf("\n enter column:");
        scanf("%d",&e[i].column);
            if(e[i].column>*c){
                printf("\n wrong input\n");
                i--;
                count++;
            }
    }
    if(count==0){
        for(int j=0;j<i;j++){
            if(e[i].row==e[j].row&&e[i].column==e[j].column){
                printf("\n duplicate\n");
                count++;
                i--;
                break;
            }
        }
    }
    if(count==0){
    printf("\n enter the value:");
    scanf("%d",&e[i].value);
    }
}
p=&e;
}
void printmatrix(struct element**p,int *a,int*b,int*c){
    int count=0,s=0;
    struct element *e;
    e=*p;
printf("\n MATRIX:\n");
for(int i=0;i<*b;i++){
    for(int j=0;j<*c;j++){
            count=0;
            for(int k=0;k<*a;k++){
                    if(e[k].row==i+1&&e[k].column==j+1){
                        printf("\t%d",e[k].value);
                        count++;
                        break;
                    }
            }
            if(count==0){
                printf("\t%d",s);
            }
    }
    printf("\n");
}
}
void printtranspose(struct element*e,int*a,int*b,int*c){
int s=0,count=0;
printf("\nTRANSPOSE MATRIX:\n");
for(int i=0;i<*c;i++){
    for(int j=0;j<*b;j++){
            count=0;
            for(int k=0;k<*a;k++){
                    if(e[k].column==i+1&&e[k].row==j+1){
                        printf("\t%d",e[k].value);
                        count++;
                        break;
                    }
            }
            if(count==0){
                printf("\t%d",s);
            }
    }
    printf("\n");
}
}
void main(){
    struct element **p;
    int a,b,c;
creatematrix(p,&a,&b,&c);
printf("\n%d",a);
printf("\n%d",b);
printf("\n%d",c);
printmatrix(p,&a,&b,&c);

}