// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Disjoint{
    int n ;
    int *parent ;
    int *rank ;
  
    public:
  
      Disjoint(int n){
        this->n = n ;
        parent = new int[n] ;
        rank = new int[n] ;
        init() ;
    }
     void init(){
        for(int i=0;i<n;i++){
            parent[i] = i ;
        }
        for(int i=0;i<n;i++){
            rank[i] = 0 ;
        }
    }
    int find(int x){
        if(parent[x]=x){
            return x; 
        }
        return find(parent[x]) ;
    }
    // void Union(int x,int y){
    //     int x_rep = find(x) ;
    //     int y_rep = find(y) ;
    //     // if(x_rep==y_rep){
    //     //     return ;
    //     // }
    //     if(rank[x_rep]>rank[y_rep]){
    //         parent[y_rep] = x_rep ;
    //     }
    //     else if(rank[y_rep]>rank[x_rep]){
    //         parent[x_rep] = y_rep ;
    //     }
    //     else{
    //         parent[y_rep]= x_rep ;
    //         rank[x_rep]++ ;
    //     }
    // }
    void Union(int x,int y){
        int x_rep = find(x) ;
        int y_rep=  find(y) ;
        if(rank[x_rep]>rank[y_rep]){
            parent[y_rep] = x_rep;
        }
        else if(rank[y_rep]>rank[x_rep]){
            parent[x_rep] = y_rep ;
        }
        else{
            parent[y_rep] = x_rep ;
            rank[x_rep]++ ;
        }
    }
  void print(){
        cout<<"parent array "<<endl ;
        for(int i=0;i<n;i++){
            cout<<parent[i]<<" " ;
        }
        cout<<endl ;
        cout<<"rank array "<<endl ;
        for(int i=0;i<n;i++){
            cout<<rank[i]<<" " ;
        }
    }

} ;
int main(){
    Disjoint d(5) ;
    d.Union(3,4) ;
    d.Union(2,3) ;
    d.Union(1,2) ;
    d.Union(0,1) ;
    if(d.find(0)==d.find(4)){
        cout<<"they are either direct or mutal frined of each other"<<endl ;
    }
    d.print() ;
    return 0 ;
}
    
