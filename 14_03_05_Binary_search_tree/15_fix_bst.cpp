/*
    Problem Statement: Fix a BST with two nodes swapped.
    Input:  
                        20
                        /\
                       60 80
                       /\  /\
                      4 10 8 100

    Output: Swap nodes with key 60 and 8 and print the new bst.
*/
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    int lCount ;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
        // lCount = 0 ;
    }
} ;

void inorderTraversal(Node *root,vector<Node*>&v){
    if(root==NULL){
        return ;
    }
    inorderTraversal(root->left,v) ;
    v.push_back(root) ;
    inorderTraversal(root->right,v) ;
}

void inorder(Node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left) ;
    cout<<root->key<<" " ;
    inorder(root->right) ;
}

int main(){
    Node *root = new Node(20) ;
    root->left = new Node(60) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(10) ;
    root->right =new Node(80);
    root->right->left = new Node(8) ;
    root->right->right = new Node(100) ;
    vector<Node *>v ;
    vector<Node *>s ;
    inorder(root) ;
    cout<<endl ;
    inorderTraversal(root,v) ;
    int j ;
    for(int i=0;i<v.size();i++){
        bool flag = false ;
        if(v[i]->key<v[i-1]->key){
            flag = true ;
             j=i-1 ;
            while(j>=0&&v[i]->key<v[j]->key){
                j-- ;
            }
        }

        if(flag==true){
            s.push_back(v[i]) ;
            s.push_back(v[j+1]) ;
        }
    }
    int temp = s[0]->key ;
    s[0]->key = s[1]->key ;
    s[1]->key = temp ;
        
    inorder(root) ;
    cout<<endl ;
    return 0 ;
}

/*
    Solove using lower bound and upper bound

    void swapNodes(Node *root,int lower_bound,int upper_bound,vector<Node*>&v){
    if(root==NULL){
        return ;
    }
    if(root->key<lower_bound||root->key>upper_bound){
        v.push_back(root) ;
        return  ;
        // return false ;
    }
    
    swapNodes(root->left,lower_bound,root->key,v) ;
    swapNodes(root->right,root->key,upper_bound,v) ;
    // if(!swapNodes(root->left,lower_bound,root->key,v)||!swapNodes(root->right,root->key,upper_bound,v)){
    //     return false ;
    // }
    // return true ;
}

int main() {
    // Node *root = NULL ;
    Node *root = new Node(60) ;
    root->left =  new Node(8) ;
    root->left->left =  new Node(4) ;
    root->left->right =  new Node(10) ;
    root->right = new Node(80) ;
    root->right->left = new Node(20) ;
    root->right->right = new Node(100)
    ;
    
    int lower_bound  =  INT_MIN ;
    int upper_bound = INT_MAX;
    
    vector<Node*>v ;
    
    swapNodes(root,lower_bound,upper_bound,v);
    
    
    cout<<"Pre swapping inorder traversal "<<endl ;
    print(root) ;
    cout<<endl ;
    
    if(v.size()==1){
        cout<<"1"<<endl ;
        swap(v[0]->key,root->key) ;
    }
    else{
        cout<<"this executed"<<endl ;
        swap(v[0]->key,v[1]->key) ;
    }
    
    cout<<"Post swapping inorder traversal "<<endl ;
    print(root) ;
    cout<<endl ;
*/ 