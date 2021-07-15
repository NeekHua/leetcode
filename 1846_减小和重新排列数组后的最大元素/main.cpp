#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
	int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		if (arr[0] != 1) arr[0] = 1;
		for (int k=0;k<arr.size()-1;k++)
		{
			if (arr[k + 1] - arr[k] > 1) {
				arr[k + 1] = arr[k] + 1;
			}
		}
		int result = arr[arr.size()-1];
		return result;
	}
};
int main() {
	vector<int> num1{ 73,98,9 };
	Solution *sol = new Solution;
	int result;
	result = sol->maximumElementAfterDecrementingAndRearranging(num1);
	cout << result << endl;
	delete sol;
	system("pause");
	return 0;
}