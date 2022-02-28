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
void floorAndCeil(Node *root, int &floor, int &ceil, int key)
{
    while (root)
    {
        if (root->data == key)
        {
            ceil = floor = root->data;
            return;
        }
        if (root->data > key)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return;
}
void floorCeilBST(Node *root, int key)
{

    int floor = -1, ceil = -1;

    floorAndCeil(root, floor, ceil, key);

    cout << key << ' ' << floor << ' ' << ceil << '\n';
}
int main()
{
    Node *root = new Node(8);

    root->left = new Node(4);
    root->right = new Node(12);

    root->left->left = new Node(2);
    root->left->right = new Node(6);

    root->right->left = new Node(10);
    root->right->right = new Node(14);

    for (int i = 0; i < 16; i++)
        floorCeilBST(root, i);

    return 0;
}