#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, int> ump;
    ump.insert({0, 10});
    ump.insert({2, 20});
    ump[1] = {30};
    for (auto it : ump)
    {
        cout << it.first << " " << it.second;
        cout << endl;
    }
    cout << endl;
    // I need to search and key 2 with value 20 in the unordered map
    int flag = 1;
    for (auto it : ump)
    {
        if (it.first == 7)
        {
            cout << it.second << endl;
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Key is not present in map" << endl;
    }
    if (ump.empty())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "false";
    }
    return 0;
}