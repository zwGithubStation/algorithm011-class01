
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/combinations/

   baseline solve :

   compile: g++ -fsanitize=address -fno-omit-frame-pointer -O1 -g levelOrder.cpp -lstdc++ -o levelOrder
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <cstdlib>
#include <deque>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int > > levelOrder(TreeNode* root) {
		int level = 0;
		vector<vector<int > > res;

		deque<TreeNode* > curLevelQueue;
		nodeQueue.push(root);
		deque<TreeNode* > nextLevelQueue;

		while (!curLevelQueue.empty())
		{
			for (auto pos = curLevelQueue.begin(); pos != curLevelQueue.end(); pos++)
			{
				res[level].push_back(pos->val);
				if (pos->left != NULL)
					nextLevelQueue.push_back(pos->left);
				if (pos->right != NULL)
					nextLevelQueue.push_back(pos->right);
			}

			curLevelQueue = nextLevelQueue;
			level++;
		}
    }
};

int main()
{
	return 0;
}

