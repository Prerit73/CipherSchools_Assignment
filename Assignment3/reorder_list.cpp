#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        Node(0);
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1) // take input till we give -1
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = newNode; // tail=tail->next
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *reverse(Node *head)
{
    Node *prev = NULL;

    while (head != NULL)
    {
        Node *Next = head->next;
        head->next = prev;
        prev = head;
        head = Next;
    }
    return prev;
}
void rearrange(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = NULL;

    head2 = reverse(head2);

    head = new Node(0);

    Node *curr = head;
    while (head1 || head2)
    {

        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }

        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    head = head->next;
}
int main()
{
    Node *head = takeInput();
    rearrange(head);
    print(head);
}