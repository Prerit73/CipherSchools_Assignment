#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums){
    int n=nums.size();
    int i=0,j=n-1;
    while (i<j)
    {
        if(nums[i]==1){
            swap(nums[i],nums[j--]);
        }
        else
        i++;
    }
}

int main(){
    vector<int> nums={0,1,0,1,1,1};
    solve(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
}