/*
    Problem Statement; First Circular Tour
    Input: petrol[] = {4,8,7,4}
     dist[] = {6,5,3,5}
    Output= 2

    Description:
        The element in petrol array gives petrol in that indxe
        The element in dist array gives dist between two petrol station
*/
#include <iostream>
using namespace std;
void firstCircularTour(int petrol[], int dist[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        int flag = 1;
        int curr_petrol = petrol[i];
        while (j != i)
        {
            if (curr_petrol < (j == 0 ? dist[n - 1] : dist[j - 1]))
            {
                flag = 0;
                break;
            }
            if (j == 0)
            {

                curr_petrol = curr_petrol - dist[j - 1] + petrol[n - 1];
            }
            else
            {
                curr_petrol = curr_petrol - dist[j - 1] + petrol[j];
            }
            j = (j + 1) % n;
        }
        if (flag == 1)
        {
            if (curr_petrol > (j == 0 ? dist[n - 1] : dist[j - 1]))
            {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    cout << "-1" << endl;
}
int main()
{
    // int petrol[] = {4, 8, 7, 4};
    // int dist[] = {6, 5, 3, 5};
    // int petrol[] = {4, 8};
    // int dist[] = { 5,6};
    int petrol[] = {8, 9, 4};
    int dist[] = {5, 10, 12};
    int n = sizeof(petrol) / sizeof(petrol[0]);
    firstCircularTour(petrol, dist, n);
    return 0;
}

/*
    This I code i re-written during my revison

    #include<iostream>
using namespace std;
void travel(int petrol[],int dist[],int n){
    int res ;
    int flag=0 ;
    for(int i=0;i<n;i++){
        flag =0 ;
        int curr_petrol = petrol[i] ;
        if(curr_petrol>dist[i]){
            int j =i ;
            while(curr_petrol>dist[j]){
                curr_petrol = curr_petrol-dist[j]+petrol[(j+1)%n] ;
                j = (j+1)%n ;
                if(j==i){
                    flag=1 ;
                  cout<<i+1<<endl ;
                    break ;
                }
            }
        }
        if(flag==1){
            break ;
        }
    }
    if(flag==0){
        cout<<"-1"<<endl ;
    }
       
}
int main(){
    int petrol[] = {4,8} ;
    int dist[] = {3,6} ;
    // int petrol[] = {4,8,7,4} ;
    // int dist[] = {6,5,3,5} ;
    int n = sizeof(dist)/sizeof(dist[0]) ;
    travel(petrol,dist,n) ;
    return 0 ;
}
*/ 