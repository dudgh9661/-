class Solution {
public:
    vector<int> ans;
    vector<vector<int>> answer;
    bool visited[6] = { false };
    
    void DFS(vector<int>& nums, int depth) {
        if ( depth == nums.size()) {
            answer.push_back(ans);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            
            visited[i] = true;
            ans.push_back(nums[i]);
            
            DFS(nums, depth + 1);
            
            visited[i] = false;
            ans.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        DFS(nums, 0);
        return answer;
    }
};
