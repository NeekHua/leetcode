#include<iostream>
#include<vector>

#include<string>
#include <utility>
#include<map>
using namespace std;
class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int max = 0;
		int temp = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (nums[i]==nums[j])
				{
					continue;
				}
				else
				{
					temp = nums[i] ^nums[j];
					if (temp>max)
					{
						max = temp;
					}
				}
			};
		}
		return max;
	}
};

int main() {

	vector<int>temp = { 14,70,53,83,49,91,36,80,92,51,66,70 };
	Solution sol;
	int result;
	result = sol.findMaximumXOR(temp);
	cout << result << endl;
	return 0;
}