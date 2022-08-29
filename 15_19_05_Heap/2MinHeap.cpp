/*
    Problem Statement: Implementing Min Heap, and operations like:
        - heapify up.
        - heapify down.
        - extract min.
    
    Input: 
                    40
                    /\
                  20  30
                 / \    /\
               35  25  80 32
              /\    /
            100 70 60

    Output:
                   20
                    /\
                  25  30
                 / \   /\
               35  40 80 32
              /\    /
            100 70 60

    Violation is at the root itself.
    But inseted of root node,we will be given array of all values. 
*/ 
#include<iostream>
#include<cmath>
using namespace std;


class MinHeap{
    int *arr,cap,size;
  public:
    MinHeap(int n){
    arr = new int[n] ;
    cap = n ;
    size =0 ;
  }
    int parent(int i){
        int value = i-1 ;
        return floor(value/2) ;
    }
    int left(int i){
    return (2*i+1) ;
  }
    int right(int i){
    return (2*i+2) ;
  }
  
    void heapify_up(int i){
  
     int pt = parent(i) ;
     if(pt&&arr[i]<arr[pt]){
         swap(arr[pt],arr[i]) ;
         heapify_up(pt) ;
     }
   
  }

    void heapify_down(int i){
    int lt =left(i) ;
    int rt =right(i) ;
    int smallest =  i ;
    if(lt<size&&arr[lt]<arr[smallest]){
      smallest = lt ;
    }
    if(rt<size&&arr[rt]<arr[smallest]){
      smallest = rt ;
    }
    if(smallest!=i){
      swap(arr[i],arr[smallest]) ;
      heapify_down(smallest) ;
    }
  }
 
    void insert(int x){
    if(size==cap){
      cout<<"The size is equal to capactiy "<<endl ;
      return ;
    }
    size++ ;
    arr[size-1] = x; 
    int index = size-1 ;
    heapify_up(index) ;
  }
  
  int extractMin(int i){
      swap(arr[i],arr[size-1]) ;
      size-- ;
      heapify_down(i) ;
      return arr[size] ;
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
    // m.print() ;
    cout<<endl ;
    cout<<m.extractMin(0)<<endl ;
    m.print();
    
    // int arr[] = {40,20,30,35,25,80,32,100,70,60} ;
   
    return 0 ;
}
    