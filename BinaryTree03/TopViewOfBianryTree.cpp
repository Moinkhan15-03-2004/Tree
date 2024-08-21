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

 Node* construct(int arr[],int n){
    queue<Node*>q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i=1;
    int j= 2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i]!=INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        if(j!=n && arr[j]!=INT_MIN) r= new Node(arr[j]);
        else r = NULL;
        temp->left = l;
        temp->right = r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
 }

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
        void leftBoundary(Node* root){
            if(root==NULL) return;
            if(root->left==NULL && root->right==NULL) return;
            cout<<root->val<<" ";
            leftBoundary(root->left);;
            if(root->left==NULL) leftBoundary(root->right);
        }
         void rightBoundary(Node* root){
            if(root==NULL) return;
            if(root->left==NULL && root->right==NULL) return;
            cout<<root->val<<" ";
            rightBoundary(root->right);
            if(root->right==NULL) leftBoundary(root->left);
        }
        // bottomBoundary
        void bottomBoundary(Node* root){
            if(root==NULL) return;
            bottomBoundary(root->left);
            bottomBoundary(root->right);
            if(root->left==NULL && root->right==NULL) cout<<root->val<<" ";// if this line is below the call then it print in reverse order
        }
                int level(Node* root){
            if(root==NULL) return 0;
            return 1 + max(level(root->left),level(root->right));

        }
         void nthLevel(Node* root,int curr,int level){    if(root==NULL) return ;// base case
    if(curr==level){
         cout<<root->val<<" ";//root
         return;
    }
       nthLevel(root->left,curr+1,level);// call 1
      nthLevel(root->right,curr+1,level);// call 2
        }
                void levelOrder(Node* root){
            int n = levelroot);
            for(int i=1;i<=n;i++){
                nthLevel(root,1,i);
                cout<<endl;
            }
        }

   void  HorLevel(Node* root,int& maxLevel){// it find the maximam top view of right side ke 2 se left side ke -2 tk find krega
    if(root==NULL) return;// base case
    minLevel = min(minLevel,level);
    minLevel = max(maxLevel,level);
    HorLevel(root->left,minLevel-1) // left me 1 minus ho rha hai
    HorLevel(root->right,minLevel+1) // right me 1 bad jayega
    HorLevel(root,minLevel,maxLevel,0);
    int horLevels = maxLevel - minLevel +1;
    vector<int>top(horLevels)
   }


    int main(){
        // construct
        int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,9,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8};
        int n = sizeof(arr)/sizeof(arr[0]);
        Node* root = construct(arr,n);
        // level order traversal
        int maxLevel = 0;
        int minLevel = 0;
        HorLevel(root,minLevel,maxLevel,0);
        int horlevels = maxLevel-minLevel+1;
        vector<int>top(horlevels,INT_MIN);
        topview(top,root,-minLevel);
        minHorLevel(root,minLevel);

    }