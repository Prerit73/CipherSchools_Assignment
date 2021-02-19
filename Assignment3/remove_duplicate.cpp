#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(){
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
void removeAllDuplicates(Node *&head)
{
    Node *dummy = new Node();

    dummy->next = head;
    Node *prev = dummy;
    Node *current = head;

    while (current != NULL)
    {

        while (current->next != NULL && prev->next->data == current->next->data)
            current = current->next;

        if (prev->next == current)
            prev = prev->next;

        else
            prev->next = current->next;

        current = current->next;
    }

    head = dummy->next;
}
int main()
{
    Node *head = takeInput();
    cout<<"Current Elements"<<endl;
    print(head);
    cout<<endl;
    removeAllDuplicates(head);
    cout<<"After Removing duplicate"<<endl;
    print(head);
}