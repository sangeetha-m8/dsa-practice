#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int)); // Allocate memory for the result array
    if (result == NULL) {
        *returnSize = 0;
        return NULL; // Return NULL if memory allocation fails
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2; // Set the return size to 2
                return result; // Return the result array
            }
        }
    }

    *returnSize = 0; // If no solution found, set return size to 0
    free(result); // Free the allocated memory before returning NULL
    return NULL; // Return NULL if no solution is found
}

void main(void)
{
    int nums[] = {7, 5, 8, 10, 17, 4};
    int numsSize = 6;
    int target = 11;
    int returnSize = 0;

    int *result = NULL;

    result = twoSum(nums, numsSize, target, &returnSize);
    if(result != NULL && returnSize == 2)
	printf("result = [%d, %d]\n", result[0], result[1]);
    else
        printf("Solution Not found\n");
}
