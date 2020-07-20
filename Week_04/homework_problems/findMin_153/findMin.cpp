
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/jump-game/

   baseline solve :

   compile: g++ -fsanitize=address -fno-omit-frame-pointer -O1 -g findMin.cpp -o findMin
 */


#include <vector>

using namespace std;

 
 class Solution {
 public:
	 int findMin(vector<int>& nums) {
		 int left = 0;
		 int right = nums.size() - 1;				 
		 while (left < right) { 					 
			 int mid = left + (right - left) / 2;	 
			 if (nums[mid] > nums[right]) { 		
				 left = mid + 1;					 
			 } else if (nums[mid] < nums[right]) {	
				 right = mid;						
			 }
		 }
		 return nums[left];  	
	 }
 };

