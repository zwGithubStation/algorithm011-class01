
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/combinations/

   baseline solve :

   compile: g++ -fsanitize=address -fno-omit-frame-pointer -O1 -g combine.cpp -o combine
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

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return NULL;
    }
};

