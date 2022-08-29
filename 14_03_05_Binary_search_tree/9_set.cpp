/*
    Problem Statement: Set operation
*/ 
#include<iostream>
#include<set>
using namespace std;
int main(){

    // by default set store value in ascending order
    set<int>s ;
    // we can change this behaviour by
    // set<int,greater<int>>s ;
    s.insert(30) ;
    s.insert(5);
    s.insert(10) ;
    s.insert(20) ;
    s.insert(30) ;
    // first way to print set
    for(int i:s){
        cout<<i<<" " ;
    }
    cout<<endl;
    // second way of printing set
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" " ;
    }
    cout<<endl ;
    // Third way of printing set
    for(auto it=s.rbegin();it!=s.rend();it++){
        cout<<*it<<"  " ;
    }
    cout<<endl ;
    // to search element in set
    auto it = s.find(20)  ;
    if(it!=s.end()){
        cout<<"Element exist in the set"<<endl ;
    }
    else{
        cout<<"The element does not exist in the set"<<endl ;
    }
    // clear remove all the element from the set
    // s.clear() ;
    // cout<<s.size()<<endl;
    
    // deleting element using erase.
    auto its = s.find(20) ;
    // s.erase(its,s.end()) ;
 
//    for(int i:s){
//         cout<<i<<" " ;
//     }
    cout<<endl ;
    // count in set
    int count = s.count(10) ; //output -> 1
    cout<<count<<endl;

    /*
        lower bound.
        1.If element exist in the set, then it return that element.
        2.If element does not exist in the set, then we return the slightly greatest element 
        than that array.
        3.If element is greatest then the greatest then the greatest element of set,
        then we return s.end() ;
    */ 
   auto it1 = s.lower_bound(5); 
   auto it2 = s.lower_bound(11); 
    cout<<*it1<<" "<<*it2<<" "<<endl ; 
    auto it3 = s.lower_bound(32) ;
    if(it3!=s.end()){
        cout<<*it3<<endl ;
    }
    else{
        cout<<"The element is greates then the greatest element of the set"<<endl ;
    }
   
    /*
        Upper bound.
        1.If element exist in the set, then it returns iterator to element slightly greater than it.
        2.If element does not exist in the set, then we return the slightly greatest element 
        than that array.
        3.If element is greatest then the greatest then the greatest element of set,
        then we return s.end() ;
    */ 

   auto it4 = s.upper_bound(5) ;
   auto it5 = s.upper_bound(22) ;
   cout<<*it4<<" "<<*it5<<endl ;

    
     
    return 0 ;
}