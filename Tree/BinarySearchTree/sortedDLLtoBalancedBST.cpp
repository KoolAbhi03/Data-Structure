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
int coundNodes(Node *root)
{
    int count = 0;
    Node *temp = root;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}
