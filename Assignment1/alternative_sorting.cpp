#include<bits/stdc++.h>
using namespace std;

void alternative_sorting(vector<int> &nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int i=0,j=n-1;
    while(i<j){
        cout<<nums[j--]<<" "<<nums[i++]<<" ";
    }
    if(n%2!=0){
        cout<<nums[i];
    }
}

int main(){
    int n;
    cout<<"Enter number of elements ";
    cin>>n;

    vector<int> nums;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    alternative_sorting(nums);
}