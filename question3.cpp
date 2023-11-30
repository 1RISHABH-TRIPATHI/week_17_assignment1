#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node(int val)
        {
            this->val=val;
            left=right=NULL;
        }
};
bool isSameTree(Node* p,Node* q) 
{
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    if(p->val != q->val) return false;
    bool lst=isSameTree(p->left, q->left);
    if(lst==false) return false;
    bool rst= isSameTree(p->right,q->right);
    if(rst==false) return false;
    return true;
}
Node* invertTree(Node* root) {
    if(root==NULL) return NULL;
    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;    
    }
bool isSymmetric(Node* root) 
{
    if(root==NULL) return true;
    invertTree(root->left);
    bool flag=isSameTree(root->left,root->right);
    invertTree(root->left);
    return flag;
}
int main()
{
    Node *a=new Node(10);
    Node *b=new Node(2);
    Node *c=new Node(2);
    Node *d=new Node(4);                 
    Node *e=new Node(3);
    Node *f=new Node(3);
    Node *g=new Node(4);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    cout<<isSymmetric(a);
    return 0;
}