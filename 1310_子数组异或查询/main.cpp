#include<iostream>
#include<vector>
using namespace std;

//有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。
//
//对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li + 1] xor ... xor arr[Ri]）作为本次查询的结果。
//
//并返回一个包含给定查询 queries 所有结果的数组。

class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int>result;
		for (int  i = 0; i < queries.size(); i++)
		{	
			vector<int>temp;
			temp.assign(queries[i].begin(),queries[i].end());
			result.push_back((arr[temp[0]]) ^ (arr[temp[1]]));
		}

		return result;
	}
};
int main() {
	vector<int>temp1 = { 1,3,4,8 };
	vector<vector<int>> temp2 = { { 0,1 },{ 1,2 },{ 0,3 },{ 3,3 } };
	Solution sol;
	vector<int>result;
	result=sol.xorQueries(temp1, temp2);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}