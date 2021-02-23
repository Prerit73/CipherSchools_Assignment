#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int a, b, target = 9;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            a = mp[target - nums[i]];
            b = i;
        }
        mp[nums[i]] = i;
    }
    cout<<"Index are "<<a<<" and "<<b;
}