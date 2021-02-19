#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

int length(Node *head)
{
    int l = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

int intersection(Node *head1, Node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    Node *temp1; // make temp1 whose length is large
    Node *temp2;
    if (l1 > l2)
    {
        d = l1 - l2;
        temp1 = head1;
        temp2 = head2;
    }
    else
    {
        d = l2 - l1;
        temp1 = head2;
        temp2 = head1;
    }
    while (d)
    {
        temp1 = temp1->next;
        if (temp1 == NULL)
        {
            break;
        }
        d--;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
        {
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}

int main()
{
    Node *head1 = new Node(1);
    Node *head1node1 = new Node(2);
    Node *head1node2 = new Node(3);
    Node *head1node3 = new Node(4);
    Node *head1node4 = new Node(5);
    Node *head1node5 = new Node(6);

    head1->next = head1node1;
    head1node1->next = head1node2;
    head1node2->next = head1node3;
    head1node3->next = head1node4;
    head1node4->next = head1node5;

    Node *head2 = new Node(9);
    Node *head2node1 = new Node(10);

    head2->next = head2node1;
    head2node1->next = head1node4;


    cout << intersection(head1, head2);
}