#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "a2q4_set.h"
/*
#define SIZE 100
#define UNION  200
#define INTERSECTION 100
*/


#define SIZE 100
#define UNION  200
#define INTERSECTION 100

int main(void)
{
    int set1[SIZE], set2[SIZE];
    int tempSet[SIZE];
    int countTs;

    int count1 = 0, count2 = 0, countIntersection;
    int i;

    getSet(set1, &count1);
    getSet(set2, &count2);

    setFiter(set1, &count1);
    setFiter(set2, &count2);

    setAsubB(set1,set2,count1,count2,tempSet,&countTs);

    displaySet(tempSet,&countTs);
    // displaySet(set1, &count1);
    // displaySet(set2, &count2);

    int intersection_1_2[INTERSECTION];
    int unionSet_1_2[UNION];

    countIntersection = setIntersection(set1, set2, intersection_1_2, count1, count2);

    displaySet(intersection_1_2, &countIntersection);

    int countUnion = setUnion(set1, set2, unionSet_1_2, count1, count2);
    displaySet(unionSet_1_2, &countUnion);

}

