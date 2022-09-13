#include<iostream>
#include<cmath>
using namespace std;

class MaxHeap{
    int *arr ;
    int size ;
    int cap ;
    public:
    MaxHeap(int n){
        arr = new int[n] ;
        size = 0 ;
        cap = n ;
    }

    int parent(int i){
        return floor((i-1)/2) ;
    }

    int left(int i){
        return 2*i+1 ;
    }

    int right(int i){
        return 2*i+2 ;
    }

    // heapify up

    void heapify_up(int i){
        int p = parent(i) ;
        if(i>0&&arr[i]>arr[p]){
            swap(arr[i],arr[p]) ;
            heapify_up(p) ;
        }
    }
    void heapify_down(int i){
        int l  = left(i) ;
        int r  = right(i) ;
        int largest = i ;
        if(l<size&&arr[largest]<arr[l]){
            largest = l ;
        }
        if(r<size&&arr[largest]<arr[r]){
            largest = r ;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]) ;
            heapify_down(largest) ;
        }
    }

    void insert(int x){
        if(size==cap){
            return ;
        }
        if(size==0){
            arr[size] = x; 
            size++ ;
        }
        else{
            arr[size] = x ;
            size++ ;
            heapify_up(size-1) ;
        }
    }
    
    void deleteKey(int i){
        if(size==0){
            return ;
        }
        if(size==1){
            size-- ;
        }
        else{
            swap(arr[i],arr[size-1]) ;
            size-- ;
            heapify_down(i) ;
        }
    }
    
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" " ;
        }
        return ;
    }
};

int main(){
    class MaxHeap m(10) ;
    m.insert(1) ;
    m.insert(3) ;
    m.insert(5) ;
    m.insert(4) ;
    m.insert(6) ;
    m.insert(13) ;
    m.insert(14) ;
    m.deleteKey(0) ;
    m.print() ;
}