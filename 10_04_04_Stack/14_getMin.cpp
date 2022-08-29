/*
    Problem Statement: Desing a Stack that supports getMin()
    push(20) push(10) getMin() pop() getMin() pop()
    getMin() pop() getMin()
    Output: 10 5 10 20
*/ 

#include<iostream>
#include<stack>
using namespace std;
class MyStack{
    stack<int>ms ;
    stack<int>as ;
    public:
    void push(int x){
        if(ms.empty()){
            ms.push(x) ;
            as.push(x) ;
        }
        if(as.top()>=x){
            as.push(x) ;
        }
        ms.push(x) ;
    }
    void pop(){
        if(ms.empty()){
            cout<<"Underflow"<<endl ;
            return ;
        }
        if(ms.top()==as.top()){
            as.pop() ;
        }
        ms.pop() ;
    }
    int getMin(){
        if(as.empty()){
            cout<<"Stack is empty"<<endl ;
            return -1 ;
        }
        return as.top() ;
    }
    void print(){
        stack<int>s = ms ;
        while(s.empty()==false){
            cout<<s.top()<<" " ;
            s.pop() ;
        }
        cout<<endl ;
    }
} ;
int main(){
   MyStack s ;
   s.push(2) ;
   s.push(3) ;
   s.push(1) ;
   s.push(5) ;
   cout<<s.getMin()<<endl ;
   s.pop() ;                                                                                                                                                                                                                                 
   s.pop() ;
   cout<<s.getMin()<<endl ;
   return 0 ;                                                                                                                                                                                                                                 
}