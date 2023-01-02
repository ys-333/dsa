/*
    Problem Statement: Given a string, print all those permutation which do not contain "AB" as substring
    Input:"ABC"
    Output:ACB BAC BCA CBA

    The above string do not contain AB as substring and are permutation
    of the given string.
*/ 
#include<iostream>
#include<string.h>
using namespace std;



void permute(string str,int l,int r){
    if(l==r){
        if(str.find("AB")==string::npos){
            cout<<str<<" ";
            return ;
        }
    }
    else{
        for(int i=l;i<=r;i++){
            swap(str[l],str[i]);
            permute(str,l+1,r);
            swap(str[l],str[i]);
        }
    }
}
int main(){
    string str = "ABC";
    permute(str,0,str.size()-1);
    return 0 ;
}
