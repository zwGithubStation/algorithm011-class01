
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

   baseline solve :

   compile: gcc -fsanitize=address -fno-omit-frame-pointer -O1 -g buildTree.c -o buildTree
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (preorderSize == 0 || inorderSize == 0) 
	{
        return NULL;
    }
	
    struct TreeNode* head = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    head->val = preorder[0];
    
    head->left = NULL;
    head->right = NULL;
    if (preorderSize == 1 || inorderSize == 1) {
        return head;
    }
    
    int i;
    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == preorder[0]) {
            break;
        }
    }
    
    int right = preorderSize - i - 1;
    if (i) 
        head->left = buildTree(&preorder[1], i, &inorder[0], i);
    if (right)
        head->right = buildTree(&preorder[1 + i], right, &inorder[i+1], right);

    return head;
}



