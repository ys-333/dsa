#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 16;
    int curr_sum = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    while (curr_sum != sum)
    {
        if (curr_sum < sum)
        {
            curr_sum += arr[i];
            i++;
        }
        else
        {
            curr_sum -= arr[j];
            j++;
        }
        if (curr_sum == sum)
        {
            cout << "exist" << endl;
        }
        if (i > n)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "not exist" << endl;

    return 0;
}