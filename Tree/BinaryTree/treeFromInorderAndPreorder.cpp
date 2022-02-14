#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    char data;
    Node *right = NULL;
    Node *left = NULL;
    Node(char data)
    {
        this->data = data;
    }
};
int searchIndex(char str[], int start, int end, char value)
{
    for (int i = start; i <= end; i++)
        if (str[i] == value)
            return i;
    return -1;
}
Node *buildTree(char in[], char pre[], int start, int end)
{
    static int preIndex = 0;
    if (start > end)
        return NULL;

    Node *tNode = new Node(pre[preIndex++]);

    if (start == end)
        return tNode;

    int inIndex = searchIndex(in, start, end, tNode->data);

    tNode->left = buildTree(in, pre, start, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, end);

    return tNode;
}
void printInorder(Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    Node *root = buildTree(in, pre, 0, len - 1);

    /* Let us test the built tree by
    printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}