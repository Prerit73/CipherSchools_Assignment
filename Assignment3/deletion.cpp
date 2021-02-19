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

void deletion(Node* &head,int target){
    Node* temp=head;
    while(temp->next->data!=target){
        temp=temp->next;
    }
    Node *todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}
int main()
{
    Node *head = takeInput();
    cout<<"Current Elements"<<endl;
    print(head);
    cout<<endl;
    cout<<"Enter the element you want you delete"<<endl;
    int target;
    cin>>target;
    deletion(head,target);
    print(head);
}