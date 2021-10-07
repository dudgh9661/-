class Solution {
public:
    
    int UD[4] = {0, 1, 0, -1};
    int LR[4] = {1, 0,-1, 0};
    bool visited[10][10] = { false };
    
    bool inRange(int r, int c, int maxRowSize, int maxColSize) {
        if ( r < 0 || r >= maxRowSize || c < 0 || c >= maxColSize ) return false;
        return true;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int cR= 0, cC = 0, arrow = 0, nR, nC;
        visited[cR][cC] = true;
        result.push_back(matrix[cR][cC]);
        int maxColSize = matrix[0].size();
        int maxRowSize = matrix.size();
        int count = maxColSize * maxRowSize;
        
        while (count > 1) {
            nR = cR + UD[arrow];
            nC = cC + LR[arrow];
            // cout << nR << "," << nC;
            
            if (inRange(nR,nC, maxRowSize, maxColSize) == false || visited[nR][nC] ) {
                arrow = (arrow+1) % 4;
                nR = cR + UD[arrow];
                nC = cC + LR[arrow];
                // cout << " -> " << nR << "," << nC << "c : "<< cR << "," << cC << endl;
                // cout << arrow << UD[arrow] << LR[arrow] << endl;
            }
            // cout << endl;
            
            visited[nR][nC] = true;
            count--;
            result.push_back(matrix[nR][nC]); 
            cR = nR;
            cC = nC;
            
        }
        
        return result;
    }
};
