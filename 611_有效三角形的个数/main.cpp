#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = i+1; j < n; j++){
				int left = j + 1, right = n - 1, k = j;
				while (left<=right){
					int mid = (left + right) / 2;
					if (nums[mid]<nums[i]+nums[j]){
						k = mid;
						left = mid + 1;
					}
					else{
						right = mid + 1;
					}
				}
				ans += k - j;
			}
		}
		return ans;
	}
};
int main() {
	vector<int> num1{ 2,2,3,4};
	Solution* sol = new Solution;
	int result;
	result = sol->triangleNumber(num1);
	cout << result << endl;
	delete sol;
	system("pause");
	return 0;
}