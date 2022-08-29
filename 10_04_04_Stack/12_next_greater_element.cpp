/*
    Problem Statement: Given an array of distinct integer,find
    cloest(position wise) gretaer on right of every element If there is no 
    greater element on left than print -1.

    Input: {15,10,18,12,4,6,2,19}
    Output: 18 18 19 19 6 19 19 -1

    Input: {8 10,12}
    Output: 10 12 -1
*/ 
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

/*
    Approach:
        Same as stock span problem and previous greater element
        just difference is we traverse the element from the back of array 
*/ 

vector<int> nextGreater(int arr[],int n){
    // Time Complexity: O(n) Approach
    // Space Complexity: O(n) extra Space
    stack<int>s ;
    vector<int> v;
   for(int i= n-1;i>=0;i--){
       while (s.empty()==false&&arr[i]>s.top())
       {
           s.pop() ;
       }
       int val =  s.empty()?-1:s.top() ;
        v.push_back(val) ;
        s.push(arr[i]) ;
    }
    reverse(v.begin(),v.end()) ;
    return v;
}

int main(){
    int arr[] ={15,10,18,12,4,6,2,8}  ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    vector<int> v =  nextGreater(arr,n) ;
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
    return 0 ;
}

/*
    O(n^2) Appraoch

    void nextGreater(int arr[],int n){
    for(int i=0;i<n;i++){
        int res =-1 ;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                res = arr[j] ;
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