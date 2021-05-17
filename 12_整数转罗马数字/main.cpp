#include<iostream>
#include<vector>
#include"windows.h"
#include<string>
#include <utility>
#include<map>
using namespace std;
const pair<int, string> valueSymbols[] = {
	{ 1000, "M" },
	{ 900,  "CM" },
	{ 500,  "D" },
	{ 400,  "CD" },
	{ 100,  "C" },
	{ 90,   "XC" },
	{ 50,   "L" },
	{ 40,   "XL" },
	{ 10,   "X" },
	{ 9,    "IX" },
	{ 5,    "V" },
	{ 4,    "IV" },
	{ 1,    "I" },
};
class Solution {
public:
	string intToRoman(int num) {
		string roman;
		for (const auto & kv: valueSymbols)
		{
			while (num>=kv.first)
			{
				num -= kv.first;
				roman += kv.second;
			}
			if (num==0)
			{
				break;
			}
		}
		return roman ;
	}
};

int main() {
	
	int temp1 = 4;
	Solution sol;
	string result;
	result = sol.intToRoman(temp1);
	cout << result << endl;
	return 0;
}