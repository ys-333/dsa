/*
    Problem Statement: Heap Sort
*/ 
#include<iostream>
using namespace std ;


void max_heapify(int arr[],int n,int i){
    int left = 2*i+1 ;
    int right = 2*i+2 ;
    int largest = i ;
    if(left<n&&arr[left]>arr[largest]){
        largest = left ;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest = right ;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]) ;
        max_heapify(arr,n,largest) ;
    }
}

void build_heap(int arr[],int n){
    for(int i=n-2/2;i>=0;i--){
        max_heapify(arr,n,i) ;
    }
}

void heap_sort(int arr[],int n){
    build_heap(arr,n) ;

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]) ;
        max_heapify(arr,i,0) ;
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

int main(){
    int arr[] = {10,15,50,4,20} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    heap_sort(arr,n) ;
    print(arr,n) ;
}