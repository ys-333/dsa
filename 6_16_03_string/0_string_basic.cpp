#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name = "yashwant";
    // cout << name << endl;
    // give us length of string
    int len = name.size();
    cout << len << endl;
    // find some char or word in given sentence or string
    cout << name.find('w') << endl;
    cout << name.find("yash") << endl;
    // substring of string substr(beginIndex,lengh) ;
    cout << name.substr(1, 4) << endl;
    return 0;
}