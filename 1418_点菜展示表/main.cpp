#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<string>> displayTable(vector<vector<string>>& orders){
		unordered_set<string>nameSet;//存菜名
		unordered_map<int, unordered_map<string, int>>foodsCnt; //桌号为key,value为桌号和菜名的并集
		for (auto &order: orders)
		{
			nameSet.insert(order[2]);
			int id = stoi(order[1]);
			++foodsCnt[id][order[2]];
		}

		int n = nameSet.size();
		vector<string>names;
		for (auto &name:nameSet )
		{
			names.push_back(name);
		}
		std::sort(names.begin(), names.end());
		// 提取桌号，并按餐桌桌号升序排列
		int m = foodsCnt.size();
		vector<int> ids;
		unordered_map<int, unordered_map<string, int>>::iterator iter;
		for (unordered_map<int, unordered_map<string, int>>::iterator iter = foodsCnt.begin(); iter != foodsCnt.end(); iter++) {
			ids.push_back(iter->first);
		}
		sort(ids.begin(), ids.end());

		// 填写点菜展示表
		vector<vector<string>> table(m + 1, vector<string>(n + 1));
		table[0][0] = "Table";
		copy(names.begin(), names.end(), table[0].begin() + 1);
		for (int i = 0; i < m; ++i) {
			int id = ids[i];
			auto &cnt = foodsCnt[id];
			table[i + 1][0] = to_string(id);
			for (int j = 0; j < n; ++j) {
				table[i + 1][j + 1] = to_string(cnt[names[j]]);
			}
		}
		return table;
	}

};
int main() {
	string temp_array[6][3] = {{"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"}};
	vector<vector<string>> orders(6, vector<string>(3,""));
	for (int i = 0, m = 0; i <orders.size(), m<6; i++, m++)
	{
		for (int j = 0, n = 0; j < orders[0].size(), n<3; j++, n++)
		{
			orders[i][j] = temp_array[m][n];
		}
	}
	Solution *sol = new Solution;
	vector<vector <string>> result;
	result = sol->displayTable(orders);
	//cout << result;
	delete sol;
	return 0;
}