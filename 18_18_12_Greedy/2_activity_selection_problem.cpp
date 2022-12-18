/*
    Problem Statement: Activity selection problem.
    
    Input1: {
        {1,2},{2,3},{5,7},{3,8}
    }
    Output:3



    Explanation: Total number of activity that can place in above input is 3.

    Note: machine can compute only one activiy at a time, if there are activity that may occur at same time or interval then we can only 
    execute one activity in that time.

    Input2:

    {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

     Output: {1, 4} {5, 7} {8, 11} {12, 14}


    Input3:

    {
        {3,8},{2,4},{1,3},{10,11}
    }
    

    Output:(1,3),(3,8),(10,11)
    
*/ 
    

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Activity{
    int start;
    int finish;
};

bool activityCompare(Activity a1,Activity a2){
    return a1.finish<a2.finish;
}
// approach:
// todo sort the array with respect to increasing finishing time
// todo: if starting time of current activity is greater of equal to finishing time of previos activity, then only we include in the solutions
void activity_selection(vector<Activity>v){
    sort(v.begin(),v.end(),activityCompare);
    int i=0;
    cout<<v[i].start<<" "<<v[i].finish<<endl;
    for(int j=1;j<v.size();j++){
        if(v[j].start>=v[i].finish){
            cout<<v[j].start<<" "<<v[j].finish<<endl;
            i=j;
        }
    }
}

// calling function

int main(){
    vector<Activity> jobs =
    {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };
    // output {1, 4} {5, 7} {8, 11} {12, 14}
    
    activity_selection(jobs);
    return 0 ;
 
}

    