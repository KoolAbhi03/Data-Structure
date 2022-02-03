/*Input:
List1: 5->6->3 // represents number 563
List2: 8->4->2 // represents number 842
Output:
Resultant list: 1->4->0->5 // represents number 1405
Explanation: 563 + 842 = 1405*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;

    new_node->next = *head;
    *head = new_node;
}

Node *add(Node *first, Node *second)
{
    Node *res = NULL, *temp, *prev = res;
    int carry = 0, sum;

    while (first || second)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);

        carry = sum >= 10 ? 1 : 0;

        sum = sum % 10;
        temp = newNode(sum);

        if (res == NULL)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        prev->next = newNode(carry);

    return res;
}

Node *reverse(Node *head)
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

    return head;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *res = NULL;
    Node *first = NULL;
    Node *second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    cout << "Second List is ";
    printList(second);

    first = reverse(first);
    second = reverse(second);

    res = add(first, second);
    res = reverse(res);
    cout << "Final List is ";
    printList(res);
}