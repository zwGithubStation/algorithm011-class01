
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
			
	        for (auto s : beginSet) {  //�ֵ��в�Ӧ������ǰ�������Ĵ�
	            wordDict.erase(s);
	        }
			
	        for (auto s : beginSet) {   //����ÿ����ѡ����
	            for (int i = 0; i < s.size(); ++i){  //���ʵ�ÿ���ַ�i������仯
	                string str = s;
	                for (char c = 'a'; c <= 'z'; ++c){
	                    str[i] = c;             //XXiXX ��Ϊ XX[c]XX ʱ
	                    if (wordDict.find(str) == wordDict.end()){  //������ֵ���û��XX[c]XX��˵����ͨ����������ǰλ���ַ�
	                        continue;
	                    }
	                    if (endSet.find(str) != endSet.end()){   //���ͨ�ˣ������ҵ���ͨ·�ߣ����Է���
	                        return step;
	                    }
	                    tempSet.insert(str);   //������������һ������δ��ͨ�ĺ�ѡ������һ����ѡ��
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
		
		if (dict.find(end) == dict.end()) //Ŀ��������Ϸ�
			return -1;

		while (!beginSet.empty())
		{
			cout << "cur beginSet:" << endl;
			
			copy(beginSet.begin(),beginSet.end(),ostream_iterator<string>(cout," "));
			cout << endl;
			
			unordered_set<string> tmpSet;
			minCnt++;

			for (auto elem : beginSet) //����ǰѰ·��ӺϷ��������ȥ��
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

