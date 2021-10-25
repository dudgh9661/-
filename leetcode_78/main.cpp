class Solution {
public:
    vector<int> ans;
    vector<vector<int>> answer;
    
    void DFS(int depth, vector<int>& nums, int start) {
        if (depth == nums.size()) {
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            ans.push_back(nums[i]);
            answer.push_back(ans);
            DFS(depth + 1, nums, i + 1);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        answer.push_back(vector<int>());
        DFS(0, nums, 0);
        // for (auto v : answer)  {
        //     for (auto n : v) {
        //         cout << n << " ";
        //     }
        //     cout << endl;
        // }
        return answer;
    }
};
