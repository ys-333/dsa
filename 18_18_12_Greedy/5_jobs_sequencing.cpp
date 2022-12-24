/*
    Problem Statement: Jobs Sequencing problem.


    Approach:

    vector<int>jobs{
        {1,100},{1,30}{1,80},{4,70}
    }

   Output: 170
*/ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
    int deadline;
    int profit;
};

bool sortWithProfit(Job j1,Job j2){
    return j1.profit>j2.profit ;
}


int max_profit(vector<Job>jobs){
    sort(jobs.begin(),jobs.end(),sortWithProfit);
    int n = jobs.size();
    vector<int>result(n,-1);
    vector<bool>slot(n,false);

    int res = 0;
    for(int i=0;i<n;i++){
        // in this loop, we check for free slot from end.
        for(int j=jobs[i].deadline-1;j>=0;j--){
            if(slot[j]==false){
                result[j] = i;
                res+=jobs[i].profit;
                slot[j] = true ;
                break;
            }
        }
    }
    return res;
}

int main(){
    vector<Job>jobs1{
        {4,70},{1,80},{1,30},{1,100}
    };

    vector<Job>jobs2{
        {2,50},{2,60},{3,20},{3,30}
    };
    vector<Job>jobs3{
        {2,100},{1,50},{2,10},{1,20},{3,30}
    };
    vector<Job>jobs4{
         {2,5},{2,60},{3,30},{3,40}
    };
    cout<<max_profit(jobs1)<<endl;
    cout<<max_profit(jobs2)<<endl;
    cout<<max_profit(jobs3)<<endl;
    cout<<max_profit(jobs4)<<endl;
    return 0 ;
}















/*
    This approach fails in this case

    {2,5},{2,60},{3,30},{3,40};

    This algorithm would give output as

    output:105

    But original output is 130

    todo since here we use the approach that, job with closest deadline will be executed first and then we consider the profit too.

*/ 


/*
    Problem Statement: Jobs Sequencing problem.


    Approach:

    vector<int>jobs{
        {1,100},{1,30}{1,80},{4,70}
    }

    vector<bool>isJobDone(jobs.size(),false);
    int time = 0;
    int maxDeadLine = jobs[n-1].deadline;
    while(time<maxDeadline){
        int closestDeadline = INT_MAX;
        int i=0;
        int current_max = INT_MIN ;
        while(i<jobs.size()){
            if(jobs[i].deadline>time&&jobs[i].deadline<=closestDeadline){
                current_max = max(current_max,jobs[i].profit);
                closestDeadline = jobs[i].deadline ;
                isJobDone[i] = true ;
            }
            i++;
        }
        res+=current_max ;
        time++ ;
    }
*/ 

// #include<iostream>
// #include<climits>
// #include<algorithm>
// #include<vector>
// using namespace std;
// struct Job{
//     int deadline;
//     int profit;
// };

// bool sortJobs(Job j1,Job j2){
//     return j1.deadline<j2.deadline ;
// }

// int max_profit(vector<Job>jobs){
//     int res =0; // to store the final result
//     int time = 0; // activit start from 0 hour and then activity with closest deadline are perform first
//     sort(jobs.begin(),jobs.end(),sortJobs); 

//     int n = jobs.size() ;  //total no. of jobs

//     vector<bool>isJobsDone(n,false); // to keep track of job which has been done

//     int maxDeadline = jobs[n-1].deadline ;
    
//     while(time<maxDeadline){
//         int current_res = INT_MIN;
//         int j=0;
//         int closestDealine = INT_MAX;
//         int lastJobdone =-1 ;
//         while(j<n){
            
//             if(isJobsDone[j]==false&&jobs[j].deadline>time&&jobs[j].deadline<=closestDealine){
//                 isJobsDone[j] = true ;
//                 current_res = max(current_res,jobs[j].profit);
//                 closestDealine = jobs[j].deadline ;
//                 if(lastJobdone!=-1){
//                     isJobsDone[lastJobdone] = false ;
//                 }
//                 lastJobdone = j;
//             }
            
//             j++;
//         }

//         if(current_res!=INT_MIN){
//             res+=current_res ;
//         }
//         time++ ;
//     }
//     return res;
// }
    


// int main(){
//     vector<Job>jobs1{
//         {4,70},{1,80},{1,30},{1,100}
//     };

//     vector<Job>jobs2{
//         {2,50},{2,60},{3,20},{3,30}
//     };
//     vector<Job>jobs3{
//         {2,100},{1,50},{2,10},{1,20},{3,30}
//     };
//     cout<<max_profit(jobs1)<<endl;
//     cout<<max_profit(jobs2)<<endl;
//     cout<<max_profit(jobs3)<<endl;
//     return 0 ;
// }
