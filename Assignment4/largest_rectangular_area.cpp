#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[], int n)
{
    stack<int> s;
    int res = 0;
    int tp;
    int curr;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();
            if (s.empty())
            {
                curr = arr[tp] * i;
            }
            else
            {
                curr = arr[tp] * (i - s.top() - 1);
            }
            res = max(res, curr);
        }
        s.push(i);
    }
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        if (s.empty())
        {
            curr = arr[tp] * n;
        }
        else
        {
            curr = arr[tp] * (n - s.top() - 1);
        }
        res = max(res, curr);
    }

    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = 7;
    cout << "Maximum Area " << getMaxArea(arr, n);
    return 0;
}
