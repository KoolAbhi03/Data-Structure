#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node(int data) { this->data = data; }
};
void inorderWithStack(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
// NOTE:Inorder traversal without stack and recursion -- Morris Traversal
/* did not understand
void inorder_(node *root){
    if(root==NULL)
        return;
    node *temp=root,*pre;
    while (temp!=NULL)
    {
        if (temp->left==NULL)
        {
            printf("%d ",temp->data);
            temp=temp->right;
        }else{
            pre=temp->left;
            while (pre->right!=NULL && pre->right!=temp)
                pre=pre->right;

            if (pre->right==NULL){
                pre->right=temp;
                temp=temp->left;
            }else{
                pre->right=NULL;
                printf("%d ",temp->data);
                temp=temp->right;
            }
        }
    }
}
*/
int main()
{
    Node *root = new Node(1);
    root->right = new Node(2);
    root->left = new Node(3);
    root->right->right = new Node(4);
    root->right->left = new Node(5);

    inorderWithStack(root);
    return 0;
}