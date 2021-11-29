class Solution {
public:
    set<vector<string>> st;
    vector<string> vec;
    string oper[2] = {"+","-"};
    int ans = 0;
    
    void DFS(vector<int>& nums, int target, int sum, int idx) {
        if (idx == nums.size()) {
            if (target == sum) {
                ans++;
            }
            return;
        }
        
        // for (int j = 0; j < 2; j++) { // +, -
            // string addNum = oper[j] + to_string(nums[idx]);
            // cout << sum << " + " << addNum << " = " << sum + stoi(addNum) << endl;
            DFS(nums, target, sum + nums[idx], idx + 1);
            DFS(nums, target, sum - nums[idx], idx + 1);
            // DFS(nums, target, sum + stoi(addNum), idx + 1);
        // }
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {        
        DFS(nums,target,0,0);
//         int ansTmp = st.size();
        
//         cout << ans << " , " << ansTmp;
        return ans;
    }
};
