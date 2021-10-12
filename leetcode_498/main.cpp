class Solution {
public:
    vector<pair<int,int>> LR = {{0,1}, {1,0}};
    vector<pair<int,int>> diag = {{-1,1}, {1,-1}};
    vector<int> ans;
    
    int m, n;
    
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        int cnt = m * n;
        
        int r = 0, c = 0;
        
        while (cnt > 0) {    
            
            while (r >= 0 && c < n) {
                ans.push_back(mat[r--][c++]);
                cnt--;
            }
            r++; c--;
            if (c + 1 < n)  c++;
            else r++;
            while (r < m && c >= 0) {
                ans.push_back(mat[r++][c--]);
                cnt--;
            }
            r--;c++;
            if (r + 1 < m) r++;
            else c++;
        }
        
        return ans;
    }
};
