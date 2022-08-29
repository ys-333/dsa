/*
    Index of last occurence
    arr[]: {10,15,20,20,40,40}
    key = 20
    Output:3 ( as it is last occurence of value 20 in the array or last index of that value)
*/
#include<iostream>
using namespace std;
int lastIndex(int arr[],int low,int high,int key){
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==key){
            if(arr[mid+1]==key){
                low=mid+1;
            }
            else{
                return mid;
            }
        }
        else if(arr[mid]>key) high=mid-1;
        else low = mid+1;
    }
    return -1 ;
}
int main(){
    int arr[]={10,15,20,20,40,40} ;
    int n=sizeof(arr)/sizeof(arr[0]) ;
    int res = lastIndex(arr,0,n-1,20) ;
    cout<<res<<endl;
    return 0 ;
}