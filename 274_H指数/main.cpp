#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int h = 0, i = citations.size()-1;
		while (i>=0 &&citations[i]>h)
		{
			h++;
			i--;
		}
		return h;
	}
};
int main() {
	vector<int>citation;
	int temp[] = { 0,1 };
	for (int i = 0; i < sizeof(temp)/sizeof(temp[0]); i++)
	{
		citation.push_back(temp[i]);
	}
	Solution *sol = new Solution;
	int result;
	result=sol->hIndex(citation);
	cout << result << endl;
	delete sol;
	return 0;
}