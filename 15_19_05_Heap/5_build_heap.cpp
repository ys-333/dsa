/*



    Minimum number of nodes at height h = ceil[n/2^h+1]


    Problem statement

    Given an complete binary tree but it violate the min heap property,
    make it min heap.

    Input 1:

    int arr[] = {17,15,13,9,6,5,10,4,8,3,1};

    Output: {1,3,5,4,6,13,10,9,8,15,17}


*/ 


#include<iostream>
using namespace std;

void heapify_down(int arr[],int n,int i){
    int lt = 2*i+1 ;
    int rt = 2*i+2 ;
    int smallest = i ;
    if(lt<n&&arr[lt]<arr[smallest]){
        smallest= lt ;
    }
    if(rt<n&&arr[rt]<arr[smallest]){
        smallest= rt ;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]) ;
        heapify_down(arr,n,smallest) ;
    }
}

void buildHeap(int arr[],int n){
    for(int i=n-2/2;i>=0;i--){
        heapify_down(arr,n,i) ;
    }
}

void printHeap(int arr[],int n){
    for(int i=0;i< n;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}

int main(){
    int arr[] = {10,5,20,2,4,8} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    buildHeap(arr,n) ;
    printHeap(arr,n) ;
    return 0 ;
}
    