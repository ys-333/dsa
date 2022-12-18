
// Problem Statement: To find minimum number of coins required to pay the given amount

// Input 1:
// amount= 57
// coins[] = {5,10,2,1};
// Output:7 coins

#include <bits/stdc++.h>
using namespace std;
int minCoins(int amount,int coins[],int n){
    sort(coins,coins+n,greater<int>());
    int res = 0;
    for(int i=0;i<n;i++){
        if(amount>=coins[i]){
            int q = floor(amount/coins[i]);
            res+=q;
            amount-=q*coins[i];
        }
        if(amount==0){
            break;
        }
    }
    return res;
}
int main() {
    int amount  = 58;
    int coins[] = {5,10,1,2};
    int n = 4;
    cout<<minCoins(amount,coins,n)<<endl;
    return 0;
}

// another approach
// int minCoins(int amount,int coins[],int n){
//     int res = 0 ;
//     int coinIndex = 0;
//     sort(coins,coins+n,greater<int>());
//     while(amount!=0){
//         if(amount>=coins[coinIndex]){
//             res++;
//             amount-=coins[coinIndex];
//             cout<<amount<<" ";
//         }
//         else{
//             coinIndex++;
//         }
//     }
//     cout<<endl;
//     return res;
// }