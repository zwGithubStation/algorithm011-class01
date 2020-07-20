
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/generate-parentheses/#/description

   baseline solve :

   compile: g++ -lstdc++ -fsanitize=address -fno-omit-frame-pointer -O1 -g levelOrder.cpp  -o levelOrder
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
#include <queue>

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
		int cnt = 0;
		vector<vector<int > > res;

		queue<TreeNode* > nodesQueue;
		nodesQueue.push(root);

		while (!nodesQueue.empty())
		{
			vector<int > curRes;
			cnt = nodesQueue.size();
			TreeNode* curNode;
			while (cnt--)
			{
				curNode = nodesQueue.front();
				nodesQueue.pop();
				curRes.push_back(curNode->val);
				if (curNode->left)
					nodesQueue.push(curNode->left);
				if (curNode->right)
					nodesQueue.push(curNode->right);	
			}
			res.push_back(curRes);
		}
		return res;
    }
};

int main()
{
	return 0;
}

