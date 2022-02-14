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
int maxWidthUsingBFS(Node *root)
{
    if (root == NULL)
        return 0;
    int maxWidth = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();

        maxWidth = max(count, maxWidth);
        while (count--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return maxWidth;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);
    cout << "Maximum width is " << maxWidthUsingBFS(root) << endl;
    return 0;
}