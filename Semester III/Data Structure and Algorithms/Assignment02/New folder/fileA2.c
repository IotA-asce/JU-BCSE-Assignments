/*Write a program to store student information in a file 
and t do the following operations. Information
includes roll, name, and score in five subjects.
Use may like to add record (ensure roll number is unique),
display all records showing roll, name and total score. 
User may search for the record against a roll. User
may edit the details a record. User may delete record. 
Deletion may be logical (by some means indicate it is
an invalid record and to be avoided in processing) and 
physical (file will not have the record).*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 4000

struct Student
{
    int roll, score[5], total;
    char name[31];
};

void getData(struct Student *s, FILE *f);
void showData(FILE *f);
void deleteData(FILE *f, char delete[], FILE *fo);

int main(void)
{
    struct Student info;
    FILE *fp;
    int choice;

    printf("Enter choice for particular operation : \n");
    printf("choice 1 = add  Data\n");
    printf("choice 2 = show Data\n");
    printf("choice 3 = delete data\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        if((fp = fopen("studentRecord","a")) == NULL)
        {
            printf("Error approaching file");
            exit(1);
        }
        getData(&info,fp);
        fclose(fp);
        break;
    case 2:
        if((fp = fopen("studentRecord","r")) == NULL)
        {
            printf("Error approaching file");
            exit(1);
        }
        showData(fp);
        fclose(fp);
        break;
    case 3:
        if ((fp = fopen("studentRecord","r")) == NULL)
        {
            printf("Error file may not exist");
            exit(1);
        }
        FILE *fo;
        printf("\nEnter the roll for deletion Operation\n");
        char deleteRoll[3];
        fflush(stdin);
        gets(deleteRoll);
        deleteData(fp,deleteRoll,fo);
        break;

    default:
        printf("Do enter a valid choice");
        exit(1);
        break;
    }
}

void getData(struct Student *s, FILE *f)
{
    char c = '*';
    fprintf(f,"%c\n",c);

    printf("Enter roll no. : ");
    scanf("%d",&(s->roll));
    fprintf(f,"%d\n",s->roll);

    printf("Enter the name : ");
    fflush(stdin);
    gets(s->name);
    fprintf(f,"%s\n",s->name);

    printf("Enter score in subjects\n");
    int i;
    s->total = 0;
    for ( i = 0; i < 5; i++)
    {
        printf("\nEnter the score for subject no %d : ",i+1);
        scanf("%d",&(s->score[i]));
        s->total += s->score[i];
    }
    fprintf(f,"%d\n",s->total);
}

void showData(FILE *f)
{
    char c;
    int k = 0;
    rewind(f);
    printf("The records are as below :\n");
    while(!feof(f))
    {
        c = getc(f);
        if(c == '*')
        {
            k++;
        }
        
        else
        {
            putchar(c);
        }
    }
    printf("\nNo of records : %d",k);
}

void deleteData(FILE *f, char delete[], FILE *fo)
{
    printf("Inside delete function\n");
    char c;
    int l = 0,i,j,k;
    rewind(f);
    
    //setting up temporary array

    char tempFile[SIZE],tempFile2[SIZE];

    
    i = 0;
    
    int count = 0;
    char space = '\n',dollar = '$';
    rewind(f);
    while(!feof(f))
    {
        c = getc(f);
        tempFile[i] = c;
        i++;
    }
    
    tempFile[i] = '\0';
    count = 0;    
    fclose(f);

    if((fo = fopen("studentRecord","r")) == NULL)
    {
        printf("File could not be created ");
    }
    i = 1;
    while(tempFile[i] != '\0')
    {
        if(tempFile[i-4] == '*' && tempFile[i-3] == '\n' && tempFile[i-2] == delete[0] && tempFile[i-1] == delete[1] && tempFile[i] == '\n')
        {
            count++;
        }
        i++;
    }
    if (count == 0)
    {
        printf("\nRoll No searched and not found\n");
        fclose(fo);
        exit(1);
    }
    fo = fopen("studentRecord","w");
    rewind(fo);
    i = 1;
    while(tempFile[i] != '\0')
    {
        if(tempFile[i-4] == '*' && tempFile[i-3] == '\n' && tempFile[i-2] == delete[0] && tempFile[i-1] == delete[1] && tempFile[i] == '\n')
        {
            while(tempFile[i] != '*')
            {
                tempFile[i-4] = dollar;
                tempFile[i-3] = dollar;
                tempFile[i-2] = dollar;
                tempFile[i-1] = dollar;
                tempFile[i]   = dollar;
                
                i++;

            }
            tempFile[i-1]=space;
            count++;
        }
        i++;
    }
    
    l = 0;
    for (j = 0; j < i; j++)
    {
        if(tempFile[j] == dollar)
        {
            tempFile2[j-1] = ' ';
            tempFile2[j]   = ' ';
        }
        else
        {
            tempFile2[l] = tempFile[j];
            l++;
        }
    }
    i=0;
    while (i<l-1)
    {
        fprintf(fo,"%c",tempFile2[i]);
        i++;
    }    

}
    