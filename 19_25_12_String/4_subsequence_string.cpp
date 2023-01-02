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
// another way to get subsequence of string
int subsequence(string input,string output[]){
    // base case
    if(input.length()==0){
        output[0] = "";
        return 1;
    }
    int smallerArraylength = subsequence(input.substr(1),output);

    for(int i=0;i<smallerArraylength;i++){
        output[i+smallerArraylength] = input[0]+output[i];
    }

    return 2*smallerArraylength ;

}

// this main caller for recurse function

// int main(){
//     string str = "abc";
//     string output = "" ;
//     recurse(str,output);
//     return 0 ;
// }

int main(){
    string str = "abc";
    string output[1000];
    int outputStringLength = subsequence(str,output);
    for(int i=0;i<outputStringLength;i++){
        cout<<output[i]<<endl;
    }
}