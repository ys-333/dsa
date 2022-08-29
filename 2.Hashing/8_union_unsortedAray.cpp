/*
    a[] = {15,20,5,15} ;
    b[] = {15,15,15,20,10} ;

    Output - > 4 (array would like ---->[15,20,5,10])

    a[] = {10,12,15};
    b[] = {18,12};

    Output - -> 4  [10,12,15,18]
*/
#include <iostream>
#include <vector>
using namespace std;
int countUnion(int a[], int b[], int n, int m)
{
    bool visited[m] = {false};
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        bool flag = 0;

        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;

        bool check = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j])
            {
                check = 1;
                v.push_back(a[i]);
                for (int k = 0; k < m; k++)
                {
                    if (a[i] == b[k])
                    {
                        visited[k] = true;
                    }
                }
                break;
            }
        }
        if (check == 0)
        {
            v.push_back(a[i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (visited[i] == false)
        {
            v.push_back(b[i]);
        }
    }

    for (int x : v)
    {
        cout << x << " ";
    }

    return v.size();
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


/*
vector<int> v; 
     for(int i=0;i<n;i++){
        int flag =1;
        for(int j=i-1;j>=0;j--){
            if(a[j]==a[i]){
                flag =0 ;
                break;
            }
        }
        if(flag==1){
            v.push_back(a[i]) ;
        }
    }
  
    for(int i=0;i<m;i++){
        int val = b[i] ;
        auto it = find(v.begin(),v.end(),val) ;
        if(it==v.end()){
            v.push_back(b[i]) ;
        }
    }
   cout<<v.size()<<endl ;*/