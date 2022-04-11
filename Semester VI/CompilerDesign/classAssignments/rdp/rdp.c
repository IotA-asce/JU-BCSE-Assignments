/**
 * @file rdp.c
 * @author your name (you@domain.com)
 * @brief develop a recursive descent parser in c/cpp
 * @version 0.1
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 *
 * << :: GRAMMER :: >>
 *
 * E -> T E'                            // @ represents null character
 * E'-> +TE' | @
 * T -> FT'
 * T'-> *FT' | @
 * F -> (E) | iD
 *
 */








// ---------------------------------------------------------------------------------------------------------------------------------------------------
// DEPENDENCY HEADERS >> START
#include <stdio.h>
#include <string.h>
// DEPENDENCY HEADERS >> END
// ---------------------------------------------------------------------------------------------------------------------------------------------------








// ---------------------------------------------------------------------------------------------------------------------------------------------------
// GLOBAL VARIABLES >> START
char input[100];
int i, l = 0;
// GLOBAL VARIABLES >> END
// ---------------------------------------------------------------------------------------------------------------------------------------------------








// ---------------------------------------------------------------------------------------------------------------------------------------------------
// UTILITY FUNCTIONS FOR INTERACTING WITH USER >> START
void showGrammer()
{
    printf("\n\n >> The grammer followed in this program is provided below -> \n");
    printf("\n-->\t E -> T E'\n-->\t E'-> +TE | @\n-->\t T -> FT'\n-->\t T'-> *FT' | @\n-->\t F -> (E) | iD\n\n");
}

void takeInput()
{
    printf("\n\n >> Enter the string that is to be analysed : ");
    gets(input);
    if (strlen(input) != 0)
    {
        printf(" -->\tString input complete\t>>\t'%s'", input);
    }
}
// UTILITY FUNCTIONS FOR INTERACTING WITH USER >> END
// ---------------------------------------------------------------------------------------------------------------------------------------------------








// ---------------------------------------------------------------------------------------------------------------------------------------------------
// GRAMMER BASED RECURSIVE FUNCTIONS >> START
void E()
{
    T();
    Eprime();
}
void T()
{
    F();
    Tprime();
}
void Eprime()
{
    if (input[i] == "+"){
        i++;
        T();
        Eprime();
    }
}
void Tprime()
{
    if (input[i] == "*"){
        i++;
        F();
        Tprime();
    }
}
void F()
{
    if(input[i] >= 0 && input[i] <= 255){
        i++;
    }
    else if (input[i] == '('){
        i++;
        E();
        if (input[i] == ')'){
            i++;
        }else{
            l = 1;
        }
    }else {
        l = 1;
    }
}
// GRAMMER BASED RECURSIVE FUNCTIONS >> END
// ---------------------------------------------------------------------------------------------------------------------------------------------------








// ---------------------------------------------------------------------------------------------------------------------------------------------------
// MAIN RUNNER PROGRAM >> START
int main(int argc, char const *argv[])
{

    showGrammer();
    takeInput();
    E();
    return 0;
}
// MAIN RUNNER PROGRAM >> END
// ---------------------------------------------------------------------------------------------------------------------------------------------------