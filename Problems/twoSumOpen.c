#include <stdio.h>
#include <stdlib.h>

#define MAX 31

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct node {
    int key;           // index in array
    int val;           // element value
    struct node* link;
} *LIST;

typedef LIST Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);

/*********************************/
/*          YOUR TASKS           */
/*********************************/
void insert(Dictionary D, int data, int index);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int hash(int elem);

int main(void) {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int returnSize;
    int* result = twoSum(nums, n, target, &returnSize);

    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    free(nums);
    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/
void insert(Dictionary D, int data, int index) {
    // TODO: Implementation here
    int idx = hash(data);
    LIST newNode = (LIST)malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->val = data;
        newNode->key = index;
        newNode->link = D[idx];
        D[idx] = newNode;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Dictionary D;
    initDict(D);
    *returnSize = 2;

    for(int i = 0; i < numsSize; i++) {
        int find = target - nums[i];
        int idx = hash(find);

        LIST trav = D[idx];
        while(trav != NULL) {
            if(trav->val == find) {
                int *result = (int*)malloc(sizeof(int) * (*returnSize));
                result[0] = trav->key;
                result[1] = i;
                return result;
            }
            trav = trav->link;
        }
        insert(D, nums[i], i);
    }
    return NULL;
}

int hash(int elem) {
    // TODO: Implementation here
    if(elem < 0) elem = -elem;
    return elem % MAX;
}
