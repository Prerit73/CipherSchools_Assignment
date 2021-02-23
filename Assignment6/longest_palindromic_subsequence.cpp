#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(char *a, int i, int j)
{

    if (i == j)
        return 1;

    if (a[i] == a[j] && i + 1 == j)
        return 2;

    if (a[i] == a[j])
        return longestPalindromicSubsequence(a, i + 1, j - 1) + 2;

    return max(longestPalindromicSubsequence(a, i, j - 1), longestPalindromicSubsequence(a, i + 1, j));
}

int main()
{
    char a[] = "GEEKSFORGEEKS";
    int n = strlen(a);
    cout << "Length is" << longestPalindromicSubsequence(a, 0, n - 1);
}
