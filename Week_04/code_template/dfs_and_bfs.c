
/*
 * Copyright (C) ZWP
 */

#include <map>
#include <deque>

//DFS递归写法简易版
void dfs(Node* root) {
	// terminator
	if (!root) return ;

	//针对图的场景，如果是树则无甚意义
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


//DFS递归写法增强版 包含深度信息
vector<vector<int > > levelOrder(TreeNode root) {
	vector<vector<int > > allResults;
    if(root==null){
        return allResults;
    }
    travel(root, 0, allResults);
    return allResults;
    }


void travel(TreeNode root, int level, vector<vector<int > > results){
    if(results.size() == level){
		vector<int > c;
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

//DFS非递归写法，借助stack结构
void dfs(Node* root)
{
	stack<Node *> stackNodes;
	stackNodes.push(root);

	while (!stackNodes.empty())
	{
		Node *cur = stackNodes.top();
		stackNodes.pop();

		for (int i = 0; i < cur->children().size(); ++i)
			stackNodes.push(cur->children[i]);
	}

	return;
}

//BFS，借助queue结构
void BFS(Node *root)
{
	deque<Node *> queueNodes;
	queueNodes.push_back(root);

	while (!queueNodes.empty()) {
	    Node* node = queueNodes.front();
	    queueNodes.pop_front();

	    for (int i = 0; i < node->children.size(); ++i) {
	        queueNodes.push_back(node->children[i]);
	    }
  }

  return ;
}




