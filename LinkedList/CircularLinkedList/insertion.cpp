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
    new_node->next = new_node;
    *last = new_node;
}