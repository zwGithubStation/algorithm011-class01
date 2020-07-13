
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/combinations/

   baseline solve :

   compile: gcc -fsanitize=address -fno-omit-frame-pointer -O1 -g combine.c -o combine
 */


#define MAX_LEN 10240
void dfs(int n, int k, int* returnSize, int** returnColumnSizes,int **ret,int *path,int depth,int val)
{
    if(depth == k) 
	{
        ret[*returnSize] = (int *)calloc(k, sizeof(int));
        for(int i = 0; i < k; i++) {
            ret[*returnSize][i] = path[i];
        }
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;        
    }
	
    for (int i = val + 1; i <= (n - k + depth + 1); i++) 
	{
        path[depth] = i;
        dfs(n,k,returnSize,returnColumnSizes,ret,path,depth + 1,i);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int ** ret = (int **)calloc(MAX_LEN, sizeof(int));
    * returnSize = 0;
    if (k == 0) return ret;
    int *path = (int *)calloc(k, sizeof(int));
    * returnColumnSizes = (int *)calloc(MAX_LEN, sizeof(int));
    dfs(n, k, returnSize, returnColumnSizes, ret, path, 0, 0);
    return ret;
}


