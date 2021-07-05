#include<iostream>
#include<string>
#include<map>
using namespace std;
//ÔØ×Ôhttps://blog.csdn.net/qq_41855420/article/details/89644525
class Solution {
public:
	string countOfAtoms(string formula) {
		string resStr = "";
		map<string, int>hashMap;
		myFunc(formula, 0, hashMap);
		for (auto &item:hashMap)
		{
			resStr += item.first;
			if (item.second>1)
			{
				resStr += to_string(item.second);
			}
		}
		return resStr;
	}
	int myFunc(string &formula, int nowIndex, map<string, int>&hashMap)
	{
		int formulaSize = formula.size();
		if (nowIndex>=formulaSize || formula[nowIndex]==')')
		{
			return nowIndex + 1;
		}
		while (nowIndex<formulaSize)
		{
			if (formula[nowIndex]=='(')
			{
				map<string, int>tempMap;
				nowIndex = myFunc(formula, nowIndex + 1, tempMap);
				int cnt = 0;
				while (nowIndex<formulaSize && formula[nowIndex]>='0' && formula[nowIndex]<='9')
				{
					cnt = cnt * 10 + formula[nowIndex++] - '0';
				}
				if (cnt>0)
				{
					for (auto &item:tempMap)
					{
						item.second*=cnt;
					}
				}
				for (auto &item:tempMap)
				{
					hashMap[item.first] += item.second;
				}
			}
			else if (formula[nowIndex] == ')')
			{
				return nowIndex + 1;		
			}
			else
			{
				auto temp = formula[nowIndex++];
				string name = string(1, temp);
				//string names = string(2, "KK");
				while (nowIndex<formulaSize && formula[nowIndex]>='a' && formula[nowIndex]<='z')
				{
					name += formula[nowIndex++];
				}

				int cnt = 0;
				while (nowIndex<formulaSize &&formula[nowIndex]>='0' && formula[nowIndex]<='9')
				{
					cnt = cnt * 10 + formula[nowIndex++] - '0';
				}
				if (cnt>0)
				{
					hashMap[name] += (cnt);
				}
				else
				{
					hashMap[name] += 1;
				}
			}
		}
		return nowIndex;
	}
};
int main() {
	string demo = "K4(ON(SO3)2)2";
	Solution *sol = new Solution;
	string result;
	result=sol->countOfAtoms(demo);
	cout << result;
	delete sol;
	return 0;
}