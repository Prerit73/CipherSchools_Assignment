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

Node *sort_(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *mid = getMid(head);
    Node *left = sort_(head);
    Node *right = sort_(mid);
    
    return merge(left, right);
}

Node *merge(Node *list1, Node *list2)
{
    Node *dummyHead(0);
    Node *ptr = dummyHead;
    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            ptr->next = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    if (list1)
        ptr->next = list1;
    else
        ptr->next = list2;

    return dummyHead->next;
}

Node *getMid(Node *head)
{
    Node *midPrev = NULL;
    while (head!=NULL && head->next!=NULL)
    {
        if(midPrev==NULL){
            midPrev=head;
        }else{
            midPrev=midPrev->next;
        }
        //midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    Node *mid = midPrev->next;
    midPrev->next = NULL;
    return mid;
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
    Node* head=takeInput();
    head=sort_(head);print(head);
}
