
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/word-ladder/description/

   baseline solve :

   compile: g++ -fsanitize=address -fno-omit-frame-pointer -O1 -g levelOrder.cpp -o levelOrder
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

 
 class Solution {
 public:
	 int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		 unordered_set<string> wordDict(wordList.begin(), wordList.end());
		 
		 if (wordDict.find(endWord) == wordDict.end()){
			 return 0;
		 }
		 
		 unordered_set<string> beginSet{beginWord};
		 unordered_set<string> endSet{endWord};
 
		 int step = 1;
		 for (; !beginSet.empty();){
			 
			 unordered_set<string> tempSet;
			 ++step;
			 
			 for (auto s : beginSet) {	//字典中不应包含当前待检索的词
				 wordDict.erase(s);
			 }
			 
			 for (auto s : beginSet) {	 //对于每个候选单词
				 for (int i = 0; i < s.size(); ++i){  //单词的每个字符i都参与变化
					 string str = s;
					 for (char c = 'a'; c <= 'z'; ++c){
						 str[i] = c;			 //XXiXX 变为 XX[c]XX 时
						 if (wordDict.find(str) == wordDict.end()){  //如果在字典中没有XX[c]XX，说明不通，继续换当前位置字符
							 continue;
						 }
						 if (endSet.find(str) != endSet.end()){   //如果通了，则已找到联通路线，可以返回
							 return step;
						 }
						 tempSet.insert(str);	//将可以走入下一跳但并未联通的候选放入下一跳候选池
					 }
				 }
			 }
			 if (tempSet.size() < endSet.size()){  //如果下一跳候选池的大小 比最终匹配池小，选取下一跳候选池---->最终匹配池 的路线继续
				 beginSet = tempSet;
			 } else {
				 beginSet = endSet;   //如果下一跳候选池的大小 比最终匹配池大，选取最终匹配池---->下一跳候选池 的路线继续
				 endSet = tempSet;
			 }
		 }
		 return 0;
	 }
 };


