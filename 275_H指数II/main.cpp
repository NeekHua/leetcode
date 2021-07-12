#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int k = 0;
		int n = citations.size() - 1;
		while (n >= 0 && citations[n]>k )
		{
			n--;
			k++;
		}
		
		return k;
	}
};
int main() {
	vector<int>citation;
	int temp[] = { 0,1,3,5,6 };
	for (int i = 0; i < sizeof(temp) / sizeof(temp[0]); i++)
	{
		citation.push_back(temp[i]);
	}
	Solution *sol = new Solution;
	int result;
	result = sol->hIndex(citation);
	cout << result << endl;
	delete sol;
	system("pause");
	return 0;
}