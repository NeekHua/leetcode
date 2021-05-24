#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class Solution {
public:
	int kthLargestValue(vector<vector<int>>& matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> pre(m + 1, vector<int>(n + 1));
		vector<int> results;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ matrix[i - 1][j - 1];
				results.push_back(pre[i][j]);
			}
		}

		sort(results.begin(), results.end(), greater<int>());
		return results[k - 1];
	}
};



int main() {
	vector<vector<int>>temp1= { {5,2},{1,6} };
	int k = 1;
	Solution sol;
	int result;
	result = sol.kthLargestValue(temp1,k);
	cout << result << endl;
	return 0;
}