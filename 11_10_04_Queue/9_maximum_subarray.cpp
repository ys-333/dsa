/*
    Problem Statement: Maxiumums in all subarray of size k.
    Input: {10,8,5,12,15,7,6} K=3
    Output: 10 12 15 15 15
*/

#include <bits/stdc++.h>
using namespace std;

/*
    1.First traverse the first k-1 element and get it in  the dequue
    2.When last element of deque is smaller than arr[i],so we pop all
    smaller element from the dequeu till deque is empty or
    last element becomes larger than current array element.

    Traversing last Loop
    here we print the front element of deque as we store
    all greates element of of window k in front of deque and smaller
    element in back of deque.

    We also keep on removing the index from deque which becmoe out of window
    so we simply pop it.

*/

void maximumEl(int arr[], int n, int k)
{
    deque<int> d;
    for (int i = 0; i < k; i++)
    {
        while (!d.empty() && arr[d.back()] <= arr[i])
        {
            d.pop_back();
        }
        d.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[d.front()] << " ";
        // now remove  index from deque which is not in current window
        while (!d.empty() && d.front() <= i - k)
        {
            d.pop_front();
        }
        // now check last index and its correspoding value of that index
        while (!d.empty() && arr[d.back()] <= arr[i])
        {
            d.pop_back();
        }
        d.push_back(i);
    }
    cout << arr[d.front()] << endl;
}
int main()
{
    int arr[] = {10, 4, 7, 1, 15, 7, 6};
    // int arr[] = {10, 12, 14, 16, 17, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    maximumEl(arr, n, 3);
    return 0;
}

/*
    Great apporach but code is quite messy,
    so will go with 2 traversal method.
    Here I solve the problem in one traversal

*/
/*

    Came with this code during revison



    #include<iostream>
#include<deque>
using namespace std;

void maxSubarray(int arr[],int n,int k){
    deque<int>dq ;
    for(int i=0;i<k;i++){
        if(dq.empty()){
            dq.push_front(i) ;
        }
        else{
            if(arr[dq.front()]<arr[i]){
                dq.push_front(i) ;
            }
            else{
                dq.push_back(i) ;
            }
        }
    }
    for(int i=k;i<n;i++){
        cout<<arr[dq.front()]<<" " ;
        // now we need to pop the element
        auto it = dq.begin() ;
        while(*it!=i-k){
            it++ ;
        }
        dq.erase(it) ;
         if(arr[dq.front()]<arr[i]){
            dq.push_front(i) ;
        }
        else{
            dq.push_back(i) ;
        }
    }
     cout<<arr[dq.front()]<<" " ;
}

int main(){
    // int arr[] = {10,8,5,12,15,7,6} ;
    int arr[] = {5,15,10,20,4,40} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int k =3 ;
    maxSubarray(arr,n,k) ;
    return 0 ;
}

*/ 