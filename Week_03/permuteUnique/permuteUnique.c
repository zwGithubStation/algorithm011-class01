
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/permutations-ii/

   baseline solve :

   compile: gcc -fsanitize=address -fno-omit-frame-pointer -O1 -g permuteUnique.c -o permuteUnique
 */

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void search_helper(int *src_arr, int *tar_arr, int offset, int *used, int numsSize, int **res, int *returnSize, int *returnColumnSizes)
{
    if(offset == numsSize)
    {
        res[*returnSize] = (int *)calloc(numsSize, sizeof(int));
        memcpy(res[*returnSize], tar_arr, numsSize * sizeof(int));
        returnColumnSizes[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for(int i = 0; i < numsSize; i++)
    {
        if(used[i]) continue;
        if (i > 0 && src_arr[i] == src_arr[i - 1] && !used[i - 1]) 
            continue;
        tar_arr[offset] = src_arr[i];
        used[i] = 1;
        search_helper(src_arr, tar_arr, offset + 1, used, numsSize, res, returnSize, returnColumnSizes);
        used[i] = 0;
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(numsSize == 0)
        return NULL;
    
    qsort(nums, numsSize, sizeof(int), cmp); 
    int **res = (int **)calloc(1000, sizeof(int *));
    *returnColumnSizes = (int *)calloc(1000, sizeof(int));
    int used[numsSize];
    int tmp[numsSize];
    memset(used, 0x0, numsSize * sizeof(int));
    search_helper(nums, tmp, 0, used, numsSize, res, returnSize, *returnColumnSizes);
    return res;
}


