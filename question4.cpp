#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
bool isBalancedTree(Node *root, int *height)
{
    if (root == NULL)
        return true;
    int ln = 0, rl = 0;
    if (isBalancedTree(root->left, &ln) == false)
        return false;
    if (isBalancedTree(root->right, &rl) == false)
        return false;
    *height = max(ln, rl) + 1;
    int ans = abs(ln - rl);
    if (ans == -1 || ans == 0 || ans == 1)
        return true;
    else
        return false;
}
bool isBalanced(Node *root)
{
    int height = 0;
    return isBalancedTree(root, &height);
}
int main()
{
    Node *a = new Node(10);
    Node *b = new Node(2);
    Node *c = new Node(2);
    Node *d = new Node(4);
    Node *e = new Node(3);
    Node *f = new Node(3);
    Node *g = new Node(4);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    cout<<isBalanced(a);
    return 0;
}