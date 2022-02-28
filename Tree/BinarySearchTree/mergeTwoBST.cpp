#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *right = NULL;
    Node *left = NULL;
    Node(int data)
    {
        this->data = data;
    }
};
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void merge(Node *root1, Node *root2)
{
    stack<Node *> s1, s2;
    Node *curr1 = root1, *curr2 = root2;
    if (root1 == NULL)
    {
        inorder(root2);
        return;
    }
    if (root2 == NULL)
    {
        inorder(root1);
        return;
    }
}