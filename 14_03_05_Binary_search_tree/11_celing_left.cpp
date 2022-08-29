/*
    Problem Statement: Celing on left Side.
    Input: arr[] = {2,8,30,15,25,12}
    Output:         -1 -1 -1 30 30 15
    Input: arr[] = {10,20,30}
    Output: -1 -1 -1
    Input: arr[] = {6,18,4,5}
    Ouput: -1 -1 6,6
*/ 
#include<iostream>
#include<climits>
#include<set>
#include<stack>
using namespace std ;
// method 2 using stack

void ceil(int arr[],int n){
    stack<int>s1,s2 ;
    s1.push(arr[0]) ;
    for(int i=0;i<n;i++){
        int res = INT_MAX ;
        bool checked = false ;
        while (s1.empty()==false)
        {
            if(s1.top()>arr[i]&&res>s1.top()){
                res = s1.top() ;
                checked = true;
            }
            s2.push(s1.top());
            s1.pop() ;
        }
       if(checked){
           cout<<res<<" " ;
       }
       else{
           cout<<"-1"<<" " ;
       }
        while (s2.empty()==false)
        {
            /* code */
            s1.push(s2.top()) ;
            s2.pop() ;
        }
        s1.push(arr[i]) ;
        
        
    }
}
// Better method using set data structure which is built on top of red black tree.
void ceilSet(int arr[],int n){
     set<int>s ;
    s.insert(arr[0]) ;
    cout<<"-1"<<" ";
  for(int i=1;i<n;i++){
      auto it=s.end() ;
      it-- ;
      if(arr[i]>*it){
          cout<<"-1"<<" " ;
      }
      else{
          auto it1 =  s.upper_bound(arr[i]);
          cout<<*it1<<" " ;
      }
      s.insert(arr[i]) ;
          
  }
}

int main(){
    int arr[] = {6,18,4,5} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    ceilSet(arr,n) ;
    
}

/*
    Approach 1:
    Time Complexity: O(n^2)
    Space complexity: O(1)
   int res ;
    cout<<"-1"<<" " ; //since for first element of array
    for(int i=1;i<n;i++){
        res=-1 ;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[i]&&res==-1){
                res = arr[j] ;
            }
            if(arr[j]>arr[i]&&res>arr[j]){
                res  = arr[j] ;
            }
        }
        if(res==-1){
            cout<<"-1"<<" " ;
        }
        else{
            cout<<res<<" " ;
        }
    }

    Approach 2:
    Time Complexity: O(n)
    Space Complexity: O(n)



*/ 