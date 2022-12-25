/*
    Problem Statement: To print sum of all substring...
*/ 
#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;

int stringToInt(string res){
    
    stringstream toNum(res);
    int num = 0 ;
    toNum>>num ;
    return num ;
}


int sumOfSubstring(string str){
    int res =0 ;
    for(int i=0;i<str.size();i++){
        for(int len=1;len<=str.size()-i;len++){
            int num = stringToInt(str.substr(i,len));
            res+=num;
        }
    }
    return res;
}
int main(){
    string str ="1234" ;
    cout<<sumOfSubstring(str)<<endl; 
}