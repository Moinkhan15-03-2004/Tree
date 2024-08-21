#include<iostream>
#include<climits>
#include<queue>

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
        if(root==NULL) return ;// base case
        
        cout<<root->val<<" ";// work
        displayTree(root->left);// call 1
        displayTree(root->right);// call 2
    }
    void preorder(Node* root){
        if(root==NULL) return ;// base case
        
        cout<<root->val<<" ";// work
        preorder(root->left);// call 1
        preorder(root->right);// call 2
    }
        void Inorder(Node* root){
        if(root==NULL) return ;// base case
        
        Inorder(root->left);// call 1
        cout<<root->val<<" ";// work
       Inorder(root->right);// call 2
    }
            void Postorder(Node* root){
        if(root==NULL) return ;// base case
        
       Postorder(root->left);// call 1
       Postorder(root->right);// call 2
        cout<<root->val<<" ";// work
    }
 void nthLevel(Node* root,int curr,int level){    if(root==NULL) return ;// base case
    if(curr==level){
         cout<<root->val<<" ";//root
         return;
    }
       nthLevel(root->left,curr+1,level);// call 1
      nthLevel(root->right,curr+1,level);// call 2
        }
         void nthLevelRev(Node* root,int curr,int level){    if(root==NULL) return ;// base case
    if(curr==level){
         cout<<root->val<<" ";//root
         return;
    }
     nthLevelRev(root->right,curr+1,level);// call 2
      nthLevelRev(root->left,curr+1,level);// call 1
        }
        int levels(Node* root){
            if(root==NULL) return 0;
            return 1 + max(levels(root->left),levels(root->right));

        }
             void levelOrder(Node* root){
            int n = levels(root);
            for(int i=1;i<=n;i++){
                nthLevelRev(root,1,i);
                cout<<endl;
            }
        }
        void levelOrder(Node* root){
            int n = levels(root);
            for(int i=1;i<=n;i++){
                nthLevel(root,1,i);
                cout<<endl;
            }
        }
        // this is best method for finding Level order traversal using queue
        void levelOrderQueue(Node* root){
           queue<Node*>q;
          q.push(root);
           while(q.size()>0){
            Node* temp = q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left!=NULL) q.push(temp->left);// if we interchange the line then it print in reverse order
            if(temp->right!=NULL) q.push(temp->right);

           }
           cout<<endl;
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
       displayTree(a);
       preorder(a);
       Postorder(a);
    //  nthLevel(a,1,1);// it print first level
    //  nthLevel(a,1,2);// it print second level
    //  nthLevel(a,1,3);// it print third level
    // in Leetcode level is not given so use like this 
    levelOrder(a);
    levelOrderQueue(a);
    }