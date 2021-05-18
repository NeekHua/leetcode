#include<iostream>
#include<vector>
using namespace std;
class Solution {

public:
	int countTriplets(vector<int> arr) {
		int n = arr.size();
		vector<int> s(n + 1);
		for (int i = 0; i < n; ++i) {
			s[i + 1] = s[i] ^ arr[i];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = j; k < n; ++k) {
					if (s[i] == s[k + 1]) {
						++ans;
					}
				}
			}
		}
		return ans;
	}
};


int main() {
	vector<int>temp1 = { 2, 3, 1, 6, 7 };
	Solution sol;
	int result;
	result = sol.countTriplets(temp1);
	cout << result << endl;
	return 0;
}