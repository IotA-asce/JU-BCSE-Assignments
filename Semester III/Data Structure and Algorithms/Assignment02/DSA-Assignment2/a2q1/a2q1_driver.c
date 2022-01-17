#include<stdio.h>
#include "a2q1_polynomial.h";

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
}