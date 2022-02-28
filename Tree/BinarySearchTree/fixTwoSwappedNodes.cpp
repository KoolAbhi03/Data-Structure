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
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void correctBSTUtil(Node *root, Node **first, Node **middle, Node **last, Node **prev)
{
    if (root)
    {
        correctBSTUtil(root->left, first, middle, last, prev);
        if (*prev && root->data < (*prev)->data)
        {
            if (!*first)
            {
                *first = *prev;
                *middle = root;
            }
            else
            {
                *last = root;
            }
        }
        *prev = root;
        correctBSTUtil(root->right, first, middle, last, prev);
    }
}
void correctBST(Node *root)
{
    Node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
    correctBSTUtil(root, &first, &middle, &last, &prev);
    if (first && last)
        swap(&(first->data), &(last->data));
    else if (first && middle)
        swap(&(first->data), &(middle->data));
}
void printInorder(Node *Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout << "  " << Node->data;
    printInorder(Node->right);
}
int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */

    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    cout << "Inorder Traversal of the original tree \n";
    printInorder(root);

    correctBST(root);

    cout << "\nInorder Traversal of the fixed tree \n";
    printInorder(root);

    return 0;
}