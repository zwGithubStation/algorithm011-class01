
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
			 rec[wordList[i]]=i;//����ǰ���ʼ��뵽��ϣ���У���¼���ʺ������Ķ�Ӧ��ϵ
		 }
		 
		 if(rec.count(beginWord)==0){//������ʱ���û����㵥�ʣ�������뵽wordList�͹�ϣ����
			 wordList.push_back(beginWord);
			 rec[beginWord]=size;
			 size++;
		 }
 
		 vector<int> visited(size,false);//���ʱ�־
		 if(rec.count(endWord)==0){//���word List��û�н������ʣ��϶��޽�
			 return res;
		 }
 
		 vector<unordered_set<int>> graph(size);//Ҫͨ��˫��BFS��������������ʹ��unordered_set��Ϊ��ȥ��
		 
		 queue<int> head2tail,tail2head;//�������У���Ӧ��ͷ��β�ʹ�β��ͷ����������
		 head2tail.push(rec[beginWord]);//������,�����¼������Ӧ�ĵ�����wordList�е���������Լ�ڴ�
		 tail2head.push(rec[endWord]);//�յ����
		 
		 visited[rec[beginWord]]=1;//�����������չ�ĵ��visitedֵΪ1
		 visited[rec[endWord]]=2;//�յ�����յ���չ�ĵ��visitedֵΪ2
 
		 int flag=false;//������ɱ�־
		 while((head2tail.empty()!=true||tail2head.empty()!=true)&&flag==false){//�������������һ��Ϊ���ҽ���δ���			
			 if(head2tail.size()==0||head2tail.size()>tail2head.size()){//����ѡ�������ٵ��Ǳ���
			 //չ�����һ�������Ѿ����ˣ���ֻ����չ��һ�������ˣ�bfs()���ؽ����Ƿ����
				 flag=bfs(tail2head,visited,graph,wordList,rec);
			 }
			 else if(tail2head.size()==0||tail2head.size()>=head2tail.size()){//ͬ�ϣ�����һ��������չ
				 flag=bfs(head2tail,visited,graph,wordList,rec);
			 } 
		 }	
 
		 vector<string> trace;//��¼���������еĵ���
		 trace.push_back(beginWord);
		 dfs(rec[beginWord],rec[endWord],graph,trace,wordList,res);//��dfs()���������õ���
 
		 return res;
	 }
 //bfs()����������
	 bool bfs(queue<int> &work,vector<int> &visited,vector<unordered_set<int>> &graph,
			 vector<string> &wordList,unordered_map<string,int> &rec){
		 int size=work.size();
		 bool flag=false;//�Ƿ���ɽ���������������չ�ĵ��Ƿ�������
 
		 vector<int> subVisited(visited);//��¼�����չʱ�����ĵ㣬��visited��ʼ��
		 for(int i=0;i<size;i++){//������ǰ���е�ÿһ����
			 int pres=work.front();
			 work.pop();
 
			 auto neigbor=getNeigbor(wordList[pres],rec);//��ȡ��ǰ���ʿ��Ե����ÿһ������(������)
			 for(auto next:neigbor){//������һ����
				 if(visited[next]==0){//�����һ��û�з����������
					 work.push(next);//���
					 subVisited[next]=visited[pres];//����չ�ĵ����չ���ĵ�����ͬһ�࣬
					 //����visited��־��ͬ
					 if(visited[pres]==1){//���ʱ���ڴ�ͷ��β�ı�������������Ͻڵ�ʱӦ��ʱ��ǰ��
						 //�Ǳ���չ��ĸ��ڵ�
						 graph[pres].insert(next);
					 }
					 else if(visited[pres]==2){//������ڴ�β��ͷ����չ���򣬱���չ�ĵ�Ӧ���ǵ�ǰ�� 					 
						 //�ĸ��ڵ�
						 graph[next].insert(pres);
					 }
				 }
				 else if(visited[pres]==1&&visited[next]==2){//�������չ���Ѿ������ʹ�����˵�����������BFS��
				 //�Ѿ������ˣ���������ˣ���flagΪtrue�����ϵĸ��ӹ�ϵͬ��
					 graph[pres].insert(next);
					 flag=true; 				
				 }
				 else if(visited[pres]==2&&visited[next]==1){//ͬ��
					 graph[next].insert(pres);
					 flag=true;
				 }
			 }
		 }
 
		 visited=subVisited;//�����νڵ���������ֵ��visited
		 return flag;
	 }
 //���·����������������
	 void dfs(int begin,int end,vector<unordered_set<int>> &graph,vector<string>&trace,
			 vector<string>&wordList,vector<vector<string>>&res){
		 if(begin==end){
			 res.push_back(trace);
			 return;
		 }
 
		 for(auto next:graph[begin]){
			 trace.push_back(wordList[next]);//ע�⣬�������Ͻڵ��ǵ�����word List�е�������
			 //Ҫ������ԭ�ɵ���
			 dfs(next,end,graph,trace,wordList,res);
			 trace.pop_back();
		 }
	 }	  
 //�ҵ��͵�ǰ����ֻ���һ����ĸ�ĵ���
	 list<int> getNeigbor(string &str,unordered_map<string,int> &rec){
		 list<int> res;
		 int size=str.size();
		 for(int i=0;i<size;i++){
			 char prev=str[i];
			 for(char chr='a';chr<='z';chr++){//���ĵ�ǰλ�õ���ĸΪÿһ�����ܵ���ĸ
				 if(chr!=prev){//�����ǰ��ĸ����ԭ�ȵ���ĸ�����ò���
					 str[i]=chr;
					 if(rec.count(str)!=0){//���Ҹ��ĺ�ĵ����ڵ��ʱ������޳���
						 res.push_back(rec[str]);//��¼���ʵ�����
					 }
				 }				
			 }
			 str[i]=prev;//�ָ�ԭ�ȵ���ĸ
		 }
 
		 return res;
	 }
 };


