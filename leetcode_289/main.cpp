class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    vector<vector<int>> ans;
    int m, n;
    bool inRange(int r, int c) {
        if ( r < 0 || r >= m || c < 0 || c >= n) return false;
        return true;
    }
    
    // Any live cell with fewer than two live neighbors dies as if caused by under-population.
    bool one(int r, int c, vector<vector<int>>& board) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if (!inRange(nr,nc)) continue;
            if (board[nr][nc] == 1) cnt++;        
        }
        if (cnt < 2) return true;
        return false;
    }
     
    bool two(int r, int c, vector<vector<int>>& board) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if (!inRange(nr,nc)) continue;
            if (board[nr][nc] == 1) cnt++;            
        }
        
        if ( cnt == 2 || cnt == 3) return true;
        return false;
    }
    
    bool three(int r, int c, vector<vector<int>>& board) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if (!inRange(nr,nc)) continue;
            if (board[nr][nc] == 1) cnt++;            
        }
        
        if ( cnt > 3) return true;
        return false;
    }
    
    bool four(int r, int c, vector<vector<int>>& board) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;
            if (!inRange(nr,nc)) continue;
            if (board[nr][nc] == 1) cnt++;            
        }
        
        if ( cnt == 3) return true;
        return false;
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        
        for(int i= 0 ;i < m; i++) {
            ans.push_back(vector<int>(n,0));
        }
        
        for(int i = 0;i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 1) {
                    if (one(i,j,board)) ans[i][j] = 0;
                    else if (two(i,j,board)) ans[i][j] = 1;
                    else if (three(i,j,board)) ans[i][j] = 0;
                } else {
                    if (four(i,j,board)) ans[i][j] = 1;
                }
            }
        }
        
        board = ans;
    }
};
