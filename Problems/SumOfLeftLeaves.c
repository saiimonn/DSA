#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode* root) {
    if(root == NULL) return 0;
    int sum = 0;

    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        sum += root->left->val;
    } else {
        sum += sumOfLeftLeaves(root->left);
    }
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {

}