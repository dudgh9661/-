class Solution {
public:
    int UD[4] = {-1, 0, 1, 0};
    int LR[4] = { 0, -1, 0, 1};
    bool visited[15][15] = { false };
    int rSize, cSize;
    int MAX = 0;
    
    bool outOfRange(int r, int c) {
        if ( r < 0 || r >= rSize || c < 0 || c >= cSize) return true;
        return false;
    }
    
    void DFS(int r, int c, int cnt, vector<vector<int>>& grid) {
        
        for (int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];
            if (outOfRange(nr,nc) || visited[nr][nc] || grid[nr][nc] == 0) {
                MAX = max(MAX, cnt);
                continue;
            }
            
            visited[nr][nc] = true;
            DFS(nr, nc, cnt + grid[nr][nc], grid);
            visited[nr][nc] = false;
        }
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        rSize = grid.size();
        cSize = grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) continue;
                visited[i][j] = true;
                DFS(i, j, grid[i][j], grid);
                visited[i][j] = false;
            }
        }
        return MAX;
        
    }
};
