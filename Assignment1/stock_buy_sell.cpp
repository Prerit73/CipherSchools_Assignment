#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &nums){
    int n=nums.size();
    int profit=0;
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]){
            profit+=nums[i]-nums[i-1];
        }
    }
    return profit;
}

int main(){
    int n;
    cout<<"Enter number ";
    cin>>n;
    
    vector<int> nums;

    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    cout<<"Maximum Profit is "<<maxProfit(nums);
}