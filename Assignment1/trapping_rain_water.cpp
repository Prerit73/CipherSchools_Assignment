#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
        int totalWater=0,n=height.size();
        if(n==0){
            return 0;
        }
        int left[n]; 
        left[0]=height[0];
      
        int right[n];
        right[n-1]=height[n-1];
        
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=1;i<n;i++){
            totalWater+=min(left[i],right[i])-height[i];
        }
        return totalWater;
    }
int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
}