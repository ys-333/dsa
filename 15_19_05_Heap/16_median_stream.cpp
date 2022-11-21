/*
    Problem Statement: To find median of streams of data

    Input: arr[] =  {25,7,10,15,20}
    Output:        25 16 10 12.5 15 

    Approach: Used priority queue to find median

    Used min heap and max heap.

    Time Complexity:
    O(nlog(n))
*/ 

#include<iostream>
#include<queue>
#include<vector>
using  namespace std;
void median_stream(int arr[],int n){
  priority_queue<float>p ; 
  priority_queue<float,vector<float>,greater<float>>q ;
  vector<float>res ;
  for(int i=0;i<n;i++){
    int x = arr[i];
    if(p.size()>q.size()){
      if(p.size()>0&&p.top()>x){
        q.push(p.top());
        p.pop();
        p.push(x);
      }
      else{
        q.push(x);
      }
    }
    else{
      if(q.size()>0&&q.top()<x){
        p.push(q.top());
        q.pop();
        q.push(x);
      }
      else{
        p.push(x);
      }
    }
    int size = p.size()+q.size();
    if(size%2!=0){
       
        res.push_back(p.top());
    }
    else{
      float mid = (p.top()+q.top())/2;
     
      res.push_back(mid);
    }
  }
  for(int i=0;i<res.size();i++){
      cout<<res[i]<<" " ;
  }
}
using namespace std;
int main(){
  int arr[] = {25,7,10,15,20};
  int n = sizeof(arr)/sizeof(arr[0]);
  median_stream(arr,n) ;
  return 0 ;
}