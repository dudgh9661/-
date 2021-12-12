class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        
        int target = sum / 2;
        
        set<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            set<int> newDp;
            for (auto itr = dp.begin(); itr != dp.end(); itr++) {
                if (*itr + nums[i] == target) return true;
                newDp.insert(*itr + nums[i]);
                newDp.insert(*itr);
            }
            newDp.insert(nums[i]);
            dp = newDp;
            if (dp.find(target) != dp.end()) return true;
        }

        return false;
    }
};
