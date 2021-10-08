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
    vector<vector<int>> paths;
    vector<int> path;
    
    void DFS(TreeNode *root, int sum, int targetSum) {
        int curSum = sum + root->val;
        path.push_back(root->val);
        
        if (curSum == targetSum && !root->right && !root->left) {
            paths.push_back(path);
            return;
        }
        
        if (root->right) {
            DFS(root->right, curSum, targetSum);
            path.pop_back();
        }
        if (root->left) {
            DFS(root->left, curSum, targetSum);
            path.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return paths;
        DFS(root, 0, targetSum);
        for(auto ps : paths) {
            for(auto p : ps) {
                cout << p << " ";
            }
            cout << endl;
        }
        return paths;
    }
};
