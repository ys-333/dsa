/*
    Problem Statement: Given an array of distinct integer,find
    cloest(position wise) gretaer on left of every element If there is no 
    greater element on left than print -1.

    Input: {15,10,18,12,4,6,2,8}
    Output:-1 15 -1 18 12 12 6 12

    Input: {8 10,12}
    Output: -1 -1 -1  
*/ 
#include<iostream>
#include<stack>
using namespace std;

/*
    Approach:
    If arr[i] is smaller than s.top() then we push into the stack.
    else
        we pop out the element from stack till stack is empty or arr[i] is smaller than stack top.
        
        Dry run if have doubt.
*/ 

void previousGreater(int arr[],int n){
    // Time Complexity: O(n) Approach
    // Space Complexity: O(n) extra Space
    stack<int>s ;
    for(int i=0;i<n;i++){
       
        // to check that arr[i] is smaller or not compare to s.top(
            while(s.empty()==false&&arr[i]>s.top()){
                s.pop() ;
            }
            s.empty()==true?cout<<"-1"<<" ":cout<<s.top()<<" " ;
            s.push(arr[i]) ;
        
    }
}

int main(){
    int arr[] ={15,10,18,12,4,6,2,8}  ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    previousGreater(arr,n) ;
    return 0 ;
}

/*
    O(n^2) Appraoch

    void previousGreater(int arr[],int n){
    for(int i=0;i<n;i++){
        int res =-1 ;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                res = j ;
                break ;
            }
        }
        if(res==-1){
            cout<<res<<" " ;
        }
        else cout<<arr[res]<<" " ;
    }
}


*/ 