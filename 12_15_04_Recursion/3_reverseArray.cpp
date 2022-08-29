/*
    Problem Statement: Reverse Array usng recursion
*/ 
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void reverse(int arr[],int low,int high){
    if(low>=high){
        return  ;
    }
    int temp = arr[low] ;
    arr[low] = arr[high] ;
    arr[high] = temp ;
    reverse(arr,low+1,high-1) ;

}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" " ;
    }
}
int main() {
    int arr[] = {1,2,3,4,5} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    reverse(arr,0,n-1) ;
    printArray(arr,n) ;
    return 0;
}

/*
    Code Re-wriiten during revison

    // Online C++ compiler to run C++ program online
#include <iostream>
#include<deque>
using namespace std;
void reverse(int *arr,int n,int start){
    if(start==n){
        return ;
    }
    int front = arr[start] ;
    start++ ;
    reverse(arr,n,start) ;
    arr[n-start] = front ;
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "  ;
    }
    cout<<endl ;
}
int main(){
    int arr[] = {1,2,3,4,5} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    reverse(arr,n,0) ;
    print(arr,n) ;
    return 0 ;
}
*/