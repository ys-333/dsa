/*
    Problem Statement: Implementing binary heap.
*/ 
#include<iostream>
#include<cmath>
using namespace std;
class MinHeap{
    
    int *arr;
    int size ; 
    int capacity ;
    public:
    MinHeap(int c){
        arr = new int[c] ;
        size = 0 ;
        capacity =c;
    }
    int left(int i){
        return (2*i+1) ;
    }
    int right(int i){
        return (2*i+2) ;
    }
    int parent(int i){
        return floor((i-1)/2) ;
    }
    void insert(int x){
        if(size==capacity){
            cout<<"The array is full "<<endl ;
            return ;
        }
        size++ ;
        arr[size-1] = x;
        for(int i=size-1;i!=0&&arr[parent(i)]>x;){
            swap(arr[i],arr[parent(i)]) ;
            i = parent(i) ;
        }
    }
    void print(){
        if(size==0){
            cout<<"Array is empty"<<endl ;
            return ;
        }
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" "  ;
        }
        cout<<endl ;
    }
} ;
int main(){
    class MinHeap m(10) ;
    m.insert(10) ;
    m.insert(20) ;
    m.insert(15) ;
    m.insert(40) ;
    m.insert(50) ;
    m.insert(100) ;
    m.insert(25) ;
    m.insert(45) ;
    m.insert(12) ;
    m.print() ;
    return 0 ;
}