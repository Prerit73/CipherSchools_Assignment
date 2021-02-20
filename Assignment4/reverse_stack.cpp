#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s,int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int topElement=s.top();
    s.pop();
    insertAtBottom(s,element);
    s.push(topElement);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int element=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,element);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
}