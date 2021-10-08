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
    int count = 0;
    
    void DFS(TreeNode* root, int sum, int target) {
        int curSum = sum + root->val;
        
        if (curSum == target) count++;
        if (root->right) {
            DFS(root->right, curSum, target);
        }
        if (root->left) {
            DFS(root->left, curSum, target);
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0; 
        DFS(root, 0, targetSum);
        if (root->right) {
            pathSum(root->right, targetSum);
        }
        if (root->left) {
            pathSum(root->left, targetSum);
        }
        
        return count;
    }
};
