#include <bits/stdc++.h>
using namespace std;
class Myhash
{
    int *arr;
    int cap, size;

public:
    Myhash(int c)
    {
        cap = c;
        size = 0;
        for (int i = 0; i < cap; i++)
        {
            arr[i] = -1;
        }
    }
    bool insert(int key);
    bool del(int key);
    bool search(int key);
    void display();
    int hash(int key)
    {
        return key % cap;
    }
};

bool Myhash::insert(int key)
{
    if (cap == size)
    {
        cout << "Hash Table is full" << endl;
        return false;
    }
    int i = hash(key);
    while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
    {
        i = (i + 1) % cap;
    }
    if (arr[i] == key)
        return false;
    else
    {
        arr[i] = key;
        size++;
        return true;
    }
}

bool Myhash::search(int key)
{
    int h = hash(key);
    int i = h;
    while (arr[i] != -1 && arr[i] != key)
    {
        i = (i + 1) % cap;
        if (i == h)
            return false;
    }
    if (arr[i] == key)
    {
        return true;
    }
    return false;
}

bool Myhash::del(int key)
{
    int h = hash(key);
    int i = h;
    while (arr[i] != -1)
    {
        i = (i + 1) % cap;
        if (i == h)
        {
            return false;
        }
        if (arr[i] == key)
        {
            arr[i] = -2;
            size--;
            return true;
        }
    }
    return false;
}

void Myhash::display()
{
    for (int i = 0; i < cap; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    Myhash h(7);
    h.insert(49);
    h.insert(56);
    h.insert(72);
    if (h.search(56) == true)
        cout << "element exist in hash table" << endl;
    else
        cout << "element does not exist in hash table" << endl;
    h.del(56);
    if (h.search(56) == true)
        cout << "element exist in hash table" << endl;
    else
        cout << "element does not exist in hash table" << endl;
    h.display();
    return 0;
}