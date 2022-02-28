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
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
void inorderSuccessor(Node *root, Node *target, Node *&res)
{
    if (root == NULL)
        return;
    inorderSuccessor(root->left, target, res);
    if (root->data > target->data && res == NULL)
    {
        res = root;
        return;
    }
    inorderSuccessor(root->right, target, res);
}
int main()
{
    Node *root = NULL, *temp, *res = NULL;

    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);
    temp = root->left->right->right;

    // Function Call
    inorderSuccessor(root, temp, res);
    if (res != NULL)
        cout << "\n Inorder Successor of "
             << temp->data << " is " << res->data;
    else
        cout << "\n Inorder Successor doesn't exist";
    return 0;
}