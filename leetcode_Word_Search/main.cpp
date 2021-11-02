class Solution {
public:
    int UD[4] = {-1,0,1,0};
    int LR[4] = {0,-1,0,1};
    bool visited[6][6]= { false };
    
    bool flag = false;
    
    bool inRange(int r, int c, vector<vector<char>>& board) {
        if ( r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;
        return true;
    }
    
    void DFS(vector<vector<char>>& board, string word, int curIdx, int r, int c) {
        if (curIdx == word.length() - 1) {
            flag = true;
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];
            if (!inRange(nr,nc, board) || visited[nr][nc]) continue;
            if (board[nr][nc] != word[curIdx + 1]) continue;
            
            visited[nr][nc] = true;
            DFS(board, word, curIdx + 1, nr, nc);
            if (flag) return;
            visited[nr][nc] = false;
        }
    }
    
    void initVisited() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0 ; j < 6; j++) {
                visited[i][j] = false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    initVisited();
                    visited[i][j] = true;
                    DFS(board, word, 0, i, j);
                }
                if (flag) return true;
            }
        }
        return false;
    }
};
