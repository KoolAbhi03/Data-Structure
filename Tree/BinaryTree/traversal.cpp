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
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    preorderTraversal(root);

    cout << "\nInorder traversal of binary tree is \n";
    inorderTraversal(root);

    cout << "\nPostorder traversal of binary tree is \n";
    postorderTraversal(root);

    return 0;
}