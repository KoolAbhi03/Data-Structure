#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = NULL;
void insertFront(int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    if (head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}

void insertEnd(int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

void deleteNode(int key)
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    Node *temp = head;
    Node *prev;
    if (head->data == key)
    {
        head = head->next;
        delete temp;
        return;
    }

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void countNode()
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "No of nodes = " << count << endl;
}

void printList()
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void reverse()
{
    Node *current = head, *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    Node *node = NULL;
    insertFront(5);
    insertFront(4);
    insertEnd(6);
    deleteNode(6);
    insertEnd(7);
    countNode();
    reverse();
    printList();
}