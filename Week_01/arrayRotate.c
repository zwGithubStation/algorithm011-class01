void rotate(int* nums, int numsSize, int k){
	int i = 0;
	int tmp = 0;
	int j = 0;
    k %= numsSize;

	for (i = 0, j = numsSize - 1 - k; i<j; i++, j--)
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

	for (i = numsSize - k, j = numsSize - 1; i<j; i++, j--)
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

	for (i = 0, j = numsSize-1; i<j; i++, j--)
    {
		tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

}

