/*
    Input
    a1[] = {10,15,20,40} ;
    a2[] = {5,6,6,10,15};
    Output:
    [5,6,6,10,10,15,15,20,40]
*/
#include <iostream>
using namespace std;
void mergeSort(int a1[], int a2[], int n1, int n2, int temp[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            temp[k] = a1[i];
            i++;
        }
        else
        {
            temp[k] = a2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        temp[k++] = a1[i];
        i++;
    }
    while (j < n2)
    {
        temp[k++] = a2[j];
        j++;
    }
}
int main()
{
    int a1[] = {10, 15, 20, 40};
    int a2[] = {5, 6, 6, 10, 15};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);
    int temp[n1 + n2];
    mergeSort(a1, a2, n1, n2, temp);
    for (auto x : temp)
    {
        cout << x << " ";
    }
    return 0;
}