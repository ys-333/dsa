/*
    Problem Statement: To find median stream of array.

    int arr[] = {20,10,30,7} ;
    Output:     25,16,10,12.5,15

    int arr[] = {20,10,30,7} ;
    Output :     20 15 20 15




    Approach:

        Here we use augumunted binary search tree with Nodes containing size and lCount.
            1) We insert element into binary search tree.
            2) If size==1, then we print the root value.
            3) If size is even then we find median as:
                median = root->size/2+1
                
                And then we find kLargest for medain and median -1.

            4) If size is odd, then we find kth element 
                where k = root->size/2+1
            

    Time Complexity: O(nlog(n))
*/ 
#include <iostream>
using namespace std;
struct Node{
    float key ;
    Node *left,*right ;
    int lCount  ;
    int size  ;
    Node(float value){
        key = value ;
        left = right = NULL ;
        lCount = 0 ;
        size = 1 ;
    }
} ;

Node *insert(Node *root,int val){
    if(root==NULL){
        return new Node(val) ;
    }
    if(root->key>val){
        root->lCount+=1 ;
        root->size+=1 ;
        root->left = insert(root->left,val) ;
    }
    if(root->key<val){
        root->size+=1 ;
        root->right = insert(root->right,val) ;
    }
    return root ;
}

float kLargest(Node *root,int k,int n){
    if(k>n){
        return -1 ;
    }
    if(root->lCount+1==k){
        return root->key ;
    }
    if(root->lCount>=k){
        return kLargest(root->left,k,n) ;
    }
    if(root->lCount<k){
        return kLargest(root->right,k-root->lCount-1,n) ;
    }
}

void print(Node *root){
    if(root==NULL){
        return ;
    }
    print(root->left) ;
    cout<<root->size<<" " ;
    print(root->right) ;
}

int main() {
    int arr[] = {20,10,30,7} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    Node *root = NULL ;
    for(int i=0;i<n;i++){
        root = insert(root,arr[i]) ;
        if(root->size==1){
            cout<<root->key<<" " ;
        }
        else if(root->size%2==0){
            int median = (root->size)/2+1 ;
            float n1 = kLargest(root,median,n) ;
            float n2 = kLargest(root,median-1,n) ;
            cout<<(n1+n2)/2<<" " ;
        }
        else{
            int median = (root->size)/2+1 ;
            cout<<kLargest(root,median,n)<<" " ;
        }
    }
    // print(root) ;
    // cout<<endl ;
    // cout<<kLargest(root,7,n) ;
    return 0;
}



/*
    Time Complexity: O(n^2log(n))

    Approach 2: Using vectors


    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;

    void median(int arr[],int n) {
        vector<float>v ;
        for(int i=0;i<n;i++){
            v.push_back(arr[i]) ;
            sort(v.begin(),v.end()) ;
            if(v.size()%2==0){
                int index = v.size()/2 ;
                cout<<float((v[index-1]+v[index])/2)<<" " ;
                // cout<<median<<" " ;
            }
            else{
                cout<<v[v.size()/2]<<" " ;
            }
        }
    }

    int main(){
        int arr[] = {25,7,10,15,20} ;
        int n  = sizeof(arr)/sizeof(arr[0]) ;
        median(arr,n) ;
        return 0 ;
    }
*/ 
        
