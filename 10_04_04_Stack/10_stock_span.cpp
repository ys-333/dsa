/*
    Problem Statement: Stock span Problem and its varaiatino
    Input: {15,13,12,14,16,8,6,4,10,30}
    Output:1 1 1 3 5 1 1 1 4 10
    
    Input:{10,20,30,40}
    Outut:1 2 3 4
    
    Input:{40,30,20,10}
    Outut:1 1 1 1
*/ 

/*
    Approach:
    We traverse the array and push the array element which 
    are smaller than s.top() and pop out the s.top() if 
    the arr[i] is graeter than s.top() till stack is empty or 
    arr[i] becmoes smaller than the s.top().

    After we come out of the while loop we check for:
    
        if stack is empty that means that is the largest element
        in span of 0 to that index i, so we output i+1.
        Else we output i - s.top().
*/ 

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>stockSpan(int arr[],int n){
    vector<int> v;
    stack<int> s; 
    v.push_back(0) ;
    for(int i=1;i<n;i++){

        while(s.empty()==false&& arr[i]>arr[s.top()]){
            s.pop() ;
        }
        s.empty()==true?v.push_back(i+1):v.push_back(i-s.top());
        s.push(i) ;
        
    }
    return v ;
}
int main(){
    int arr[] = {15,13,12,14,16,8,6,4,10,30} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    vector<int>res = stockSpan(arr,n) ;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" " ;
    }
    return 0 ;

}