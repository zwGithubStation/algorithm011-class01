
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/jump-game/

   baseline solve :

   compile: g++ -fsanitize=address -fno-omit-frame-pointer -O1 -g canJump.cpp -o canJump
 */


#include <vector>

using namespace std;

 
 class Solution {
 public:
	 
	 bool canJump(vector<int>& nums) 
	 {
		 int k = 0;
		 for (int i = 0; i < nums.size(); i++)
		 {
			 if (i > k) return false;
			 k = max(k, i + nums[i]);
		 }
		 return true;
	 }
	 
 };


