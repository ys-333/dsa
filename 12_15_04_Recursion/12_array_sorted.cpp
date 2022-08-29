/*
    Problem Statement: Array is sorted or not.
*/ 
#include<iostream>
using namespace std;
bool sorted(int arr[],int s,int e){
   
    if(s==e||s==e-1){
      if(arr[s]<arr[e]){
          return true; 
      }
      return false ;
    }
    bool res =   sorted(arr,s+1,e) ;
    if(arr[s]>arr[s+1]){
        return false ;
    }
    return res ;
}
int main(){
    int arr[] = {2,20,21,222,123};
    int n = sizeof(arr)/sizeof(arr[0]) ;
    cout<<sorted(arr,0,n-1) ;
    return 0 ;
}