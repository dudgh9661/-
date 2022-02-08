class Solution {
public:
    
    static bool cmp (pair<long long, int> a, pair<long long, int> b) {
        return a.first < b.first;
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long long, int>> vec(nums.size());
        // init
        for (int i = 0; i < nums.size(); i++) {
            vec[i].first = nums[i];
            vec[i].second = i;
        }
        
        // sort
        sort(vec.begin(), vec.end(), cmp);
        
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i+1; j < vec.size(); j++) {
                if (abs(vec[i].first - vec[j].first) > t) break;
                else {
                    if (abs(vec[i].second - vec[j].second) <= k)
                        return true;
                }
            }
        }
        
        return false;
    }
};
