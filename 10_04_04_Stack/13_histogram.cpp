/*
    Problem Statement: Larget Rectangular Area in histogram
    Input: {6,2,5,4,1,5,6}
    Output:10
    Input:{2,5,1}
    Output:5
*/ 
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;



// Previous Greater Element

//Input: {6,2,5,4,1,5,6}
 
vector<int>prevSmaller(int arr[],int n){
   vector<int> ps ;
   stack<int>s ;
   for(int i=0;i<n;i++){
       while(s.empty()==false&&arr[i]<arr[s.top()]){
           s.pop() ;
       }
       s.empty()?ps.push_back(-1):ps.push_back(s.top()) ;
       s.push(i) ;
   }
   return ps ;

}
vector<int>nextSmaller(int arr[],int n){
    stack<int>s ;
    vector<int> ns ;
    for(int i=n-1;i>=0;i--){
        while(s.empty()==false&&arr[i]<arr[s.top()]){
            s.pop() ;
        }
        s.empty()==true?ns.push_back(n):ns.push_back(s.top()) ;
        s.push(i) ;
    }
    reverse(ns.begin(),ns.end()) ;
    return ns ;

}

void print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" " ;
    }
    cout<<endl ;
}
int largestRectHistogram(int arr[],int n){
    vector<int> ps = prevSmaller(arr,n) ;
    vector<int> ns = nextSmaller(arr,n) ;
    print(ps) ;
    print(ns) ;
    int area = INT_MIN ;
   for(int i=0;i<n;i++){
       int res = (i-ps[i]-1)*arr[i] + (ns[i]-i)*arr[i] ;
       cout<<arr[i]<<" "<<res<<endl ;
        area = max(res,area) ;
   }
  return area; 
}
int main(){
    int arr[] = {6,2,5,4,1,5,6};
    int n =sizeof(arr)/sizeof(arr[0]) ;
    int res = largestRectHistogram(arr,n) ;
    cout<<res<<endl; 
    return 0 ;
}


/*
    O(n^2 Approach)

    int largestRectHistogram(int arr[],int n){
    int curr_res =INT_MIN ;
    int res =INT_MIN ;
    for(int i=0;i<n;i++){
       int curr = arr[i] ;
        // checking on the left and calculating width
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]){
                curr+=arr[i] ;
            }
            else{
                break;
            }
        }
       
        // checking on the right and calculating width
      
        for(int j=i+1;j<n;j++){
            if(arr[j]>=arr[i]){
                curr+=arr[i];
            }
            else{
                break;
            }
        }
       
        res = max(curr,res) ;

    }
    return res ;
}
*/ 