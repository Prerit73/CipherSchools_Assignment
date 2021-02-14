#include <bits/stdc++.h>
using namespace std;

void printKSmallestNumber(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < k)
    {
        cout << "Invaid number ";
        return;
    }

    for (int i = k; i < n; i++)
    {
        int max_element = nums[k - 1];
        int max_position = k - 1;

        for (int j = k - 2; j >= 0; j--)
        {
            if (nums[j] > max_element)
            {
                max_element = nums[j];
                max_position = j;
            }
        }
        int currentElement = nums[i];

        if (max_element > currentElement)
        {

            int m = max_position;
            while (m < k - 1)
            {
                nums[m] = nums[m + 1];
                m++;
            }
            nums[k - 1] = currentElement;
        }
    }
    int ans=0;
    for(int i=0;i<k;i++){
        ans=max(ans,nums[i]);
    }
    cout<<ans;
}

int main()
{
    int n;
    cout << "Enter number of element ";
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        nums.push_back(data);
    }
    int k;
    cout << "Enter the smallest number you want to find ";
    cin >> k;
    printKSmallestNumber(nums, k);
}