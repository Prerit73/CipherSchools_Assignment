#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = nums1.size() - 1;
    m--;
    n--;
    while (n >= 0 && m >= 0)
    {
        if (nums1[m] > nums2[n])
        {
            nums1[i--] = nums1[m--];
        }
        else
        {
            nums1[i--] = nums2[n--];
        }
    }
    if (n >= 0)
    {
        while (i >= 0)
        {
            nums1[i--] = nums2[n--];
        }
    }
    if (m >= 0)
    {
        while (i >= 0)
        {
            nums1[i--] = nums1[m--];
        }
    }
    for (int i : nums1)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    merge(nums1,3,nums2,3);
}