#include<stdio.h>

#define MAX_DEGREE 101                      

struct polynomial
{
    // int degree;
    int count;
    float coeff[MAX_DEGREE];
    int exp[MAX_DEGREE];

    /*
    polynomial stored in two arrays one holding the indices 
    with non-zero coeff and the second holding coeff of the same
    */
};

void getData(struct polynomial *p);
void addPolynomial(struct polynomial *p1, struct polynomial *p2, struct polynomial *addResult);
void showPolynomial(struct polynomial *p);

int main(void)
{
    struct polynomial p1,p2,result; 

    int choice;                         // user gets to select a choice
    int trace = 0;

    // major changes here               
    // to make it menu driven i would have to make major changes regarding the declaration
    // of each polynmomial ds

    getData(&p1);
    getData(&p2);

    addPolynomial(&p1,&p2,&result);
    
    showPolynomial(&p1);
    showPolynomial(&p2);
    printf("\n\n\n\n");
    showPolynomial(&result);
}

void getData(struct polynomial *p)
{
    // printf("Enter degree of polynomial : ");
    printf("Start entering the indices and coeff of the polynomial \nindex < 0 will terminate input to the polynomial\n");
    int i = 0, tempIndex;

    while (i >= 0)                                          // okey so here i think i need to do some changes related to inout
    {                                                       // the fact that the duplicate may exist must be eliminated
        printf("Enter exp : ");
        scanf("%d",&tempIndex);
        if (tempIndex < 0)
        {
            break;
        }
        p->exp[i] = tempIndex;
        printf("Enter coeff : ");
        scanf("%f",&p->coeff[i]);
        i++;
    }

    p->count = i;
    
}

void addPolynomial(struct polynomial *p1, struct polynomial *p2, struct polynomial *resultP)
{

    int k = 0;
    for (size_t i = 0; i < p1->count; i++)
    {
        for (size_t j = 0; j < p2->count; j++)
        {
            if (p1->exp[i] == p2->exp[j])
            {
                resultP->exp[k] = p1->exp[i];
                resultP->coeff[k] = p1->coeff[i] + p2->coeff[j];
                k++;
            }
            
        }
            
   }

   for (size_t i = 0; i < p1->count; i++)
   {
       for (size_t j = 0; j < k; j++)
       {
           if (p1->exp[i] != resultP->exp[j])
           {
               resultP->exp[k] = p1->exp[i];
               resultP->coeff[k]= p1->coeff[i];
               k++;
           }
           
       }
       
   }
   
   for (size_t i = 0; i < p2->count; i++)
   {
       for (size_t j = 0; j < k; j++)
       {
           if (p2->exp[i] != resultP->exp[j])
           {
               resultP->exp[k] = p2->exp[i];
               resultP->coeff[k]= p2->coeff[i];
               k++;
           }
           
       }
       
   }
    resultP->count = k;
}

void showPolynomial(struct polynomial *p)
{
    for (size_t i = 0; i < p->count; i++)
    {
        printf("X^%d : ",p->exp[i]);
        printf("%f\n",p->coeff[i]);
    }
    
}