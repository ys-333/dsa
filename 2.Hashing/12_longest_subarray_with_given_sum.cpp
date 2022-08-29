/*
  Input
  int arr[] = {3,1,0,1,8,2,3,6};
  int sum = 5;
  Ouput: 4

   Input
   arr[] = {5,8,-4,-4,9,-2,2}
   sum = 0
   Output - > 3
   Explanation - >As there are two subarray that sum is equal to zero
       1)arr[1]+arr[2]+arr[3] = 0 and its size is 3
       2)arr[5]+arr[6] = 0  and it s size is 2
       Therefor output is 2
*/
#include <bits/stdc++.h>
using namespace std;
int longestSubarray(int arr[], int n, int sum)
{
  int res = 0;
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    count = 0;
    int s = 0;
    for (int j = i; j < n; j++)
    {
      s += arr[j];
      count++;
      if (s == sum)
      {
        res = max(res, count);
      }
    }
  }
  return res;
}
int main()
{
  int arr[] = {8, 3, 7};
  int sum = 15;
  int n = sizeof(arr) / sizeof(arr[0]);
  int res = longestSubarray(arr, n, sum);
  cout << res << endl;
  return 0;
}