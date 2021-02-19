#include <bits/stdc++.h>
using namespace std;

class DoubleNode
{
public:
    int data;
    DoubleNode *next;
    DoubleNode *prev;

    DoubleNode(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
DoubleNode *takeInput()
{
    int data;
    cin >> data;

    DoubleNode *head = NULL;
    DoubleNode *tail = NULL;
    while (data != -1)
    {
        DoubleNode *newNode = new DoubleNode(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(DoubleNode *head)
{

    DoubleNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    DoubleNode *head = takeInput();
    print(head);
}