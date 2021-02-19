#include<iostream>
using  namespace std;
template<typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Stack
{
    Node<T> *head;
    int count;
public:
Stack(){
    head=NULL;
    count=0;
}

int size(){
    return count;
}

bool isEmpty(){
    return head==NULL;
}

void push(T element){
    Node<T> *newNode=new Node<T>(element);
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
    count++;
}

T pop(){
    if(head==NULL){
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
    Node<T> *temp=head;
    head=head->next;
    T dataReturn=temp->data;
    delete temp;
    count--;
    return dataReturn;
}

T top(){
    if(head==NULL)
    {
        cout<<"Stack is Empty"<<endl;
    }
    return head->data;
}
    
};

int main(){
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
}