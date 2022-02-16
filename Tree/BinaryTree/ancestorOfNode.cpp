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
bool printAncestor(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    if (printAncestor(root->left, key) || printAncestor(root->right, key))
    {
        cout << root->data << " ";
        return true;
    }
    return false;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(9);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);
    printAncestor(root, 9);
    return 0;
}
