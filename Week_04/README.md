# 学习笔记

  
## 1.课前预热  

### 1.1 贪心算法  
**学习资料：《算法导论(第三版中文版)》 chapter-16 greedy algorithm, from page 237**  


### 1.2 广度优先搜索  
**学习资料：《算法导论(第三版中文版)》 chapter-22.2 from page 343**  

### 1.3 深度优先搜索  
**学习资料：《算法导论(第三版中文版)》 chapter-22.3 from page 349**  

### 1.4 二分查找  
**学习资料1：《C Programming Language(英文版第二版)》使用示例 from page 58/134**  

**学习资料2：《编程珠玑(第二版中文版)》 chapter 2、4、9**  

## 2.课程分析记录  

**A.** python版的DFS的递归模板，使用set比使用list效率高(类比C++中的set与vector)      

```C++
visited = set() 
.....
if node in visited
.....
for next_node in node.children():  
.....
```
问题：set内的元素可以是复杂类型么，不然如何有node.children()这种写法？  

**B.** C++版的DFS递归模板   

课程源码：
```C++
map<int, int> visited;

void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}
```
其中有判断是否已经遍历过的判断；这对于树结构来说实际应该是没用的(注意图中则必须，详见第二章)：
```C++
if (visited.count(root->val)) {
    // already visited
    return ;
  } 
```

问题：上述的判断是使用节点的val值为key，在map中查找是否有对应的[key,value]，这在一般的场景中是否会出现节点值重复的问题？  

**C.** JAVA版DFS递归模板单独针对树结构，使用了"层数与已检索元素数目相等时，建立新的层数array"的思想，写的挺巧，仿照写成C++版本：  

```C++
//DFS递归遍历写法增强版
vector<vector<int> > levelOrder(TreeNode root) {
	vector<vector<int> > allResults;
    if(root==null){
        return allResults;
    }
    travel(root, 0, allResults);
    return allResults;
    }


void travel(TreeNode root, int level, vector<vector<int>> results){
    if(results.size() == level){
		vector<int> c;
        results.push_back(c);
    }
    results[level].push_back(root.val);
    if(root.left != null){
        travel(root.left, level+1, results);
    }
    if(root.right != null){
        travel(root.right, level+1, results);
    }
}
```  
**D.** C++DFS非递归模板借助stack实现遍历  

课程源码：
```C++
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}
```
**E.** C++BFS模板借助queue实现遍历，可以看到和DFS非递归模板，出了使用的数据结构不同，代码框架是一致的  

课程源码：
```C++
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}
```

**E.** C++BFS模板借助queue实现遍历，可以看到和DFS非递归模板，出了使用的数据结构不同，代码框架是一致的 

## 3.课内题目与作业题要点记录   

**A.** 102_二叉树的层序遍历  

采用BFS思路，每层k放入queue的Node数目 == 需要加入vector[k]中的数值数目，只使用一个queue，即可实现。  

```C++
vector<vector<int > > levelOrder(TreeNode* root) {
		int cnt = 0;
        vector<vector<int > > res;

        if(!root)   //临界条件
            return res;

		queue<TreeNode* > nodesQueue;
		nodesQueue.push(root);  //初始queue中只有root

		while (!nodesQueue.empty()) 
		{
			vector<int > curRes;
			cnt = nodesQueue.size();   //记录当前层的Node数目
			TreeNode* curNode;
			while (cnt--)
			{
				curNode = nodesQueue.front();  //每次把一个Node记录在该层的数组中，并pop出queue
				nodesQueue.pop();
				curRes.push_back(curNode->val);
				if (curNode->left)             //将本层Node的左右子Node依次入queue
					nodesQueue.push(curNode->left);
				if (curNode->right)
					nodesQueue.push(curNode->right);	
			}									//queue中该层的Node全部出queue
			res.push_back(curRes);				//该层的数组记录完成
		}
		return res;
    }
```

## 4.扩展题目    

