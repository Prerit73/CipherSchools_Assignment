#include<bits/stdc++.h>
using namespace std;

int search(vector<int> nums,int low,int high, int key) 
{ 
    int n=nums.size();
	if (low > high) 
		return -1; 

	int mid = (low + high) / 2; 
	if (nums[mid] == key) 
		return mid; 

	if (nums[low] <= nums[mid]) { 
		
		if (key >= nums[low] && key <= nums[mid]) 
			return search(nums, low, mid - 1, key); 
		
		return search(nums, mid + 1, high, key); 
	} 

	if (key >= nums[mid] && key <= nums[high]) 
		return search(nums, mid + 1, high, key); 

	return search(nums, low, mid - 1, key); 
} 

int main() 
{ 
	vector<int> nums = { 4, 5, 6, 7, 8, 9, 1, 2, 3 }; 
	int key = 6; 
	int i = search(nums,0,nums.size()-1,key); 

	if (i != -1) 
		cout << "Index is " << i << endl; 
	else
		cout << "Key not found"; 
} 
