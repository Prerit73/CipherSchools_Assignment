
#include <bits/stdc++.h>
using namespace std;


int findPlatform(vector<int> arr, vector<int> dep)
{
	// Sort arrival and departure arrays
	sort(arr.begin(),arr.end());
	sort(dep.begin(),dep.end());
    int n=arr.size();


	int platform_needed = 1, res = 1;
	int i = 1, j = 0;


	while (i < n && j < n) {

		if (arr[i] <= dep[j]) {
			platform_needed++;
			i++;
		}

		else if (arr[i] > dep[j]) {
			platform_needed--;
			j++;
		}

		if (platform_needed > res)
			res = platform_needed;
	}

	return res;
}

int main()
{
	vector<int> arr = { 900, 940, 950, 1100, 1500, 1800 };
	vector<int> dep = { 910, 1200, 1120, 1130, 1900, 2000 };

	cout << "Minimum Number of Platforms Required = "
		<< findPlatform(arr, dep);
	return 0;
}
