/*
    todo Problem Statement: Print Subsequence of string.
*/ 
#include<iostream>
#include<string.h>
using namespace std;
void recurse(string input,string output){
    if(input.empty()){
        cout<<output<<" "<<endl ;
        return ;
    }
    // include first character
    recurse(input.substr(1),output+input[0]);
    // do not include first character
    recurse(input.substr(1),output) ;
}
int main(){
    string str = "abc";
    string output = "" ;
    recurse(str,output);
    return 0 ;
}
