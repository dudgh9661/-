class Solution {
public:
    set<vector<int>> st;
    
    void DFS(vector<int>& nums, int idx, vector<int> vec) {
        if (vec.size() > 1) {
            st.insert(vec);
        }
        
        for (int i = idx; i < nums.size(); i++) {
            if (!vec.empty() && vec[vec.size()-1] > nums[i]) continue;
            vec.push_back(nums[i]);
            DFS(nums, i+1, vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        DFS(nums, 0, vector<int>());
        vector<vector<int>> ans(st.begin(), st.end());
        // for (auto v : ans) {
        //     for (auto e : v) {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};
