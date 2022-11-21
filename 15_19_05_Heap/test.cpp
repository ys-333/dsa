#include<iostream>
#include<queue>
void median_stream(int arr[],int n){
  priority_queue<float,vector<float>,greater<float>>p ; //max heap
  priority_queue<float>q ; //min heap
  for(int i=0;i<n;i++){
    int x = arr[i];
    if(p.size()>q.size()){
      if(p.top()>x){
        q.push(p.top());
        p.pop();
        p.push(x);
      }
      else{
        q.push(x);
      }
    }
    else{
      if(q.top()<x){
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
      cout<<p.top()<< " " ;
    }
    else{
      float mid = p.top()+q.top();
      cout<<mid/2<<" " ;
    }
  }
}
using namespace std;
int main(){
  int arr[] = {25,7,10,15,20};
  int n = sizeof(arr)/sizeof(arr[0]);
  median_stream(arr,n) ;
  return 0 ;
}