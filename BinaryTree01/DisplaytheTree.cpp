#include<iostream>
#include<climits>

using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->left = NULL;
        this->right =NULL;
    }
};
    void displayTree(Node* root){
        if(root==NULL) return;
        cout<<root->val<<" ";// Answer will be 1 2 4 5 3 6 7
        displayTree(root->left);
        displayTree(root->right);
    }
    int sum (Node* root){
        if(root==NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    int  size(Node* root){
        if(root==NULL) return 0;
        return 1+ size(root->left) + size(root->right);
    }
    int maxInTree(Node* root){
        if(root==NULL) return 0;
        int lMax = maxInTree(root->left);
        int rMax = maxInTree(root->right);
        return max(root->val,max(lMax,rMax));
    }
    // level of Binary Tree
    int level(Node* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }


    int main(){
        Node* a = new Node(1);
        Node* b = new Node(2);
        Node* c = new Node(3);
        Node* d = new Node(4);
        Node* e = new Node(5);
        Node* f = new Node(6);
        Node* g = new Node(7);
        a->left = b;
        a->right = c;
        b->left = d;
        b->right = e;
        c->left = f;
        c->right = g;// connect the tree
       cout<<size(a);
        cout<<endl;
        cout<<sum(a);
        cout<<endl;
        cout<<maxInTree(a)<<endl;
        cout<<level(a);
    

    }