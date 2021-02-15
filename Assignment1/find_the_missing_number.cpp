#include<bits/stdc++.h>
using namespace std;

int getMissingNumber(vector<int> nums,int n){
    int total=(n*(n+1))/2;
    for(int i=0;i<nums.size();i++){
        total-=nums[i];
    }
    return total;
}

int main(){
    vector<int>nums={1,2,3,5,6};
    cout<<"Missing number is "<<getMissingNumber(nums,nums.size()+1);
}