
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/word-ladder-ii/

   baseline solve :

   compile: g++ -std=c++11 -fsanitize=address -fno-omit-frame-pointer -O1 -g findLadders.cpp -o findLadders
 */


#include <vector>

using namespace std;

 
 class Solution {
 public:
	 vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

		 int size=wordList.size();
		 
		 unordered_map<string,int> rec;
		 
		 vector<vector<string>> res;
		 
		 for(int i=0;i<size;i++){
			 rec[wordList[i]]=i;//将当前单词加入到哈希表中，记录单词和索引的对应关系
		 }
		 
		 if(rec.count(beginWord)==0){//如果单词表中没有起点单词，将其加入到wordList和哈希表中
			 wordList.push_back(beginWord);
			 rec[beginWord]=size;
			 size++;
		 }
 
		 vector<int> visited(size,false);//访问标志
		 if(rec.count(endWord)==0){//如果word List中没有结束单词，肯定无解
			 return res;
		 }
 
		 vector<unordered_set<int>> graph(size);//要通过双向BFS构建的搜索树，使用unordered_set是为了去重
		 
		 queue<int> head2tail,tail2head;//两个队列，对应从头到尾和从尾到头的搜索方向
		 head2tail.push(rec[beginWord]);//起点入队,这里记录的是相应的单词在wordList中的索引，节约内存
		 tail2head.push(rec[endWord]);//终点入队
		 
		 visited[rec[beginWord]]=1;//起点和由起点扩展的点的visited值为1
		 visited[rec[endWord]]=2;//终点和由终点扩展的点的visited值为2
 
		 int flag=false;//建树完成标志
		 while((head2tail.empty()!=true||tail2head.empty()!=true)&&flag==false){//如果两个队列任一不为空且建树未完成			
			 if(head2tail.size()==0||head2tail.size()>tail2head.size()){//优先选择数量少的那边扩
			 //展，如果一个队列已经空了，那只能扩展另一个队列了，bfs()返回建树是否完成
				 flag=bfs(tail2head,visited,graph,wordList,rec);
			 }
			 else if(tail2head.size()==0||tail2head.size()>=head2tail.size()){//同上，换另一个队列扩展
				 flag=bfs(head2tail,visited,graph,wordList,rec);
			 } 
		 }	
 
		 vector<string> trace;//记录遍历过程中的单词
		 trace.push_back(beginWord);
		 dfs(rec[beginWord],rec[endWord],graph,trace,wordList,res);//用dfs()遍历树，得到答案
 
		 return res;
	 }
 //bfs()生成搜索树
	 bool bfs(queue<int> &work,vector<int> &visited,vector<unordered_set<int>> &graph,
			 vector<string> &wordList,unordered_map<string,int> &rec){
		 int size=work.size();
		 bool flag=false;//是否完成建树（两个队列扩展的点是否相遇）
 
		 vector<int> subVisited(visited);//记录这次扩展时经过的点，用visited初始化
		 for(int i=0;i<size;i++){//遍历当前队列的每一个点
			 int pres=work.front();
			 work.pop();
 
			 auto neigbor=getNeigbor(wordList[pres],rec);//获取当前单词可以到达的每一个单词(的索引)
			 for(auto next:neigbor){//遍历下一个点
				 if(visited[next]==0){//如果上一次没有访问这个单词
					 work.push(next);//入队
					 subVisited[next]=visited[pres];//被扩展的点和扩展它的点属于同一侧，
					 //所以visited标志相同
					 if(visited[pres]==1){//如果时属于从头到尾的遍历方向，添加树上节点时应该时当前点
						 //是被扩展点的父节点
						 graph[pres].insert(next);
					 }
					 else if(visited[pres]==2){//如果属于从尾到头的扩展方向，被扩展的点应该是当前点 					 
						 //的父节点
						 graph[next].insert(pres);
					 }
				 }
				 else if(visited[pres]==1&&visited[next]==2){//如果被扩展点已经被访问过，则说明两个方向的BFS，
				 //已经相遇了，遍历完成了，置flag为true，树上的父子关系同上
					 graph[pres].insert(next);
					 flag=true; 				
				 }
				 else if(visited[pres]==2&&visited[next]==1){//同上
					 graph[next].insert(pres);
					 flag=true;
				 }
			 }
		 }
 
		 visited=subVisited;//将本次节点访问情况赋值给visited
		 return flag;
	 }
 //组合路径，搜索整个答案树
	 void dfs(int begin,int end,vector<unordered_set<int>> &graph,vector<string>&trace,
			 vector<string>&wordList,vector<vector<string>>&res){
		 if(begin==end){
			 res.push_back(trace);
			 return;
		 }
 
		 for(auto next:graph[begin]){
			 trace.push_back(wordList[next]);//注意，这里树上节点是单词在word List中的索引，
			 //要把它还原成单词
			 dfs(next,end,graph,trace,wordList,res);
			 trace.pop_back();
		 }
	 }	  
 //找到和当前单词只相差一个字母的单词
	 list<int> getNeigbor(string &str,unordered_map<string,int> &rec){
		 list<int> res;
		 int size=str.size();
		 for(int i=0;i<size;i++){
			 char prev=str[i];
			 for(char chr='a';chr<='z';chr++){//更改当前位置的字母为每一个可能的字母
				 if(chr!=prev){//如果当前字母就是原先的字母，不用操作
					 str[i]=chr;
					 if(rec.count(str)!=0){//查找更改后的单词在单词表中有无出现
						 res.push_back(rec[str]);//记录单词的索引
					 }
				 }				
			 }
			 str[i]=prev;//恢复原先的字母
		 }
 
		 return res;
	 }
 };


