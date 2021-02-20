#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int n;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        n = 0;
    }
    void push(int val)
    {
        q2.push(val);
        n++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop()
    {
        q1.pop();
        n--;
    }
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return n;
    }
    bool empty(){
        return n==0;
    }
};

int main()
{
    Stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}