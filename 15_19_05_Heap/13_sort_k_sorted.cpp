/*
    Problem Statement:


    Given an aray of n elements, where each element is almost k away
    form its target position, devise an algorithm that sorts in O(nlogk)
    times.

    Input: 
    arr[]  = {6,5,3,2,8,10,9}
    k=3
    Output: {2,3,5,6,8,9,10}
*/ 
#include<iostream>
#include<queue>
using namespace std;

void sortK(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>>pq ;

    for(int i=0;i<=k;i++){
        pq.push(arr[i]) ;
    }
    int index = 0 ;

    for(int i=k+1;i<n;i++){
        arr[index++] = pq.top() ;
        pq.pop() ;
        pq.push(arr[i]) ;
        
    }
    while (pq.empty()==false)
    {
        arr[index++] = pq.top() ;
        pq.pop() ;
    }
    
}


void print(int arr[],int n){
    for(int i=0;i< n;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

int main(){
    int arr[] = {9,8,7,18,19,17} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int k=2 ;
    sortK(arr,n,k) ;
    print(arr,n) ;
    return 0 ;
}