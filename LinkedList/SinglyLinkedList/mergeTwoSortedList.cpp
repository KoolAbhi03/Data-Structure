#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int data)
{
    Node *new_node = new Node();

    new_node->data = data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *head_ref)
{
    if (head_ref == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    while (head_ref != NULL)
    {
        cout << head_ref->data << " ";
        head_ref = head_ref->next;
    }
}

void MergeSort(Node **a, Node **b, Node **res)
{

    Node *tail = (*res);
    cout << "abcd" << endl;
    while (1)
    {
        if (*a == NULL)
        {
            // tail->next = *b;
            cout << "a" << endl;

            break;
        }
        if (*b == NULL)
        {
            // tail->next = *a;
            cout << "b" << endl;
            break;
        }
        if ((*a)->data <= (*b)->data)
        {
            push(res, (*a)->data);
            cout << (*a)->data << endl;
            (*a) = (*a)->next;
        }
        else
        {
            cout << (*b)->data << endl;
            push(res, (*b)->data);
            (*b) = (*b)->next;
        }
    }
}

int main()
{
    Node *a = NULL;
    Node *b = NULL;
    Node *res = NULL;
    push(&a, 14);
    push(&a, 55);
    push(&a, 60);
    push(&b, 23);
    push(&b, 44);
    push(&b, 69);
    MergeSort(&a, &b, &res);
    printList(res);
}