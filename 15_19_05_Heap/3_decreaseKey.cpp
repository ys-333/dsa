// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
struct Node{
    int key ;
    Node *left,*right ;
    Node(int data){
        key =data ;
        left = right = NULL ;
    }
} ;
class MinHeap{
    int *arr ;
    int cap ;
    int size ;
    // Node *root ; 
    public:
    MinHeap(int n){
        cap = n ;
        size = 0 ;
        arr =new int[n] ;
    }
 
    Node *binaryTree(int index){
        if(index>=size){
            return NULL ;
        }
        Node *root = new Node(arr[index]) ;
        root->left = binaryTree(2*index+1) ;
        root->right = binaryTree(2*index+2) ;
        return root ;
    }
    
    
    int left(int index){
        // return arr[2*index+1] ;
        return 2*index+1 ;
    }
    int right(int index){
        // return arr[2*index+2] ;
        return 2*index+2;
    }
    int parent(int index){
        // return arr[(index-1)/2] ;
        return (index-1)/2 ;
    }
    void insert(int x){
        if(cap==size){
            cout<<"overflow "<<endl ;
            return ;
        }
        arr[size] = x ;
        int index = size ;
        size++ ;
        while(x<arr[parent(index)]&&index>=0){
            swap(arr[index],arr[parent(index)]) ;
            index = parent(index) ;
        }
    }
    void print(){
        if(size==0){
            cout<<"empty heap "<<endl ;
            return ;
        }
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" " ;
        }
        cout<<endl ;
    }
    // recursive approach
    void heapify_down(int i){
        int lt =left(i) ;
        int rt = right(i) ;
        int smallest = i ;
        if(lt<size&&arr[lt]<arr[i]){
            smallest = lt ;
        }
        if(rt<size&&arr[rt]<arr[smallest]){
            smallest = lt ;
        }
        if(smallest!=i){
            swap(arr[i],arr[smallest]) ;
            heapify_down(smallest) ;
        }
    }
    void heapify_up(int i){
        int parent_idx = parent(i) ;
        if(parent_idx>=0&&arr[i]<arr[parent_idx]){
            swap(arr[i],arr[parent_idx]) ;
            heapify_up(parent_idx) ;
        }
    }
    
// to replace the existing key with the given key
    void replaceKey(int i,int x){
        if(i>=size){
            return ;
        }
      arr[i] = x ;
        heapify_up(i) ;
    }
    
    int getMin(){
        if(size==0){
            return INT_MAX ;
        }
        if(size==1){
            size-- ;
            return arr[size+1] ;
        }
            
        else{
            swap(arr[0],arr[size-1]) ;
            size-- ;
            heapify_down(0) ;
            return arr[size] ;
        }
    }
} ;
        

void print(Node *root){
    if(root==NULL){
        return ;
    }
    queue<Node*>q ;
    q.push(root) ;
    while(q.empty()==false){
        int count = q.size() ;
        while(count>0){
            auto temp = q.front() ;
            q.pop() ;
            cout<<temp->key<<" " ;
            if(temp->left!=NULL){
                q.push(temp->left); 
            }
            if(temp->right!=NULL){
                q.push(temp->right); 
            }
            count-- ;
        }
    }
}

int main() {
    MinHeap m(10) ;
    m.insert(10) ;
    m.insert(20) ;
    m.insert(40) ;
    m.insert(80) ;
    m.insert(100) ;
    m.insert(70) ;
    // m.insert(32) ;
    // m.insert(100) ;
    // m.insert(70) ;
    // m.insert(60) ;
    m.print() ;
    m.replaceKey(3,5);
    m.print() ;
    // cout<<m.getMin()<<endl ;
    return 0;
}