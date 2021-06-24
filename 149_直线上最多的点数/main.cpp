#include<iostream>
#include<vector>
#include<unordered_map>
#include<Windows.h>
using namespace std;
class Solution {
public:
	//最大公约数
	int gcd(int a, int b)
	{
		return b ? gcd(b, a%b) : a;
	}
	int maxPoints(vector<vector<int>>& points) {
		int n = points.size();
		if (n <= 2)
			return n;
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			if (ret >= n - i || ret > n / 2)
			{
				break;
			}
			unordered_map<int, int>mp;
			for (int j = i + 1; j < n; j++)
			{
				int x = points[i][0] - points[j][0];
				int y = points[i][1] - points[j][1];
				if (x == 0)
				{
					y = 1;
				}
				else if (y == 0)
				{
					x = 1;
				}
				else {
					if (y < 0)
					{
						x = -x;
						y = -y;
					}
					int gcdXY = gcd(abs(x), abs(y));
					x /= gcdXY, y /= gcdXY;
				}
				mp[y + x * 20001]++;
			}
			int maxn = 0;
			for (auto&[_, num] : mp) {
				maxn = max(maxn, num + 1);
			}
			ret = max(ret, maxn);
		}
		return ret;
	}
};
int main() {
	vector<vector<int>> points(6,vector<int>(2,0));
	int x[6][2] = {
		{1,1},
		{3,2},
		{5,3},
		{4,1},
		{2,3},
		{1,4}};
	for (int i=0,m=0; i <points.size(),m<6; i++,m++)
	{
		for (int j =0,n=0; j < points[0].size(),n<2; j++,n++)
		{
			points[i][j] = x[m][n];
		}
	}

	Solution sol;
	int result;
	result = sol.maxPoints(points);
	cout << result << endl;
	return 0;
}