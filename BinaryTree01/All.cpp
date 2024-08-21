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
    int size(Node* root){
        if(root==NULL) return 0;
        return 1+size(root->left)+size(root->right);
    }
    void display(Node* root){
        if(root == NULL) return ;
        cout<<root->val<<" ";
        display(root->left);
        display(root->right);
    }
    int sum(Node* root){
        if(root==NULL) return 0;
        return root->val+sum(root->left)+sum(root->right);
    }
    int maxInTree(Node* root){
        if(root==NULL) return 0;
        int lMax = maxInTree(root->left);
        int Rmax = maxInTree(root->right);
        return max(root->val,(lMax,Rmax));
    }
    int level(Node* root){
        if(root==NULL) return 0;
        return 1+ (level(root->left),level(root->right));
    }
    void display(Node* root){
        if(root==NULL) return;
        cout<<root->val<<" ";
        display(root->left);
        display(root->right);
    }
    // int sum (Node* root){
    //     if(root==NULL) return 0;
    //     return root->val+sum(root->left) + sum(root->right);
    // }
    // int size(Node* root){
    //     if(root==NULL) return 0;
    //     return 1+size(root->left)+size(root->right);
    // }
    // int maxInTree(Node* root){
    //     if(root==NULL) return;
    //     int Lmax = maxInTree(root->left);
    //     int Rmax = maxInTree(root->right);
    //     return max(root->val,(Lmax,Rmax));
    // }



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