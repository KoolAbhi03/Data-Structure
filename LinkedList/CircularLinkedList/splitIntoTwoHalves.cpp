#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void split(Node *head, Node **head1, Node **head2)
{
    if (head == NULL)
        return;
    Node *fast = head, *slow = head;

    while (fast->next != head && fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    *head2 = slow->next;
    slow->next = head;
    *head1 = head;

    if (fast->next == head)
    {
        fast->next = *head2;
    }
    else
    {
        fast->next->next = *head2;
    }
}
void push(Node **head_ref, int data)
{
    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    /* If linked list is not NULL then
       set the next of last node */
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    *head_ref = ptr1;
}
void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        cout << endl;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}
int main()
{
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    push(&head, 15);

    cout << "Original Circular Linked List ";
    printList(head);

    split(head, &head1, &head2);

    cout << "\nFirst Circular Linked List ";
    printList(head1);

    cout << "\nSecond Circular Linked List ";
    printList(head2);
    return 0;
}
