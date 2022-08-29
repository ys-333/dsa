/*
    Chaining is done to avoid collision in hash table.
    The ideal load factor for hash table is  = 1 when n/m is equal
    So more the load factor more is chance of collision

*/

#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int bucket;
    list<int> *table;

public:
    Hash(int v);
    void insert(int key);
    void del(int key);
    int search(int key);
    void displayHash();
    int hash(int key)
    {
        return key % bucket;
    }
};
Hash::Hash(int v)
{
    this->bucket = v;
    table = new list<int>[bucket];
}

void Hash::insert(int key)
{
    int index = hash(key);
    table[index].push_back(key);
}

void Hash::del(int key)
{
    int index = hash(key);
    table[index].remove(key);
}

int Hash::search(int key)
{
    int index = hash(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
        {
            return 1;
        }
    }
    return 0;
}

void Hash::displayHash()
{
    list<int>::iterator itr;
    for (int i = 0; i < bucket; i++)
    {
        cout << i << " ";
        for (itr = table[i].begin(); itr != table[i].end(); itr++)
        {
            cout << " --> " << *itr;
        }
        cout << endl;
    }
}

int main()
{
    Hash myHash(7);
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);

    Hash h(7);
    for (int i = 0; i < n; i++)
        h.insert(a[i]);

    // delete 12 from hash table
    h.del(12);

    // display the Hash table
    h.displayHash();
    int res = h.search(27);
    if (res == 1)
        cout << "present" << endl;
    else
        cout << "not present" << endl;
}