#ifndef _A2Q5_STRING_
#define _A2Q5_STRING_

#ifdef __cplusplus
extern "C"
{
#endif

#define NIL ((char)'\0')
#define LESSTHAN    -1
#define EQUAL   0
#define GREATERTHAN     1

    int stringLen(const char inp[])
    {
        int index = 0;
        while (inp[index] != NIL)
        {
            index++;
        }

        return index;
    }

    void stringCopy(const char A[], char B[])
    {
        int index = 0;

        while (A[index] != NIL)
        {
            B[index] = A[index++];
        }
        B[index] = NIL; // to terminate the string
    }

    void stringConcat(const char B[], char A[])
    {
        int index_A = 0, index_B = 0;
        while (A[index_A] != NIL) index_A++;
        while (B[index_B] != NIL)
        {
            A[index_A++] = B[index_B++];
        }
        A[index_A] = NIL;
    }

    int stringCmp (const char A[], const char B[]){
        
        int index = 0;

        while(A[index] == B[index]){
            index++;
        }

        return (int)(A[index] - B[index]);
    }    


    int stringCharSearch(const char A[], char ch){
        int index = 0;

        while(A[index] != NIL){
            if (A[index] == ch)
            {
                return index;
            }
            
            index++;
        }
        return -1;          // char not being found
    }

    void stringSubString(const char A[], char B[], int index_s, int index_e) {
        if (index_e < index_s || index_e > stringLen(A)) return;
        int i;
        for(i = index_s; i < index_e; i++){
            B[i] = A[i];
        }

        B[i] = NIL; 
    }

    int stringSubStringSearch(const char A[],const char B[]){
        int i = 0;
        int j = 0;
        int k = 0;
        int len = stringLen(B);
        int flag = -1;

        while(A[i] != NIL){
            if(A[i] == B[j]) {
                // comparison
                for ( j = i; j < i + len; j++)
                {
                    if (A[j] != B[k++])
                    {
                        break;
                    }
                }
                k = 0;
                flag = 1;
            }
            if (flag == 1)
            {
                return 1;
            }
            

            i++;
        }

        return 0;    
    }

    void stringReverse(char A[]) {
        int i = 0, len = stringLen(A) - 1;

        while(i < len) {
            char c = A[i];
            A[i++] = A[len];
            A[len--] = c;
        }
    }

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*_P%_STRINGS_*/