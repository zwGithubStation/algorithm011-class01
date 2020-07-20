
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/number-of-islands/

   baseline solve :

   compile: gcc -fsanitize=address -fno-omit-frame-pointer -O1 -g numIslands.c -o numIslands
 */



void dfs(char **grid, int i, int j, int iMax, int jMax)
{   
    if (i < 0 || i >= iMax || j < 0 || j >= jMax) {
        return;
    }

    if (grid[i][j] == '1') {
        grid[i][j] = '0';
    } else {
        return;
    }
    
    dfs(grid, i - 1, j, iMax, jMax);
    dfs(grid, i + 1, j, iMax, jMax);
    dfs(grid, i, j - 1, iMax, jMax);
    dfs(grid, i, j + 1, iMax, jMax);
}

int numIslands(char **grid, int gridSize, int *gridColSize)
{
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] != '1') {
                continue;
            }
            dfs(grid, i, j, gridSize, *gridColSize);
            ret++;
        }
    }
    return ret;
}



