#include <stdio.h>
#include <ctype.h>
#include "a2q5_string.h"


void main(void) {
    char A[1024] = {'\0'}, B[1024] = {'\0'}, C[2] = {'\0'}, choice[2] = {'\0'};
    int i1, i2;
    printf("A. Input string A\n");
    printf("B. Input string B\n");
    printf("C. Print A and B\n");
    printf("D. Store B into A\n");
    printf("E. Concatenate  B to A and store into A.\n");
    printf("F. Compare A and B\n");
    printf("G. Search for a character in A\n");
    printf("H. Extract a substring from A and store it into B\n");
    printf("I. Search for B within A\n");
    printf("J. Reverse string A\n");
    printf("0. Exit\n");
    while(1) {
        printf("\nEnter your choice: "); scanf("%s", choice);
        switch(toupper(choice[0])) {
        case 'A': printf("Enter string for A: "); scanf(" %[^\n]%*c", A); break;
        case 'B': printf("Enter string for B: "); scanf(" %[^\n]%*c", B); break;
        case 'C': 
            printf("A (excluding starting and ending quotes): \"%s\"\nLength of A: %d\nB (excluding starting and ending quotes): \"%s\"\nLength of B: %d\n",
            A, stringLen(A), B, stringLen(B)); break;
        case 'D': stringCopy(A, B); break;
        case 'E': stringConcat(A, B); break;
        case 'F': 
            switch(stringCmp(A, B)) {
            case LESSTHAN: printf("A is less than B\n"); break;
            case EQUAL: printf("A is equal to B\n"); break;
            case GREATERTHAN: printf("A is greater than B\n"); break;
            }
            break;
        case 'G':
            printf("Enter your character: "); scanf("%s", C);
            i1 = stringCharSearch(A, C[0]);
            if(i1 < 0) printf("%c not found in A\n", C[0]);
            else printf("%c found in A at position %d (1-based index)\n", C[0], i1 + 1);
            break;
        case 'H':
            printf("Enter starting index and ending index (inclusive, 1-based indexes): "); scanf("%d %d", &i1, &i2);
            i2--; i1--; if(i2 < i1 || i2 >= stringLen(A)) {
                printf("Invalid indexes..choose option %d and enter again.\n", choice);
                break;
            }
            stringSubString(A, B, i1, i2);
            break;
        case 'I':
            i1 = stringSubStringSearch(A, B);
            if (i1 < 0) printf("B not found in A\n");
            else printf("B found in A at position %d (1-based index)\n", i1 + 1);
            break;
        case 'J': stringReverse(A); break;
        case '0': return;
        default: printf("Invalid Option!\n"); break;
        }
    }
}