class Solution {
public:
    bool visited[16] = { false };
    bool DFS (int target, vector<int> nums, int vecSum, int k, int start) {
        if (k == 0) return true;
        
        if (target == vecSum) {
            return DFS(target, nums, 0, k-1, 0);
        }
        
        for (int i = start; i < nums.size(); i++) {
            if (visited[i] || vecSum + nums[i] > target) continue;
            visited[i] = true;
            
            if (DFS(target, nums, vecSum + nums[i], k, i+1)) return true;
            
            visited[i] = false;
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        sort(nums.begin(), nums.end(), less<>());
        return DFS(sum / k, nums, 0, k, 0);
    }
};
