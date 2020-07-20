
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/generate-parentheses/#/description

   baseline solve :

   compile: g++ -std=c++11 -fsanitize=address -fno-omit-frame-pointer -O1 -g generateParenthesis.cpp -o generateParenthesis
 */


#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string curStr;
		curStr[0] = '(';
		dfs(ret, curStr, n, 1, 1);
		return ret;
    }

	void dfs(vector<string> &result, string &curStr, int n, int level, int left_cnt)
	{
		if (level == 2*n-1)
		{
			curStr[level] = ')';
			result.push_back(curStr);
			return;
		}

		int right_cnt = level + 1 - left_cnt;

		if (right_cnt == left_cnt)
		{
			curStr[level] = '(';
			dfs(result, curStr, n, level+1, left_cnt+1);
			return;
		}

		if (left_cnt == n)
		{
			curStr[level] = ')';
			dfs(result, curStr, n, level+1, left_cnt);
			return;
		}

		curStr[level] = '(';
		dfs(result, curStr, n, level+1, left_cnt+1);

		curStr[level] = ')';
		dfs(result, curStr, n, level+1, left_cnt);

		return;
	}
};

int main()
{
	Solution slu;
	vector<string> s = slu.generateParenthesis(3);

	for_each(s.begin(), s.end(), [](const auto &i){cout << i << endl; });
	
	return 0;
}

