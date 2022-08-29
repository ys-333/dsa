/*
    a[] = {15,20,5,15} ;
    b[] = {15,15,15,20,10} ;

    Output - > 4 (array would like ---->[15,20,5,10])

    a[] = {10,12,15};
    b[] = {18,12};

    Output - -> 4  [10,12,15,19]
*/
#include <iostream>
#include <unordered_set>
using namespace std;
int countUnion(int a[], int b[], int n, int m)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }
    return s.size();
}
int main()
{
    int a[] = {3, 3, 3};
    int b[] = {3, 3};
    int n = 3, m = 2;
    int res = countUnion(a, b, n, m);
    cout << res << endl;
    return 0;
}