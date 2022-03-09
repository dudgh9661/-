class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> vec = matrix;
        // vec[0][0] = 5;
        // cout << vec[0][0] << " <-> " << matrix[0][0];
        int col = matrix[0].size() - 1;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].size(); j++) {
                matrix[j][col] = vec[i][j];
            }
            col--;
        }
    }
};
