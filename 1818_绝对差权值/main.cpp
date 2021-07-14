#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
	static const int mod = 1000000007;
	int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
		vector<int>rec(nums1);
		sort(rec.begin(), rec.end());
		int sum = 0, maxn = 0;
		int n = nums1.size();
		for (int i = 0; i < n; i++)
		{
			int diff = abs(nums1[i] - nums2[i]);
			sum = (sum + diff) % mod;
			int j = lower_bound(rec.begin(), rec.end(), nums2[i] )- rec.begin();
			if (j<n)
			{
				maxn = max(maxn, diff - (rec[j] - nums2[j]));
			}
			if (j>0)
			{
				maxn = max(maxn, diff - (nums2[i] - rec[j - 1]));
			}
		}
		return (sum - maxn + mod) % mod;
	}
};
int main() {
	vector<int> num1{ 1,7,5 };
	vector<int> num2{2,3,5};
	Solution *sol = new Solution;
	int result;
	result = sol->minAbsoluteSumDiff(num1,num2);
	cout << result << endl;
	delete sol;
	system("pause");
	return 0;
}