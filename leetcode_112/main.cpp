/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    bool flag = false;
    
    void DFS(TreeNode* root, int sum, int targetSum) {
        int curSum = root->val + sum;
        if (curSum == targetSum && !root->right && !root->left) {
            flag = true;
            return;
        }
        if (root->right) {
            DFS(root->right, curSum, targetSum);
        }
        if (root->left) {
            DFS(root->left, curSum, targetSum);
        }
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (root->val == targetSum && !root->right && !root->left) return true;
        DFS(root, 0, targetSum);
        return flag;
    }
};
