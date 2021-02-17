#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    int mid = 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            num += pos;
        }
        if (num < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
int main()
{
    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50},
    };
    cout << kthSmallest(matrix, 5);
}