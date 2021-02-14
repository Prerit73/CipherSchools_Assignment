#include<bits/stdc++.h>
using namespace std;

int firstocc(vector<int> nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }else{
                if(mid==0 || nums[mid-1]!=target){
                    return mid;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
    int lastocc(vector<int> nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }else{
                if(mid==nums.size()-1 || nums[mid+1]!=target){
                    return mid;
                }else{
                    low=mid+1;
                }
            }
        }
        return -1;
    }

    int main(){
        int n;
        cout<<"No. of elements ";
        cin>>n;
        vector<int> nums;
        for(int i=0;i<n;i++){
            int data;
            cin>>data;
            nums.push_back(data);
        }
        int target;
        cout<<"Enter the number you want to search ";
        cin>>target;
        int first=firstocc(nums,target);
        int last=lastocc(nums,target);
        cout<<"First occurrence= "<<first<<" Last occurrence= "<<last<<endl;

    }