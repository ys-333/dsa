/*
    Problem Statement: Fractional Knapsack

    here first value represent weight and second values represent values.

    So we need to print the maximum values keeping in mind that we don't cross the knapsack capacity 


    Input 1:
    {
        {50,600},{20,500},{30,400}
    }

    Knapsack Capacity = 70

    Output: 1140

    Input 2:
    {
        {10,60},{20,100},{30,120}
    }
    int knapsack_cap = 50 ;

    Output: 240

    Explanation: so we included the 0th and 1st index weight completly and for third index we only added the weight required
    current_weight =  10+20+20
    current_values = 60+100+120/30*20 = 240

*/ 

#include<iostream>
#include<climits>
#include<vector>
using namespace std;
struct item{
    int weight;
    int values;
};
int max_weight(vector<item>items,int knapsack_capacity){
    int res = INT_MIN;
    int n = items.size();
    for(int i=0;i<items.size();i++){
        int current_cap = items[i].weight;
        int current_values = items[i].values;
        int j = (i+1)%n;
        while (current_cap!=knapsack_capacity&&j!=i)
        {
            if(current_cap+items[j].weight<=knapsack_capacity){
                current_cap+=items[j].weight;
                current_values+=items[j].values;
            }else{
                int remaining_cap = knapsack_capacity - current_cap;
                current_cap+=remaining_cap;
                current_values+=(items[j].values/items[j].weight)*remaining_cap ;
            }
            res = max(res,current_values);
            j = (j+1)%n;
            
        }
    }
    return res;
        
}

int main(){
    vector<item>items{
        {50,600},{20,500},{30,400}
    };
    int knapsack_capacity = 70;
    cout<<max_weight(items,knapsack_capacity);
    return 0;

}


