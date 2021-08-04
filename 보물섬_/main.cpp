#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int>> vec;

int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};
int arr[50][50] = { 0 };
int visited[50][50] = { 0 };

int row, col;

int ans = 0;

bool inRange(int r, int c) {
    if ( r < 0 || r > row -1 || c < 0 || c > col - 1 ) return false;
    return true;
}

void init() {
    cin >> row >> col;

    for(int i = 0; i < row; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++) {
            if ( str[j] == 'L') {
                arr[i][j] = 1;
                vec.push_back({i,j});
            }
        }
    }
}
void conditionInit() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            visited[i][j] = 0;
        }
    }
}
void BFS(int sr, int sc) {
    queue<pair<int,int>> que;
    que.push({sr,sc});
    visited[sr][sc] = 0;

    while ( !que.empty() ) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];

            if ( nr == sr && nc == sc ) continue;
            if ( !inRange(nr,nc) ) continue;
            if ( visited[nr][nc] != 0 ) continue;
            if ( arr[nr][nc] == 0 ) continue;

            que.push({nr,nc});
            visited[nr][nc] = visited[r][c] + 1;
            ans = max(ans, visited[nr][nc]);
        }
    }
}
int main() {
    init();
    for( pair<int,int> p : vec ) {
        BFS(p.first, p.second);
        conditionInit();
    }
    cout << ans;
    return 0;
}
