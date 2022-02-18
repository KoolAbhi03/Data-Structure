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
void preAndSucc(Node *root, Node *&pre, Node *&succ, int key)
{
    if (root == NULL)
        return;
    if (root->data == key)
    {
        if (root->left != NULL)
        {
            Node *temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;
            pre = temp;
        }
        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            succ = temp;
        }
        return;
    }
    if (root->data > key)
    {
        succ = root;
        preAndSucc(root->left, pre, succ, key);
    }
    else
    {
        pre = root;
        preAndSucc(root->right, pre, succ, key);
    }
}
int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    Node *pre = NULL, *suc = NULL;

    preAndSucc(root, pre, suc, 65);
    if (pre != NULL)
        cout << "Predecessor is " << pre->data << endl;
    else
        cout << "No Predecessor";

    if (suc != NULL)
        cout << "Successor is " << suc->data;
    else
        cout << "No Successor";
    return 0;
}