/*
    Problem Statement: To purchase max item from the given 
    array.

    Input:
    cost[] = {1,12,5,111,200}
    sum = 10
    Output : 2

    Input:

    cost[] = {20,10,5,30,100}
    sum = 35
    Output : 3
*/ 
#include<iostream>
#include<climits>
using namespace std ;

// int max_item(int cost[],int sum,int n){
//     int res = INT_MIN ;
//     for(int i=0;i<n;i++){
//         int total = cost[i] ;
//         int count = 0 ;
//         for(int j=i+1;j<n;j++){
//             if(cost[j]+total<=sum){
//                 count++ ;
//                 total+=cost[j] ;
//             }
//         }
//         res = max(res,count) ;
//     }
//     return (res+1);
// }

void min_heap(int cost[],int n,int i){
    int l  = 2*i+1 ;
    int r  = 2*i+2 ;
    int smallest = i ;
    if(l<n&&cost[l]<cost[smallest]){
        smallest = l ;
    }
    if(r<n&&cost[r]<cost[smallest]){
        smallest = r ;
    }
    if(smallest!=i){
        swap(cost[i],cost[smallest]) ;
        min_heap(cost,n,smallest) ;
    }
}

void build_heap(int cost[],int n){
    for(int i=n-2/2;i>=0;i--){
        min_heap(cost,n,i) ;
    }
}

int max_item(int cost[],int sum,int n){
    build_heap(cost,n) ;
    int count = 0 ;
    while(sum>=cost[0]){
        count++ ;
        sum = sum-cost[0] ;
        swap(cost[0],cost[n-1]) ;
        n--;
        min_heap(cost,n,0) ;
    }
    return count ;
}


int main(){
    int cost[] = {1,12,5,111,200} ;
    int sum = 10 ;
    int n =sizeof(cost)/sizeof(cost[0]) ;
    cout<<max_item(cost,sum,n) ;
    return 0 ;
}