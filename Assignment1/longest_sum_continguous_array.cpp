#include<bits/stdc++.h>
using namespace std;

int largestSum(vector<int> nums){
    int res=nums[0];
    int maxEnding=nums[0];
    for (int i = 1; i <nums.size(); i++)
    {
        maxEnding=max(maxEnding+nums[i],nums[i]);
        res=max(res,maxEnding);
    }
    return res;
}

int main(){
    vector<int> nums={-2,-3,4,-1,-2,1,5,-3};
    cout<<largestSum(nums);
}