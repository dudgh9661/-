class Solution {
public:
    bool checkRow(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            map<char, int> mp;
            for(int j = 0; j < 9; j++) {
                mp[board[i][j]]++;
            }
            // counting
            for (auto itr : mp) {
                if (itr.first != '.' && itr.second > 1) return false;
            }
        }
        
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            map<char, int> mp;
            for(int j = 0; j < 9; j++) {
                mp[board[j][i]]++;
            }
            // counting
            for (auto itr : mp) {
                if (itr.first != '.' && itr.second > 1) return false;
            }
        }
        
        return true;
    }
    
    bool square(vector<vector<char>>& board, int r, int c) {
        map<char, int> mp;
        for (int i = r; i < r+3; i++) {
            for (int j = c; j < c+3; j++) {
                mp[board[i][j]]++;
            }
        }
        for(auto itr : mp) {
            if (itr.first != '.' && itr.second > 1) return false;
        }
        return true;
    }
    
    bool checkSquare(vector<vector<char>>& board) {
        for (int i = 0; i <= 6; i+=3) {
            for (int j = 0; j <= 6; j+=3) {
                if (!square(board, i, j)) return false;
            }
        }
        return true;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        if(!checkRow(board) || !checkCol(board) || !checkSquare(board)) return false;
        return true;
    }
};
