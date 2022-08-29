/*
    Problem Statement: Map in C++ STL.
*/ 
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> m ;
    m.insert({1,"gfg"}) ;
    m.insert({10,"yashwant"}) ;
    m.insert({7,"singh"}) ;
    m[11] = "pawan" ;

    // when we assign value using [] this so if that value
    // does't exist that it's key is alloacted in the map.
    // cout<<m[9]<<endl ; so here it will allocate this key in map

    // First way to print the map
    for(auto it:m){
        cout<<it.first<<" "<<it.second<<"\n" ;
    }
    cout<<endl  ;
    // Second method to print the element of map
    for(auto it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<"  " ;
    }
    cout<<endl ;
    // find method in map
    auto it = m.find(10) ;
    if(it==m.end()){
        cout<<"Not Found"<<"\n" ;
    }
    else{
        cout<<"Found"<<"\n" ;
    }
    for(it;it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<" " ;
    }
    cout<<endl ;
    // Count in map
    if(m.count((*m.find(1)).first)==1){
        cout<<"Value is present in map"<<"\n" ;
    }
    else{
        cout<<"Value is not present in the map"<<"\n" ;
    }
    /*
        Lower bound and upper bound can give unexpected answer
        when we do something like:-
        map<int,string,greater<int>> m
    */ 
    // Lower Bound 
    auto it1 = m.lower_bound(2) ;
    auto it2 = m.lower_bound(10) ;
    cout<<(*it1).first<<" "<<(*it2).second<<endl ;
    // Upper bound
    auto it3 = m.upper_bound(10) ;
    auto it4 = m.upper_bound(2) ;
    auto it5 = m.upper_bound(1) ;
    cout<<" Upper Bound "<<(*it3).first<<(*it4).first<<(*it5).first<<endl ;

    // Erase function
    m.erase(m.find(10),m.end()) ;
    for(auto it:m ){
        // cout<<(*it).first<<" "<<(*it).second<<" " ;
        cout<<it.first<<" "<<it.second<<" " ;
    }
    return 0 ;
}



