/*
    Problem Statement: 
     - By default priority queue is max heap.
     - To make it min heap we have to use this syntax 
            priority_queue(int,vector<int>,greater<int>)pq ;
*/


#include<iostream>
#include<queue>
using namespace std;

class Person{
    public:
    int age,height ;
    Person(int a,int h){
        age = a;
        height = h ;
    }
};

struct MyCmp{
    bool operator()(Person  &p1,Person  &p2){
        p1.height<p2.height ;
    }
};

int main(){
    priority_queue<Person,vector<Person>,MyCmp>pq ;
    Person p1(20,6);
    Person p2(24,5) ;
    Person p3(22,7) ;
   pq.push(p1) ;
   pq.push(p2) ;
   pq.push(p3) ;

   while(pq.empty()==false){
       cout<<pq.top().height<<" " ;
       pq.pop() ;
   }
}
        


// #include<iostream>
// #include<queue>
// using namespace std;
// int main(){
//     int arr[] = {1,2,3,4} ;
//     priority_queue<int>pq(arr,arr+4) ;
//     // pq.push(10) ;
//     // pq.push(15) ;
//     // pq.push(12) ;
//     cout<<pq.size()<<" " ;
//     cout<<pq.top()<<" ";
//     while(pq.empty()==false){
//         cout<<pq.top()<<" " ;
//         pq.pop() ;
//     }
// }
        