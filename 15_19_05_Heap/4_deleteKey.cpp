/*
    Problem Statement: To delete key from min heap such that binary heap
    property should be maintained.

    We can also delete key using follownig steps
    1) decreaseKey(index,INT_MIN)
    2) getMin() ;

*/
#include<iostream>
#include<climits>
using namespace std;

class MinHeap{
    int *arr ;
    int cap,size ;
    public:
    MinHeap(int n){
        arr = new int[n] ;
        cap = n ;
        size = 0 ;
    }

    // to left child index

    int left(int i){
        return (2*i+1) ;
    }

    // to get right chid index

    int right(int i){
        return (2*i+2) ;
    }

    // to get parent index

    int parent(int i){
        return (i-1/2) ;
    }

    // heapify down

    void heapify_down(int i){
        int lt = left(i) ;
        int rt = right(i) ;
        int smallest = i ;
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

    // heapify up

    void heapify_up(int i){
        int parent_index = parent(i) ;
        if(i>0&&arr[i]<arr[parent_index]){
            swap(arr[i],arr[parent_index]) ;
            heapify_up(parent_index) ;
        }
    }
    
    //  to inset the element into min heap.

    void insert(int x){
        if(size==cap){
            cout<<"overflow"<<endl ;
            return ;
        }
        if(size==0){
            arr[size] = x ;
            size++ ;
        }
        else{
            arr[size] = x ;
            size++ ;
            heapify_up(size-1) ;
        }
    }
    
    // to delete key from the min heap
    
    void deleteKey(int i){
        if(i<0&&i>=size){
            return ;
        }
        swap(arr[i],arr[size-1]) ;
        size-- ;
        heapify_down(i) ;
    }
    
    // to print the element of min heap
     void print(){
        if(size==0){
            cout<<"empty heap "<<endl ;
            return ;
        }
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" " ;
        }
        cout<<endl ;
    }
} ;

int main(){
     MinHeap m(10) ;
    m.insert(10) ;
    m.insert(20) ;
    m.insert(40) ;
    m.insert(80) ;
    m.insert(100) ;
    m.insert(70) ;
    m.print() ;
    m.deleteKey(0) ;
    m.print();
    
}