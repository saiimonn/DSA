#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare); //quick sort fn

    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}

int main() {

}