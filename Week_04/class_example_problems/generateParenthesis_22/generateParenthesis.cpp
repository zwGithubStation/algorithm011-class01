
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
		dfs(ret, curStr, n, 0, 0);
		return ret;
    }

	void dfs(vector<string> &result, string &curStr, int n, int left_cnt, int right_cnt)
	{
		if (left_cnt < right_cnt || left_cnt > n || right_cnt > n)
			return;

		if (left_cnt == n && right_cnt == n)
		{
			result.push_back(curStr);
			return;
		}

		curStr[left_cnt+right_cnt] = '(';
		dfs(result, curStr, n, left_cnt+1, right_cnt);

		curStr[left_cnt+right_cnt] = ')';
		dfs(result, curStr, n, left_cnt, right_cnt+1);

		return;
	}
};

int main()
{
	Solution slu;
	vector<string> s = slu.generateParenthesis(3);

	for_each(s.begin(), s.end(), [](const string &i){cout << i << endl; });
	
	return 0;
}

