
#include <bits/stdc++.h>
using namespace std;

int Peak(vector<int> nums, int n)
{
	if (n == 1) 
    return nums[0];

	if (nums[0] >= nums[1])
		return 0;
    
	if (nums[n - 1] >= nums[n - 2])
		return n - 1;


	for (int i = 1; i < n - 1; i++) {
		if (nums[i] >= nums[i - 1] && nums[i] >= nums[i + 1])
			return i;
	}
    return 0;
}

int main()
{
	int n;
    cout<<"Enter number of elements "<<endl;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        nums.push_back(data);
    }
    int index=Peak(nums, n);
	cout << "Peak point is "<< nums[index];
	
}

