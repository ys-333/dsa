/*
    Problem Statement:
    Max Heap
*/ 
#include<iostream>
using namespace std ;

// heapify down to make it max heap

void heapify_down(int arr[],int i,int n){
    int l = 2*i+1 ;
    int r = 2*i+2 ;
    int largest = i ;
    if(l<n&&arr[largest]<arr[l]){
        largest = l;
    }
    if(r<n&&arr[largest]<arr[r]){
        largest = r ;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]) ;
        heapify_down(arr,largest,n) ;
    }
}

void buildMaxHeap(int arr[],int n){
    for(int i=(n-1-1)/2;i>=0;i--){
        heapify_down(arr,i,n) ;
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

int main(){
    int arr[] = {1,3,5,4,6,13} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    buildMaxHeap(arr,n) ;
    print(arr,n) ;
    return 0 ;
}