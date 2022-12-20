#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
struct Item
{
    /* data */
    float weight;
    float values;
};

bool compareItems(Item i1,Item i2){
    float ratio1 = i1.values/i1.weight;
    float ratio2 = i2.values/i2.weight;
    return ratio1>ratio2;
}

float max_values(vector<Item>items,int knapsack_cap){
    sort(items.begin(),items.end(),compareItems);
    
    float res = INT_MIN;
    int current_cap = 0;
    float current_values = 0;

    for(int i=0;i<items.size();i++){
        if(items[i].weight+current_cap<=knapsack_cap){
            current_cap+=items[i].weight;
            current_values+=items[i].values;
        }
        else{
            float remaining_weight = knapsack_cap - current_cap;
            float remaining_value = (items[i].values/items[i].weight)*remaining_weight;
            current_cap+=remaining_weight;
            current_values+=remaining_value;
        }
        res = max(res,current_values);
    }
    return res;
}

int main(){
    vector<Item>items{
        {30,500}
    };
    int knapsack_cap = 10 ;
    // vector<Item>items{
    //     {10,60},{20,100},{30,120}
    // };
    // int knapsack_cap = 50 ;
    cout<<max_values(items,knapsack_cap)<<endl;
    return 0;
}
