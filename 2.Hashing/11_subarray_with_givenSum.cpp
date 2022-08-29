/*
    Input
    arr[] = {5,8,6,13,3,-1} ;
    Sum = 22

    Output - > Yes
    Explnation - > arr[2]+arr[3]+arr[4]

    Input
    arr[] = {3,2,5,6}
    Sum = 10
    Output - > No
*/
#include <iostream>
#include <unordered_set>
using namespace std;

bool subarraySum(int arr[], int n, int sum)
{
    // i would maintain unordered set of prefix sum
    unordered_set<int> s;
    int prefixSum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     prefixSum += arr[i];
    //     s.insert(prefixSum);
    // } instead of traversing array two time that is first time to insert prefix sum into unordered set and secnod to search the sum in hash table
    for(int i=0;i<n;i++){
        prefixSum+=arr[i] ;
        if(prefixSum==sum) return true ;
        if(s.find(prefixSum-sum)!=s.end()) return true ;
        s.insert(prefixSum) ;
    }
    return false;
}

int main()
{
    int arr[] = {5, 8, 6, 13, 3, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 20;
    bool res = subarraySum(arr, n, sum);
    if (res)
        cout << "Yes"
             << "\n";
    else
        cout << "No"
             << "\n";
    return 0;
}