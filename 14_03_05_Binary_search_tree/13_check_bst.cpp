/*
    Problem Statement: Check For BST.
    Input 1:   
                    10
                    /\
                   8 20
                     /\
                    13 24
    Output: YES.

    Input 2: 10
    Output: YES

    Input 3: NULL
    Output: YES.

    Input 4:        
                    20
                    /\
                  8   30
                      /\
                     18 35
    Output: NO.            

*/ 
#include<iostream>
#include<climits>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    int lCount ;
    Node(int key){
        this->key = key ;
        left = right = NULL ;
        lCount = 0 ;
    }
} ;
/*
    Solution 1:

    This method fail in some of test cases.

bool check(Node *root){
    if(root==NULL){
        return true ;
    }
    if(root->left==NULL&&root->right==NULL){
        return true ;
    }
    if(!(root->left->key<root->key)){
        return false ;
    }
    bool res1 = check(root->left);
    if(!(root->right->key>root->key)){
        return false;
    }
    bool res2 = check(root->right) ;
    return res1&&res2 ;
}
*/ 

// In this method we maintain prev and compare that prev with current node and if 
// that prev is greater than current node then we return false,otherwise we call for 
// right subtree.
// Solution 2
bool check1(Node *root, int &prev){
    if(root==NULL){
        return true ;
    }
    bool left = check1(root->left,prev) ;
    // in the first inorder traversal prev will be INT_MIN.
    if(root->key<prev){
        return false;
    }
    cout<<prev<<endl ;
    prev = root->key ;
    return left&&check1(root->right,prev) ;
}

/*
    In this methd we for root we get the maximum element from the left
    child and minimum element from right child and if root is 
    greater than the maximum element from left child and smaller than minimum
    element from right child. So we return true, otherwise return false.
*/ 
// int res ;
// int res=INT_MIN ;
//////////////////////////////////////////////////////
// Solution 3
// Helper function
int maxElement(Node *root){
    if(root==NULL){
        return INT_MIN ;
    }
    int lMax =   maxElement(root->left) ;
    int rMax =  maxElement(root->right) ;
    return (max(root->key,max(lMax,rMax))) ;
}
// Helper function
int minElement(Node *root){
    if(root==NULL){
        return INT_MAX;
    }
    int lMin = minElement(root->left) ;
    int rMin = minElement(root->right) ;
    return min(root->key,min(lMin,rMin)) ;
}
bool check2(Node *root){
    if(root==NULL){
        return true ;
    }
    if(root->left!=NULL&&maxElement(root->left)>root->key){
        return false ;
    }
    if(root->right!=NULL&&minElement(root->right)<root->key){
        return false ;
    }
    if(!check2(root->left)||!check2(root->right)){
        return false ;
    }
    return true ;
}


int main(){
    Node *root = new Node(20) ;
    root->left = new Node(8) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(9) ;
    root->right =new Node(30);
    root->right->left = new Node(22) ;
    root->right->right = new Node(35) ;
    // int prev = INT_MIN ;
    // cout<<check1(root,prev) ;
    cout<<check2(root) ;
    return 0 ;
}



/*
        It works but not good code practice
        void maxLeft(Node *root,int &resLeft){
    if(root==NULL){
        return  ;
    }
    resLeft = max(root->key,resLeft) ;
    maxLeft(root->left,resLeft) ;
    maxLeft(root->right,resLeft) ;
}

// to get minimum element in right sub tree

void minRight(Node *root,int &resRight){
    if(root==NULL){
        return  ;
    }
    resRight = min(root->key,resRight) ;
    minRight(root->left,resRight) ;
    minRight(root->right,resRight) ;
}


bool checkBst(Node *root){
    if(root==NULL){
        return true ;
    }
    if(root->left==NULL&&root->right==NULL){
        return true ;
    }
    int resLeft = INT_MIN ;
    maxLeft(root->left,resLeft) ;
    
    int resRight = INT_MAX ;
    minRight(root->right,resRight) ;
    
    if(resLeft>root->key||resRight<root->key){
        return false ;
    }
    cout<<root->key<<" " ;
    return checkBst(root->left)&&checkBst(root->right) ;
}
    
    

*/ 
