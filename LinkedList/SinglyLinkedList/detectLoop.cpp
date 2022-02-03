#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;
};
typedef struct Node node;

node *createNode(int data)
{
    Node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void printList(node *head_ref)
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

void removeLoop(node *loop_node, node *head)
{
    int count = 1;
    node *ptr1 = loop_node, *ptr2 = loop_node;
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        count++;
    }
    ptr1 = head;
    ptr2 = head;
    for (int i = 0; i < count; i++)
    {
        ptr1 = ptr1->next;
    }

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = NULL;
}

bool detectAndRemoveLoop(node *head)
{
    node *slow = head, *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            removeLoop(slow, head);
            return true;
        }
    }
    return false;
}

bool method2(node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow == fast)
    {
        slow = head;
        if (slow == fast)
        {
            while (fast->next != slow)
                fast = fast->next;
        }
        else
        {
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}

int main()
{
    node *head = createNode(50);
    head->next = createNode(20);
    head->next->next = createNode(15);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}