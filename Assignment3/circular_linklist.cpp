#include <bits/stdc++.h>
using namespace std;
class CircularNode
{
public:
    int data;
    CircularNode *next;

    CircularNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};
CircularNode *takeInput()
{
    int data;
    cin >> data;

    CircularNode *head = NULL;
    CircularNode *tail = NULL;

    while (data != -1) // take input till we give -1
    {
        CircularNode *newNode = new CircularNode(data);
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
    tail->next=head;
    return head;
}
void print(CircularNode *head)
{

    CircularNode *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp!=head);
}
int main()
{
    CircularNode *head = takeInput();
    print(head);
}