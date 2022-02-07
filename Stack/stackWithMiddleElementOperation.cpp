/* NOTE
1) push() which adds an element to the top of stack.
2) pop() which removes an element from top of stack.
3) findMiddle() which will return middle element of the stack.
4) deleteMiddle() which will delete the middle element.
*/
#include <bits/stdc++.h>
using namespace std;

class myStack
{
    struct Node
    {
        int num;
        Node *next;
        Node *prev;

        Node(int num)
        {
            this->num = num;
        }
    };
    Node *head = NULL;
    Node *middle = NULL;
    int size = 0;

public:
    void push(int x)
    {
        Node *new_node = new Node(x);
        if (size == 0)
        {
            head = new_node;
            middle = new_node;
            size++;
            return;
        }
        head->next = new_node;
        new_node->prev = head;
        new_node->next = NULL;
        head = new_node;
        if (size % 2 == 1)
            middle = middle->next;
        size++;
    }
    void pop()
    {
        if (size == 0)
        {
            cout << "empty stack" << endl;
            return;
        }
        if (size == 1)
        {
            head = NULL;
            middle = NULL;
            size--;
            return;
        }

        head = head->prev;
        head->next = NULL;
        if (size % 2 == 0)
            middle = middle->prev;
        size--;
    }
    int findMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        return middle->num;
    }
    void deleteMiddle()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                head = NULL;
                middle = NULL;
            }
            else if (size == 2)
            {
                head = head->prev;
                middle = middle->prev;
                head->next = NULL;
            }
            else
            {
                middle->next->prev = middle->prev;
                middle->prev->next = middle->next;
                if (size % 2 == 0)
                {
                    middle = middle->prev;
                }
                else
                {
                    middle = middle->next;
                }
            }
            size--;
        }
    }
};
int main()
{
    myStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    // st.pop();
    // st.pop();
    // st.pop();
    cout << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << st.findMiddle() << endl;
    return 0;
}