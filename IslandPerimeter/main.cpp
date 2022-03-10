class Solution {
public:
    int LR[4] = {-1,0,1,0};
    int UD[4] = {0,-1,0,1};
    bool visited[100][100] = { false };
    int ans = 0;
    int rowLimit = 0;
    int colLimit = 0;

    bool outOfRange(int r, int c) {
        if ( r < 0 || r >= rowLimit || c < 0 || c >= colLimit) return true;
        return false;
    }

    int getAdjacentIsland (int r, int c, vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];
            if (outOfRange(nr,nc)) continue;
            if (grid[nr][nc] == 1) cnt++;
        }
        // cout << r << "," << c << " : " << cnt << endl;
        return cnt;
    }

    void BFS(int r, int c, vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        que.push({r,c});
        visited[r][c] = true;

        while (!que.empty()) {
            int cr = que.front().first;
            int cc = que.front().second;
            ans += 4 - getAdjacentIsland(cr,cc, grid);
            que.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + UD[i];
                int nc = cc + LR[i];

                if (outOfRange(nr,nc) || visited[nr][nc] || grid[nr][nc] == 0) {

                    continue;
                }
                que.push({nr,nc});
                visited[nr][nc] = true;
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        rowLimit = grid.size();
        colLimit = grid[0].size();
        bool flag = false;
        // 1. 땅을 찾는다.
        // 2. 땅에서 4방향으로 땅이 몇개 맞닿아 있는지 확인한다.
        // 3. 4 - 닿아있는 땅을 해준다.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0 ; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    BFS(i,j, grid);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        return ans;
    }
};