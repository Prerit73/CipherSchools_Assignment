#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        long long result = 1;
        for (int i = 2; i <= n; i++)
        {
            result *= i;
        }
        return result;
    }
}
long long totalUniquePaths(int R, int C)
{
    return factorial(R + C - 2) / (factorial(R - 1) * factorial(C - 1));
}
int main()
{
    cout << totalUniquePaths(3, 7) << endl;
}