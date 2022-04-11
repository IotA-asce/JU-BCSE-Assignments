#include<iostream>
#include<string>
using namespace std;

string input;
int l=0;
// grammer
//  E->iF
// F->+iF|*iF|e

void match(char t){
    if(input[l]==t)
        l++;
    else{
        cout<<"\nerror\n";
        exit(1);
    }
}
void F(){
    if(input[l]=='+'){
        match('+');
        match('i');
        cout<<"F->+iF"<<endl;
        F();
    }
    else if(input[l]=='*'){
        match('*');
        match('i');
        cout<<"F->*iF"<<endl;
        F();
    }
}
void E(){
    if(input[l]=='i'){
        match('i');
        cout<<"E->iF"<<endl;
        F();
    }
}

int main(){

    // input="i+i*i+i*i*i*i$";
    cout << "Enter the string to be parsed : ";
    cin >> input;
    E();
    if(input[l]=='$')
        cout<<"\nparsing successful\n";
    return 0;
}
