#include <bits/stdc++.h>
using namespace std;

int bsearch(vector<int> nums, int key)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == key)
            return mid;
        else if (nums[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int index = bsearch(nums, 5);
    if (index != -1)
        cout << "Element found at " << index + 1;
    else
        cout << "Element not found";
}