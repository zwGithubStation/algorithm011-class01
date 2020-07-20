
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
			 
			 for (auto s : beginSet) {	//�ֵ��в�Ӧ������ǰ�������Ĵ�
				 wordDict.erase(s);
			 }
			 
			 for (auto s : beginSet) {	 //����ÿ����ѡ����
				 for (int i = 0; i < s.size(); ++i){  //���ʵ�ÿ���ַ�i������仯
					 string str = s;
					 for (char c = 'a'; c <= 'z'; ++c){
						 str[i] = c;			 //XXiXX ��Ϊ XX[c]XX ʱ
						 if (wordDict.find(str) == wordDict.end()){  //������ֵ���û��XX[c]XX��˵����ͨ����������ǰλ���ַ�
							 continue;
						 }
						 if (endSet.find(str) != endSet.end()){   //���ͨ�ˣ������ҵ���ͨ·�ߣ����Է���
							 return step;
						 }
						 tempSet.insert(str);	//������������һ������δ��ͨ�ĺ�ѡ������һ����ѡ��
					 }
				 }
			 }
			 if (tempSet.size() < endSet.size()){  //�����һ����ѡ�صĴ�С ������ƥ���С��ѡȡ��һ����ѡ��---->����ƥ��� ��·�߼���
				 beginSet = tempSet;
			 } else {
				 beginSet = endSet;   //�����һ����ѡ�صĴ�С ������ƥ��ش�ѡȡ����ƥ���---->��һ����ѡ�� ��·�߼���
				 endSet = tempSet;
			 }
		 }
		 return 0;
	 }
 };


