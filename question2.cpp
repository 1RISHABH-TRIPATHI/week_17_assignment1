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
int findMinimum(Node* root)
{
    if(root==NULL) return INT8_MAX;
    return min(root->val,min(findMinimum(root->left),findMinimum(root->right)));
}
int main()
{
    Node *a=new Node(10);
    Node *b=new Node(7);
    Node *c=new Node(15);
    Node *d=new Node(6);
    Node *e=new Node(9);
    Node *f=new Node(1);
    Node *g=new Node(17);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    int product=findMinimum(a);
    cout<<product;
    return 0;
}