
/*
 * Copyright (C) ZWP

 * Problem: https://leetcode-cn.com/problems/permutations/

   baseline solve :

   compile: gcc -fsanitize=address -fno-omit-frame-pointer -O1 -g permute.c -o permute
 */

int arraySize(int number)
{
    if(number==1) return 1;
    return number*arraySize(number-1);
}
void DFS(int**output, int* input, int inputSize)
{
    int outputSize = arraySize(inputSize);
    if(inputSize==1)
	{
        output[0][0] = input[0];
        return;
    }
	
    int tempInputSize = inputSize - 1;
    int *tempInput = (int*)malloc(sizeof(int) * tempInputSize);
    int tempOutputSize = arraySize(tempInputSize);
    int **tempOutput = (int**)malloc(sizeof(int*) * tempOutputSize);
	
    for(int i = 0; i < tempOutputSize; i++)
	{
        tempOutput[i] = (int*)malloc(sizeof(int) * tempInputSize);
    }
	
    for(int i = 0; i < inputSize; i++)
	{
        for(int j = 0; j < i; j++)
		{
            tempInput[j] = input[j];
        }
		
        for(int j = i; j < tempInputSize; j++)
		{
            tempInput[j] = input[j+1];
        }
		
        DFS(tempOutput, tempInput, tempInputSize); 
		
        for(int j = 0; j < tempOutputSize; j++)
		{
            output[i*tempOutputSize+j][0] = input[i];
            for(int k = 0; k < tempInputSize; k++)
			{
                output[i*tempOutputSize+j][k+1] = tempOutput[j][k];
            }
        }
    }
	
    free(tempInput);
	
    for(int j = 0; j < tempOutputSize; j++)
	{
        free(tempOutput[j]);
    }
	
    free(tempOutput);
    return;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    (*returnSize) = arraySize(numsSize);
    int** returnArray = (int**)malloc(sizeof(int*) * (*returnSize));
    *(returnColumnSizes) = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++)
	{
        returnArray[i] = (int*)malloc(sizeof(int*) * numsSize);
        *(*(returnColumnSizes)+i) = numsSize;
    }
	
    DFS(returnArray,nums,numsSize);
    return returnArray;
}


