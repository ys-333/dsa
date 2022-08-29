/*
    Problme Statement: Print Nth value of fibonacii series
*/ 

#include<iostream>
using namespace std;
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1 ;
    }
    // cout<<n<<" " ;
    return fib(n-1)+fib(n-2) ;

}
int main(){
    int n=5 ;
    cout<<fib(n) ;
    return 0 ;
}