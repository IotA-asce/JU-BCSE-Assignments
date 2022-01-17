#include<stdio.h>

#define SIZE    5000

int cursor = 0;
int poly_exp[SIZE];
int poly_coeff[SIZE];

struct PolyIndex
{
    int index_start;
    int index_end;
};

void print_data();
void get_data(struct PolyIndex *p);
void add_poly(struct PolyIndex *p1, struct PolyIndex *p2, struct PolyIndex *p3);
void multiply_poly(struct PolyIndex *p1, struct PolyIndex *p2, struct PolyIndex *p3);
// void sub_poly(struct PolyIndex *p1, struct PolyIndex *p2, struct PolyIndex *sub);           // this algo has serious consequences work at your own risk
void display_poly(struct PolyIndex *p);
// void multiply_poly(struct PolyIndex *p1, struct PolyIndex *p2, struct PolyIndex *p3);

int main(void)
{
    struct PolyIndex p1,p2,p3,p4,sub; 
    // int tracer
    int choice;  

    while (choice >= 0)
    {
        printf("Enter your choice here \n");
        printf("\nChoice 1 : getdata to polynomial 1");
        printf("\nchoice 2 : getdata to polynomial 2");
        printf("\nChoice 3 : add the two polynomials");
        printf("\nChoice 4 : multiply the polynomials");
        printf("\nChoice 5 : show polynomial 1");
        printf("\nchoice 6 : show polynomial 2");
        printf("\nChoice 7 : show result of addition");
        printf("\nChoice 8 : show result of multiplication");
        printf("\nChoice -1: exit menu");

        switch (choice)
        {
        case 1:
            printf("\nEnter polynomial 1 :\n");
            get_data(&p1);

            break;

        case 2:
            printf("\nEnter polynomial 2 :\n");
            get_data(&p2);

            break;

        case 3:
            printf("\nAddition initiated :\n");
            add_poly(&p1,&p2,&p3);

            break;

        case 4:
            printf("\nMultiplication initiated :\n");
            multiply_poly(&p1,&p2,&p4);

            break;

        case 5:
            printf("\npolynomial 1 below :\n");
            display_poly(&p1);

            break;

        case 6:
            printf("\nPolynomial 2 below :\n");
            display_poly(&p2);
        
            break;

        case 7:
            printf("\nResultant polynomial after addition :\n");
            display_poly(&p3);
            
            break;

        case 8:
            printf("\nResultant polynomial after multiplication :\n");
            display_poly(&p4);

            break;

        case -1:
            printf("\nExit initiated\n");
            break;
        
        default:
            break;
        }

    }

    
    // display_poly(&p2);
    // display_poly(&p3);
    // display_poly(&p4);
    // print_data();
}

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

void get_data(struct PolyIndex *p) // presently the only part thats broken is this 
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
    
    /*int count = 3;
    int i = 0;
    int demi = 7;                       // this variable was provided so as to get a different inout for each polynomial
    
    p->index_start = cursor;
    
    for( i = 0; i < count; i++ )
    {
        
        // printf("Enter the exp ind : ");
        poly_exp[cursor] = demi + p->index_start - i;

        // printf("Enter coeff : ");
        poly_coeff[cursor] = demi + p->index_start - i;
        
        cursor++;
        
    }
    p->index_end = cursor-1;

    poly_exp[2] = 9;
    poly_coeff[2]=6;*/
}

void print_data()                                       // this function is absolutely broken gotta write a new one
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
        thus the element gets added no matter what
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
 
    // the algorothm will be
    
    // p1 = ax^5 + bx^3 + cx
    // p2 = mx^6 + nx^4 + ox^2
    
    // p1 * p2 = ( ax^5 + bx^3 + cx ) * ( mx^6 + nx^4 + ox^2 )
    // p1 * p2 = ax^5 * ( mx^6 + nx^4 + ox^2 ) 
            // + bx^3 * ( mx^6 + nx^4 + ox^2 )
            // + cx^1 * ( mx^6 + nx^4 + ox^2 );
    
    // here we do something i dont ever understand
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
