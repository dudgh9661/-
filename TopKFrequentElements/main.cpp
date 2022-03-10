class Solution {
public:
    unordered_map<int, int> mp;

    struct cmp {
        bool operator() (pair<int,int> p, pair<int,int> p2) {
            return p.second > p2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> que;
        
        for (auto p : mp) {
            que.push(p);
            if (que.size() > k) que.pop();
        }
        
        vector<int> ans(k);
        
        for (int i = 0; i < k; i++) {
            ans[i] = que.top().first;
            que.pop();
        }
        return ans;
    }
};
