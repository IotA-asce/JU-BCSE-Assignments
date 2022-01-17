#ifndef _A2Q1_POLYNOMIAL_
#define _A2Q1_POLYNOMIAL_
#define SIZE    5000
#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int cursor = 0;
int poly_exp[SIZE];
int poly_coeff[SIZE];

struct PolyIndex
{
    int index_start;
    int index_end;
};

void sub_poly(struct PolyIndex *p1, struct PolyIndex *p2, struct PolyIndex *sub)
{
    int i,j;
    sub->index_start = cursor;
    
    for( i = p1->index_start; i <= p1->index_end; i++ )                          // loop 1 filling in the polynomial_1
    {

        poly_exp[cursor] = poly_exp[i];                     
        poly_coeff[cursor] = poly_coeff[i];
        cursor++;

    }

    sub->index_end = cursor-1;

    int flag = 0;
    // now temp value
    for( j = p2->index_start; j <= p2->index_end; j++ )
    {
        // this is
    }

    sub->index_end = cursor-1;
}

void get_data(struct PolyIndex *p) 
{

    /*
    major changes here are the facts
    1. use a temporary index holder that check the existence of the same index 
    2. if it exists continue
    3. initiate p->start to cursor before and after
    4. the need for a count is absolutely nullified
    5. sort the elements of thhe array
    */

    int tracer = 0;
    int temp_index;
    int temp_coeff;

    p->index_start = cursor;            // initializing the index of the polynomial ds

    while(tracer <= 0)
    {   
    here:
        printf("Enter the index of the polynomial\n");
        scanf("%d",&temp_index);
        if (temp_index == -1)
        {
            printf("data obtained\n");
            tracer++;
        }

        // search the existence of the index below

        for (size_t i = p->index_start; i < cursor; i++)
        {
            if (temp_index == poly_exp[i])
            {
                printf("\nThis exp already exists in the polynomial");
                goto here;
            }
            
        }
        
        poly_exp[cursor] = temp_index;
        printf("\nEnter the coeff of the same :\t");
        scanf("%d",&poly_coeff[cursor]);

        cursor++;

    }

    p->index_end = cursor - 1;

    for (size_t i = p->index_start; i < p->index_end; i++)
    {
        for (size_t j = p->index_start+1; j < p->index_end; j++)
        {
            if (poly_exp[i] < poly_exp[j])
            {
                temp_index = poly_exp[i];
                temp_coeff = poly_coeff[i];

                poly_exp[i] = poly_exp[j];
                poly_coeff[i] = poly_coeff[j];

                poly_exp[j] = temp_index;
                poly_coeff[j] = temp_coeff;
            }
            
        }
        
    }
    
}

void print_data()                                       
{
    int i;
    printf("\nthe array below\n");
    for( i = 0; i < cursor; i++)
    {
        printf("%d\t%d\n",poly_exp[i],poly_coeff[i]);
    }
}

void add_poly(struct PolyIndex *p1, struct PolyIndex *p2, struct PolyIndex *p3)
{
    // here we gotta add the polynomial 
    // conpare the elements of each polynomial and compare the common exp
    // add the rest to the global array
    // use nested for loop here
    
    int i,j;
    p3->index_start = cursor;
    
    for( i = p1->index_start; i <= p1->index_end; i++ )                          // loop 1 filling in the polynomial_1
    {
        /*
        the first polynomial gets filled into the global array 
        the second polynomial is then compared to the individual elements of the 
        resultant polynomial there
        if theres a match in the exponent then the value of the coeff gets updated

        an initaial loop fills up the resultant polynomial with the values of polynomial 1
        a second loop is run which has a nested loop which compares every element of the resultant polynomial
        if match is found then updation takes place and the inner loop is break;
        if not then flag remains 0; 
        */
        
        poly_exp[cursor] = poly_exp[i];                     
        poly_coeff[cursor] = poly_coeff[i];
        cursor++;

    }

    p3->index_end = cursor-1;

    int flag = 0;
    for ( i = p2->index_start; i <= p2->index_end; i++)
    {
        for ( j = p3->index_start; j <= p3->index_end; j++)
        {
            if(poly_exp[i] == poly_exp[j])
            {
                // add the two
                poly_coeff[j] += poly_coeff[i];
                flag++;
            }
        }

        if (flag == 0)
        {
            poly_exp[cursor] = poly_exp[i];
            poly_coeff[cursor] = poly_coeff[i];
            cursor++;
        }
        flag = 0; 
        
    }
    p3->index_end = cursor-1;
    
}


void multiply_poly(struct PolyIndex *p1, struct PolyIndex *p2, struct PolyIndex *p3)
{
 
    // the algorithm will be
    
    // p1 = ax^5 + bx^3 + cx
    // p2 = mx^6 + nx^4 + ox^2
    
    // p1 * p2 = ( ax^5 + bx^3 + cx ) * ( mx^6 + nx^4 + ox^2 )
    // p1 * p2 = ax^5 * ( mx^6 + nx^4 + ox^2 ) 
            // + bx^3 * ( mx^6 + nx^4 + ox^2 )
            // + cx^1 * ( mx^6 + nx^4 + ox^2 );
    
    int i,j;
    int flag = 0;

    int temp_exp;
    int temp_coeff;

    p3->index_start = cursor;

    for ( i = p1->index_start; i <= p1->index_end; i++)
    {
        for ( j = p2->index_start; j <= p2->index_end; j++)
        {
            temp_exp = poly_exp[i] + poly_exp[j];
            temp_coeff = poly_coeff[i] * poly_coeff[j];   
            
            for (size_t x = p3->index_start; x <= cursor; x++)
            {
                if (poly_exp[x] == temp_exp)
                {

                    poly_coeff[x] += temp_coeff;
                    flag++;
                    break;

                }
                 
            }
            if (flag == 0)
            {
                poly_exp[cursor] = temp_exp;
                poly_coeff[cursor] = temp_coeff;
                cursor++;
            }
            flag = 0;
        }
        p3->index_end = cursor-1;
    }
}

void display_poly(struct PolyIndex *p)
{
    int i;
    printf("\n\npolynomial below idk which one\n");
    for( i = p->index_start; i <= p->index_end; i++ )
    {
        printf("%d : : %d\n",poly_exp[i], poly_coeff[i]);
    }
}

#ifdef __cplusplus
}
#endif

#endif