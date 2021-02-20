#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&s,int element){
    if(s.size()==0 || s.top()>=element){
        s.push(element);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,element);
    s.push(val);
    return;
    
}

void sort(stack<int> &s){
    if(s.size()==1)
    return ;
    
    int element=s.top();
    s.pop();
    sort(s);
    insert(s,element);
    return;
}
int main(){
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(2);

    sort(s);
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
}