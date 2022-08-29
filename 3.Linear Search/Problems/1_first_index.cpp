/*
    To find index of first occurence of given element
    Input:
    arr[] = {1,2,3,4,7,8,20,20,30} ;
    key:20;
    Output: 6
*/
#include<iostream>
using namespace std;
int index(int arr[],int start,int end,int key){
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            if(arr[mid-1]==key){
                end = mid-1;
            }
            else
            return mid;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1 ;
}
int main(){
    int arr[]={5,5,5,5} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int idx = index(arr,0,n-1,5) ;
    cout<<idx<<" " ;
    return 0 ; 
}
