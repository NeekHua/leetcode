#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		if (buildings.empty()) return{};
		multiset<pair<int, int>> st;
		for (auto b : buildings) {
			st.insert(make_pair(b[0], -b[2]));
			st.insert(make_pair(b[1], b[2]));
		}
		vector<vector<int>> ret;
		multiset<int> height{ 0 };
		int m = 0;
		for (auto s : st) {
			if (s.second < 0) height.insert(-s.second); // ¾ØÐÎ×ó²à
			else height.erase(height.find(s.second)); // ¾ØÐÎÓÒ²à
			if (m != *height.rbegin())
				ret.push_back({ s.first, *height.rbegin() });
			m = *height.rbegin();
		}
		return ret;
	}


};
int main() {
	vector<vector<int>> points(5, vector<int>(3, 0));
	int x[5][3] = {
		{ 2,9,10 },
		{ 3,7,15 },
		{ 5,12,12 },
		{ 15,20,10 },
		{ 19,24,8 } };
	for (int i = 0, m = 0; i <points.size(), m<5; i++, m++)
	{
		for (int j = 0, n = 0; j < points[0].size(), n<3; j++, n++)
		{
			points[i][j] = x[m][n];
		}
	}
	Solution *sol = new Solution;
	vector<vector<int>> result;
	result = sol->getSkyline(points);
	delete sol;
	system("pause");
	return 0;
}