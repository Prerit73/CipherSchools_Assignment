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
 
Node *addTwo(Node *head1, Node *head2)
{
    Node *dummy=new Node();
    Node *temp=dummy;
    int carry=0;
    while(head1 != NULL || head2 != NULL || carry){
        int sum=0;
        if(head1!=NULL){
            sum+=head1->data;
            head1=head1->next;
        }
        if(head2 != NULL){
            sum+=head2->data;
            head2=head2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node *node_=new Node(sum%10);
        temp->next=node_;
        temp=temp->next;
    }
    return dummy->next;
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
int main(){
    Node *head1=takeInput();
    Node *head2=takeInput();
    print(addTwo(head1,head2));

}