/*
    Problem Statement: Write an efficient program for printing k largest
    elements in an array. Elements can be in any order.

    Input 1:

        arr[]  ={1,23,12,9,30,2,50}
        K = 3
    
    Output:
        50,30,23
    
    Input 2:

        arr[]  ={8,6,4,10,9}
        K = 3
    
    Output:
        10,9,8
*/ 

#include<iostream>
using namespace std;


/*
    Max heap solution

    Time Complexity:
        - To build heap  = O(n)
        - To find K largest element = klog(n)

    Over all = O(n+klog(n)) ;

*/ 

void max_heap(int arr[],int n,int i){
    int l = 2*i+1 ;
    int r = 2*i+2 ;
    int largest = i ;
    if(l<n&&arr[l]>arr[largest]){
        largest = l ;
    }
    if(r<n&&arr[r]>arr[largest]){
        largest = r ;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]) ;
        max_heap(arr,n,largest) ;
    }
}

void build_heap(int arr[],int n){
    for(int i=n-2/2;i>=0;i--){
        max_heap(arr,n,i) ;
    }
}

void print_kth_largest_element(int arr[],int n,int k){
    build_heap(arr,n) ;
    while (k>=0)
    {
        cout<<arr[0]<<" " ;
        swap(arr[0],arr[n-1]) ;
        n-- ;
        max_heap(arr,n,0) ;
    }
}

// Max hepa solution end here 

/*
    Min heap solution:
        1) Build a min heap of first k items.
        2) Traverse from the (k+1)th element.
            a) Compare the current element with top of heap, if smaller
            than top, ignore it.

            b) Else remove the top element and insert  the current element in 
            the min heap.
        3) Print the content of the min heap.



    Time Complexity:
        O(k)+ O(n-k(logk))

*/ 

void min_heap(int arr[],int n,int i)
{
    int l = 2*i+1 ;
    int r = 2*i+2 ;
    int smallest = i ;

    if(l<n&&arr[l]<arr[smallest]){
        smallest = l ;
    }
    
    if(r<n&&arr[r]<arr[smallest]){
        smallest = r ;
    }

    if(smallest!=i){
        swap(arr[i],arr[smallest]) ;
        min_heap(arr,n,smallest) ;
    }
}
    


void build_min_heap(int arr[],int n){
    for(int i=n-2/2;i>=0;i--){
        min_heap(arr,n,i) ;
    }
}

void print_k_largest_min_heap(int arr[],int n,int k){
    build_min_heap(arr,k) ;
    for(int i=k;i<n;i++){
        if(arr[i]>arr[0]){
            swap(arr[i],arr[0]) ;
            min_heap(arr,k,0) ;
        }
    }
}

void print(int arr[],int k,int n){
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
}


// Kth largest using min heap solution ends here.


int main(){
    int arr[] = {1,23,12,9,30,2,50} ; // 50 23 30
    int n  = sizeof(arr)/sizeof(arr[0]) ;
    int k = 3 ;
    // print_kth_largest_element(arr,n,k) ;
    print_k_largest_min_heap(arr,n,k) ;
    print(arr,k,n) ;
    return 0 ;
}


/*
    Method 2: Using Priority Queue

    void kLargest(int arr[],int n,int k){
    // priority_queue<int>pq(arr,arr+n) ;
    // for(int i=0;i<k;i++){
    //     cout<<pq.top()<<" " ;
    //     pq.pop() ;
    // }
   
   priority_queue<int,vector<int>,greater<int>>pq ;
   for(int i=0;i<n;i++){
       pq.push(arr[i]) ;
       
       if(pq.size()>k){
           pq.pop() ;
       }
   }
   while(pq.empty()==false){
       cout<<pq.top()<< " " ; 
       pq.pop() ;
   }
}
*/ 
    