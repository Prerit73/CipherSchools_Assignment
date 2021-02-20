#include <bits/stdc++.h>
using namespace std;

bool isMatching(char open, char close)
{
    return ((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']'));
}

bool isValid(string str)
{
    stack<char> s;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty())
                return false;

            char open = s.top();
            s.pop();
            if (!isMatching(open, str[i]))
                return false;
        }
    }
    if (s.empty())
        return true;
    return false;
}

int main()
{
    string str = "(((a+(b))+(c+d)))";

    if (isValid(str))
        cout << "Duplicate Found ";
    else
        cout << "No Duplicates Found ";
}