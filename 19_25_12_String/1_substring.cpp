/*
    Printing all substring of string

    Substring Defenation: A string is substring if its subset of main string and it's continous.
*/ 
#include<iostream>
#include<string.h>
using namespace std;
void print_substring(string str){
    for(int i=0;i<str.size();i++){
        for(int len =1;len<=str.size()-i;len++){
            cout<<str.substr(i,len)<<endl;
        }
        
    }
}
int main(){
    /*string str = "abc";
    to print all substring of string
    print_substring(str);*/


    // to print substring after certain char
    string str = "yash:want" ;
    int index = str.find(":");
   cout<<str.substr(0,index)<<" "<<str.substr(index+1,str.size())<<endl;
    return 0;
}