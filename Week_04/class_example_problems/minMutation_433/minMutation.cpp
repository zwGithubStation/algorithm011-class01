
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/word-ladder/solution/dan-ci-jie-long-by-leetcode/

   baseline solve :

   compile: g++ -fsanitize=address -fno-omit-frame-pointer -O1 -g minMutation.cpp -lstdc++ -o minMutation
 */


#include <vector>
#include <cstdlib>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream> 

using namespace std;

/*
class Solution1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		
	    unordered_set<string> wordDict(wordList.begin(), wordList.end());
		
	    if (wordDict.find(endWord) == wordDict.end()){
	        return 0;//Not FOUND 404
	    }
		
	    unordered_set<string> beginSet{beginWord};
	    unordered_set<string> endSet{endWord};

		int step = 1;
	    for (; !beginSet.empty();){
			
	        unordered_set<string> tempSet;
	        ++step;
			
	        for (auto s : beginSet) {  //字典中不应包含当前待检索的词
	            wordDict.erase(s);
	        }
			
	        for (auto s : beginSet) {   //对于每个候选单词
	            for (int i = 0; i < s.size(); ++i){  //单词的每个字符i都参与变化
	                string str = s;
	                for (char c = 'a'; c <= 'z'; ++c){
	                    str[i] = c;             //XXiXX 变为 XX[c]XX 时
	                    if (wordDict.find(str) == wordDict.end()){  //如果在字典中没有XX[c]XX，说明不通，继续换当前位置字符
	                        continue;
	                    }
	                    if (endSet.find(str) != endSet.end()){   //如果通了，则已找到联通路线，可以返回
	                        return step;
	                    }
	                    tempSet.insert(str);   //将可以走入下一跳但并未联通的候选放入下一跳候选池
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

*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
		unordered_set<string> beginSet({start});
		unordered_set<string> endSet({end});
		string str("ACGT");
		int minCnt = 0;

		if (dict.empty())
            return -1;
		
		if (dict.find(end) == dict.end()) //目标基因必须合法
			return -1;

		while (!beginSet.empty())
		{
			cout << "cur beginSet:" << endl;
			
			copy(beginSet.begin(),beginSet.end(),ostream_iterator<string>(cout," "));
			cout << endl;
			
			unordered_set<string> tmpSet;
			minCnt++;

			for (auto elem : beginSet) //将当前寻路项从合法基因库中去除
				dict.erase(elem);

			for (auto elem : beginSet)
			{
				for (int i = 0 ; i < 8; i++)
				{
					string changed(elem);
					for (int j = 0 ; j < 4; j++)
					{
						changed[i] = str[j];
						
						cout << "begin check:" << changed << endl;

						cout << "current endSet:" << endl;
						copy(endSet.begin(),endSet.end(),ostream_iterator<string>(cout," "));
						cout << endl;

						cout << "current dict:" << endl;
						copy(dict.begin(),dict.end(),ostream_iterator<string>(cout," "));
						cout << endl;
						
						if (changed == elem)
							continue;
							
						if (endSet.find(changed) != endSet.end())
						{
							cout << "find in endSet!!" << endl;
							return minCnt;
						}
							

						if (dict.find(changed) != dict.end())
						{
							cout << "find one changed node[" << changed << "] in dict" << endl;
							tmpSet.insert(changed);
						}
					}
				}
			}
			
			if (tmpSet.size() < endSet.size())
			{
				endSet = tmpSet;
			}else{
				beginSet = endSet;
				endSet = tmpSet;
			}
			
		}
		return -1;
    }
};



int main()
{
	Solution s;
	string start("AAAAAAAA"); 
	string end("CCCCCCCC");
	vector <string > dict = {"AAAAAAAA","AAAAAAAC","AAAAAACC","AAAAACCC","AAAACCCC","AACACCCC","ACCACCCC","ACCCCCCC","CCCCCCCA","CCCCCCCC"};
	int i = s.minMutation(start, end, dict);
	cout << "result:" << i << endl;
	return 0;
}

