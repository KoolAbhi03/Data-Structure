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
bool pairWithSum(Node *root, int key)
{
    stack<Node *> st1;
    stack<Node *> st2;

    bool done1 = false, done2 = false;
    Node *curr1 = root, *curr2 = root;
    int val1 = 0, val2 = 0;

    while (true)
    {
        while (!done1)
        {
            if (curr1 != NULL)
            {
                st1.push(curr1);
                curr1 = curr1->left;
            }
            else
            {
                if (st1.empty())
                    done1 = true;
                else
                {
                    curr1 = st1.top();
                    st1.pop();
                    val1 = curr1->data;
                    curr1 = curr1->right;
                    done1 = true;
                }
            }
        }
        while (!done2)
        {
            if (curr2 != NULL)
            {
                st2.push(curr2);
                curr2 = curr2->right;
            }
            else
            {
                if (st2.empty())
                    done2 = true;
                else
                {
                    curr2 = st2.top();
                    st2.pop();
                    val2 = curr2->data;
                    curr2 = curr2->left;
                    done2 = true;
                }
            }
        }
        if (val1 != val2 && (val1 + val2 == key))
        {
            cout << "pair found " << val1 << " " << val2 << endl;
            return true;
        }
        else if (val1 + val2 < key)
            done1 = false;
        else if (val1 + val2 > key)
            done2 = false;

        if (val1 >= val2)
            return false;
    }
}
int main()
{
    /*
                15
                / \
            10 20
            / \ / \
            8 12 16 25 */
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    int target = 41;
    if (pairWithSum(root, target) == false)
        cout << "\nNo such values are found\n";
    return 0;
}