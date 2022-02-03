#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x) { data = x; };
};

void addToEmptyList(Node **last, int data)
{
    Node *new_node = new Node(data);
    *last = new_node;
    (*last)->next = (*last);
}
void insertEnd(Node **last, int data)
{
    if (*last == NULL)
    {
        addToEmptyList(last, data);
        return;
    }

    Node *new_node = new Node(data);
    new_node->next = (*last)->next;
    (*last)->next = new_node;
    *last = new_node;
}
void insertFront(Node **last, int data)
{
    if (*last == NULL)
    {
        addToEmptyList(last, data);
        return;
    }

    Node *new_node = new Node(data);
    new_node->next = (*last)->next;
    (*last)->next = new_node;
}
void traverse(Node *last)
{
    Node *p;

    // If list is empty, return.
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Pointing to first Node of the list.
    p = last->next;

    // Traversing the list.
    do
    {
        cout << p->data << " ";
        p = p->next;

    } while (p != last->next);
}
int main()
{
    Node *last = NULL;

    addToEmptyList(&last, 6);
    insertFront(&last, 4);
    insertFront(&last, 2);
    insertEnd(&last, 8);
    insertEnd(&last, 12);

    traverse(last);

    return 0;
}