/*
    1.Print all subset of array -> code of this problem
    2.Original problem is --> given sum search that any subset of array has equal to that sum

*/
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
bool print(int arr[], int n, int curr, int index, int sum)
{
    if (index == n)
    {
        int num = curr;
        int res = 0;
        while (num != 0)
        {
            int rem = num % 10;
            cout << rem << endl;
            res += rem;
            num /= 10;
        }
        if (res == sum)
        {
            cout << res << endl;
            return true;
        }
        return false;
    }
    print(arr, n, curr, index + 1, sum);
    print(arr, n, curr * 10 + arr[index], index + 1, sum);
}
int main()
{
    // Write C++ code here
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n, 0, 0, 40);

    return 0;
}