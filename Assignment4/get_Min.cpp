#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int topElement=s.top();
    if(topElement<element){
       s.pop();
       s.push(element);
       s.push(topElement);
       return;
    }
    s.push(element);
    return;
}

void getMin(stack<int> &s){
    if(s.empty()){
        return;
    }
    int element=s.top();
    s.pop();
    getMin(s);
    insert(s,element);
}
int main(){
    stack<int> s;
    s.push(2);
    s.push(6);
    s.push(1);
    s.push(4);

    getMin(s);
    cout << s.top() <<endl;
    
}