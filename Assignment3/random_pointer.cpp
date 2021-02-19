#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node()
    {
        Node(0);
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
        random = NULL;
    }
};

Node *createClone(Node *head)
{
    Node *original = head;

    while (original != NULL && original->next != NULL)
    {
        Node *copy = new Node(original->data);
        Node *next = original->next;
        original->next = copy;
        copy->next = next;
        original = original->next->next;
    }
    original->next = new Node(original->data);
    original = head;
    while (original != NULL && original->next != NULL)
    {
        if (original->random != NULL)
        {
            original->next->random = original->random->next;
        }
        original = original->next->next;
    }

    original = head;
    Node *copy = head->next;
    Node *copyHead = head->next;

    while (original->next != NULL && copy->next != NULL)
    {
        original->next = original->next->next;
        copy->next = copy->next->next;
        original = original->next;
        copy = copy->next;
    }

    original->next = NULL;

    return copyHead;
}

void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " Random pointer of this node is "<<temp->random->data<<endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    head->next = node2;
    head->random = node3;

    node2->next = node3;
    node2->random = head;

    node3->next=node4;
    node3->random = node5;

    node4->next=node5;
    node4->random = node3;

    node5->random = node2;

    Node *newCloned = createClone(head);
    print(newCloned);
}