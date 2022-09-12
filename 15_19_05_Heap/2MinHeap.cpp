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
#include<climits>
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

    void heapify(int i){
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
      heapify(smallest) ;
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
  
   int getMin(){
        if(size==0){
            return INT_MAX ;
        }
        if(size==1){
            size-- ;
            return arr[size+1] ;
        }
            
        else{
            swap(arr[0],arr[size-1]) ;
            size-- ;
            heapify(0) ;
            return arr[size] ;
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
    // m.print() ;
    cout<<endl ;
    cout<<m.getMin()<<endl ;
    m.print();
    
    // int arr[] = {40,20,30,35,25,80,32,100,70,60} ;
   
    return 0 ;
}

/*
  Iterative approach
  
  void fixMinHeap(int *arr,int size,int i){
    while(i<size&&arr[i]>arr[left(i)]||arr[i]>arr[right(i)]){
        if(arr[left(i)]<arr[right(i)]){
            swap(arr[i],arr[left(i)]) ;
            i = left(i) ;
        }
        else{
            swap(arr[i],arr[right(i)]) ;
            i = right(i) ;
        }
    }
}
*/ 