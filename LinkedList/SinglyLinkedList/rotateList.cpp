#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
void push(Node **head, int data)
{
    Node *new_node = new Node();

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void rotate(Node **head, int k)
{
    if (k == 0)
        return;

    Node *current = *head, *kth_Node = *head;
    for (int i = 1; i < k; i++)
    {
        current = current->next;
    }
    kth_Node = current;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = *head;
    *head = kth_Node->next;
    kth_Node->next = NULL;
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
int main()
{
    Node *head = NULL;

    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);

    cout << "Given linked list \n";
    printList(head);
    rotate(&head, 1);

    cout << "\nRotated Linked list \n";
    printList(head);

    return (0);
}