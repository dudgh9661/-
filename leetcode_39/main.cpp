class Solution {
public:
    vector<vector<int>> ans;
    
    void DFS(vector<int> vec, vector<int>& candidates, int target, int sum, int start) {
        if (target == sum) {
            ans.push_back(vec);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) continue;
            vec.push_back(candidates[i]);            
            DFS(vec, candidates, target, sum + candidates[i], i);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        DFS(vector<int>(0), candidates, target, 0, 0);
        return ans;
    }
};
