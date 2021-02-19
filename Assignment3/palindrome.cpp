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

Node *reverseList(Node *head)
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

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;
    while (slow != NULL)
    {
        if (head->data != slow->data)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    Node *head = takeInput();

    if (isPalindrome(head))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}