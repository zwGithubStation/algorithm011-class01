
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

   baseline solve :

   compile: gcc -fsanitize=address -fno-omit-frame-pointer -O1 -g lowestCommonAncestor.c -o lowestCommonAncestor
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int visitTree( struct TreeNode *t , struct TreeNode *p , int l , int r )
{
    if( t == NULL )
	{
        return 0;
    }

    int flag_l = 0 , flag_r = 0;

    flag_l = visitTree( t->left ,p ,l ,r);
    flag_r = visitTree( t->right ,p ,l ,r);

    if( ( ( t->val == l || t->val == r ) && ( flag_l == 1 || flag_r == 1 ) ) 
        || ( flag_l == 1 && flag_r == 1 ) )
    {
        p->val = t->val;
    }
    
    if( t->val == r || t->val == l )
	{
        flag_l = 1;
    }

    return flag_l || flag_r;

}



struct TreeNode * lowestCommonAncestor( struct TreeNode *root , struct TreeNode *p , struct TreeNode *q ) 
{
    if( root == NULL || p == NULL || q == NULL )
	{
        return NULL;
    }

    struct TreeNode *t = ( struct TreeNode *)malloc(sizeof( struct TreeNode ) * 1);
    visitTree(root ,t ,p->val ,q->val);
    return t;

}


