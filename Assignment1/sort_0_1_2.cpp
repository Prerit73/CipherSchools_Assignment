#include<bits/stdc++.h>
using namespace std;

void sortElements(vector<int>& nums) {
        int lo=0;
        int mid=0;
        int high=nums.size()-1;
        
        while(mid<=high)
        {    
            if(nums[mid]==0)
            {
                swap(nums[lo++],nums[mid++]);
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high--]);
            }
            else
                mid++;
        }
        for(int i=0;i<nums.size();i++)
            cout<<nums[i];
    }

    int main()
    {
        int n;
        cout<<"write number of elements "<<endl;
        cin>>n;
        vector<int> nums;
        for(int i=0;i<n;i++){
            int data;
            cin>>data;
            nums.push_back(data);
        }
        sortElements(nums);
    }