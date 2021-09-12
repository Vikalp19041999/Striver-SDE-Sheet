/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDiameter(TreeNode* A) {
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
}

int maxDepth(TreeNode* A, int maxi) {
    if(A == NULL) {
        return 0;
    }
    int lh = maxDepth(A->left);
    int rh = maxDepth(A->right);
    maxi = max(maxi, (lh + rh));
    return 1 + max(lh, rh);
}