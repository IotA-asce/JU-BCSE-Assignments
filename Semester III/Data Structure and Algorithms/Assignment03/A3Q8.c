/*

Attempt 1 :     using vector cross product 

                explanation:
                            suppose there are two line segments P1 & P2
                            P1 comprises of P1(x1, y1) - P1'(x2, y2)
                            P2 comprises of P2(x3, y3) - P2'(x3, y3)

                            if P2 intersected by P1 then the end coordinates of P2 will
                            be seperated by the line P1

                            P1(x1, y1)                           * _P2(x4, y4)
                            *                               *  
                                *                       * 
                                    *               *    
                                        *       *      
                                            * O(a, b)       
                                        *        *  
                                    *                * M(m, n)
                                *                        * 
                            *                               * 
                        *                                       * 
                        P2(x3, y3)                                  * 
                                                                        * 
                                                                            * _P1(x2, y2)
                    the next step is to find the coordinates of mid point of P1
                    now rotating clockwise 

                    A = (_P2 - M) x (_P1 - M)
                    B = (P2  - M) x (P1  - M)

                    Now if sign (A) == sign (B)
                            intersect = true
                        else 
                            intersect = false

Attempt 2 : using substitution 

                explanation:
                            suppose there are two line segments P1 & P2
                            P1 comprises of P1(x1, y1) - P1'(x2, y2)
                            P2 comprises of P2(x3, y3) - P2'(x3, y3)

                            if P2 intersected by P1 then the end coordinates of P2 will
                            be seperated by the line P1

                            C(Cx, Cy)                           * B(Bx, By)
                            *                               *  
                                *                       * 
                                    *               *    
                                        *       *      
                                            * O(a, b)       
                                        *        *  
                                    *                * 
                                *                        * 
                            *                               * 
                        *                                       * 
                        A (Ax, Ay)                                  * 
                                                                        * 
                                                                            * D(Dx, Dy)
                    
                    algo :
                            S1 = (Cy - By) * (Bx - Ay) - (By - Ay) * (Cx - Bx)
                            S2 = (Dy - By) * (Bx - Ay) - (By - Ay) * (Dx - Bx)

                            P1 = (Ay - Cy) * (Dx - Cx) - (Ax - Cx) * (Dy - Cy);
                            P2 = (Ay - Cy) * (Dx - Cx) - (Ax - Cx) * (Dy - Cy);

                            if((S1 * S2) == 0) -> they touch
                            else if ((S1 * S2) > 0) -> dont intersect
                            else if((S1 * S2) < 0) -> they intersect
/*

/*
AD
*/


#include<stdio.h>

#define SIZE

float polygon1_X[SIZE];
float polygon1_Y[SIZE];

float polygon2_X[SIZE];
float polygon2_Y[SIZE];

int main(void)
{
    int choice;
    int trace = 0;
    int count = 0;

    while(trace == 0)
    {
        printf("\nEnter choice : ");
        
    }

    float Ax, Ay;
    float Bx, By;

    float Cx, Cy;
    float Dx, Dy;

	float S1, S2, P1, P2;
	
    printf("Enter details of line 1 :\n\n");

    printf("Enter value of Ax : ");
    scanf("%f",&Ax);
    printf("Enter value of Ay : ");
    scanf("%f",&Ay);

    printf("Enter value of Bx : ");
    scanf("%f",&Bx);
    printf("Enter value of By : ");
    scanf("%f",&By);

    printf("\n\nEnter details of line 2 :\n\n");

    printf("Enter value of Cx : ");
    scanf("%f",&Cx);
    printf("Enter value of Cy : ");
    scanf("%f",&Cy);

    printf("Enter value of Dx : ");
    scanf("%f",&Dx);
    printf("Enter value of Dy : ");
    scanf("%f",&Dy);

    S1 = (Cy - By) * (Bx - Ax) - (By - Ay) * (Cx - Bx);
    S2 = (Dy - By) * (Bx - Ax) - (By - Ay) * (Dx - Bx);

    P1 = (Ay - Cy) * (Dx - Cx) - (Ax - Cx) * (Dy - Cy);
    P2 = (Ay - Cy) * (Dx - Cx) - (Ax - Cx) * (Dy - Cy);

	printf("Bingo");
	
	printf("%lf\t%lf",S1, S2);
    if ( (S1 * S2) == 0 )
    {
        printf("\nTHEY TOUCH");
    }
    else if ( (S1 * S2) > 0 )
    {
        printf("\nThey dont intersect");
    }
    else if ((S1 * S2) < 0)
    {
        printf("\nTHEY INTERSECT BITCH");
    }
    
    
    
    return 0;
}
