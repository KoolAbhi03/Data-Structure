#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    bool rightThreaded;
    Node(int data) { this->data = data; }
};
Node *leftMost(Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}
void inorder(Node *root)
{
    Node *curr = leftMost(root);
    while (curr != NULL)
    {
        cout << curr->data << " ";
        if (curr->rightThreaded)
            curr = curr->right;
        else
            curr = leftMost(curr->right);
    }
}