class Solution {
public:
    
    vector<int> vec;
    vector<vector<int>> ans;
    
    void DFS(int target, int sum, int num, int k) {
        if (vec.size() == k) {
            if (target == sum) {
                ans.push_back(vec);
            }
            return;
        }
        
        for (int i = num; i <= 9; i++) {
            vec.push_back(i);
            
            DFS(target, sum+i, i+1, k);
            
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        // int sum = 0;
        // for (int i = 1; i <= k; i++) {
        //     sum += i;
        // }
        // if (sum > n) return ans;
        // sum = 0;
        // for (int i = 9; i >= 9-k+1; i--) {
        //     sum += i;
        // }
        // if (sum < n) return ans;
        
        
        DFS(n, 0, 1, k);
        return ans;
    }
};
