
#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string str)
{
    int n = str.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {

        vector<bool> visited(256);

        for (int j = i; j < n; j++)
        {

            if (visited[str[j]] == true)
                break;

            else
            {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
        visited[str[i]] = false;
    }
    return res;
}

int main()
{
    string str = "geeksforgeeks";
    cout << "The input string is " << str << endl;
    int len = longestUniqueSubsttr(str);
    cout << "Length of the longest substring is " << len;
}
