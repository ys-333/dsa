#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

// the first value in pair indicates the element value,
// the first value in second pair indecates the array index
// the second value in second pair indicates the element index in that array

typedef pair<int,pair<int,int>>pp ;


vector<int>mergeKArrays(vector<vector<int>>arr){
    priority_queue<pp,vector<pp>,greater<pp>>pq ;

    vector<int>output ;   

    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}}) ;
    }

    while(pq.empty()==false){
        pp curr = pq.top() ;
        pq.pop() ;

        output.push_back(curr.first) ;
        
        // i=> curr index of the array
        // j=> curr index of value

        int i = curr.second.first ;
        int j = curr.second.second ;
        if(j+1<arr[i].size()){
            pq.push({arr[i][j+1],{i,j+1}}) ;
        }
    }
    return output ;
}



void print(vector<int>v)
{
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" " ;
    }
    cout<<endl ;
}
int main(){
    vector<vector<int>>arr{
        {2,6,12},
        {1,9},
        {23,34,90,2000}
    } ;

    vector<int>output = mergeKArrays(arr) ;

    print(output) ;
    return  0 ;
}