/*
    Problem Statement: Implement K Stack in an array
*/

/*
    Here in this approach we used arr, next,and top which are all array.
    arr --> push the data into it
    next --> act as referece to go forward and backward,as when object is invoked it gives all the free space in array
    but when element is started pushing in the stack then it store the element below top element of stack and that store the index of another element
    top --> store the indxe of topmost element.
*/

#include <iostream>
using namespace std;
class Kstack
{
    int *arr;
    int *next;
    int *top;
    int free = 0;
    int n, k;

public:
    Kstack(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        top = new int[k];
        // in next array we store the index of next block of array as in 0 index we store 1 and in 1 we store 2 and so onl
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
    }
    // to push the element into stack
    void push(int x, int sn);
    int pop(int sn);
    int size(int sn);
};
void Kstack::push(int x, int sn)
{
    if (free == -1)
    {
        cout << "Overflow"
             << "\n";
        return;
    }
    int i = free;
    free = next[i];
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = x;
}
int Kstack::pop(int sn)
{
    if (top[sn] == -1)
    {
        cout << "Underflow" << endl;
        return -1;
    }
    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}

int Kstack::size(int sn)
{
    int prev = top[sn];
    int count = 0;
    while (prev != -1)
    {
        prev = next[prev];
        count++;
    }
    return count;
}

void solve()
{
    Kstack s(9, 3);
    s.push(100, 2);
    s.push(100, 2);
    s.push(100, 2);
    s.push(100, 2);
    s.push(100, 2);
    s.push(100, 2);
    s.push(100, 0);
    s.push(100, 0);
    s.push(100, 0);
    s.push(100, 0);
    s.push(100, 0);
}
int main()
{
    solve();
    return 0;
}

/*
    Efficient but not flexible and cache friendly as we are statically allocating space to each stack
*/
/*
    First Approach:-
    1.It's not cache friendly as here we are statically allocated memory for
    space for each stack
    2.Their begin index as (sn-1)*n/k and  their end index as sn*n/k-1.
    3.So using these condition we push or pop element from respective stack.
    4.So if we are calling push operation then with value we need to sent stack number also.
    5.And we maintain another array called top of size of k which hold the index of top element of each kth stack.

*/

/*
    #include <iostream>
using namespace std;
class Kstack
{
    //
    //     whenever we create object we need to pass
    //     n --> Size of array
    //     k ---> Size of stack
    //
int *arr;
int *top;
int n;
int k;

public:
Kstack(int n, int k)
{
    // dynamically create array
    this->n = n;
    this->k = k;
    arr = new int[n];
    top = new int[k];
    // Then allocate intital top of each stack like 0 3 6 --> this are basically starting index of array
    for (int i = 0; i < k; i++)
    {
        top[i] = i * n / k - 1;
    }
}
// Push operation for k stack
void push(int x, int sn)
{
    if (sn > k)
    {
        cout << "sn should be equal to 0 and less than k" << endl;
        return;
    }
    if (top[sn - 1] == (sn * n) / k - 1)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        int index = top[sn - 1] + 1;
        arr[index] = x;
        top[sn - 1] = index;
    }
}
// Pop operation for k stack
void pop(int sn)
{
    if (top[sn - 1] == ((sn - 1) * (n / k) - 1))
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        top[sn - 1]--;
    }
}
int tops(int sn)
{
    if (top[sn - 1] == ((sn - 1) * n) / k - 1)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return arr[top[sn - 1]];
}
int size(int sn)
{
    // current top - first index +1
    return top[sn - 1] - (sn - 1) * n / k;
}
}
;
*/