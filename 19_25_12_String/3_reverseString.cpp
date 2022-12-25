// Reverse string using
#include <iostream>
#include<string.h>
#include<vector>
using namespace std;
void reverse(string name,int index,vector<char>&v){
    // base case
    if(index<0){
        return ;
    }
  
    v.push_back(name[index]) ;
    reverse(name,--index,v);
  
}
int main() {
    string name = " margorp emosewa";
    int index = name.size()-1 ;
    vector<char>v ;
    reverse(name,index,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" " ;
    }
    return 0;
}