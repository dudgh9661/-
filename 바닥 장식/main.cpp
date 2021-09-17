#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[100][100];
int visited[100][100] = { 0 };

int row, col;
int ga = 0 , se = 0;

void init() {
    cin >> row >> col;

    char ch;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> ch;
            map[i][j] = ch;
        }
    }
}
bool inRange(int r, int c) {
    if ( r < 0 || r >= row || c < 0 || c >= col ) return false;
    return true;
}

void BFSga(int r, int c) {
    queue<pair<int,int>> que;
    que.push({r, c});
    visited[r][c] = ga;

    while ( !que.empty() ) {
        int cr = que.front().first;
        int cc = que.front().second;
        que.pop();

        int nr = cr;
        int nc = cc + 1;
        if ( !inRange(nr, nc) ) break;
        if ( map[nr][nc] == '-' ) {
            visited[nr][nc] = ga;
            que.push({nr,nc});
        }
    }
}

void BFSse(int r, int c) {
    queue<pair<int,int>> que;
    que.push({r, c});
    visited[r][c] = se;

    while ( !que.empty() ) {
        int cr = que.front().first;
        int cc = que.front().second;
        que.pop();

        int nr = cr + 1;
        int nc = cc;
        if ( !inRange(nr, nc) ) break;
        if ( map[nr][nc] == '|' ) {
            visited[nr][nc] = se;
            que.push({nr,nc});
        }
    }
}

void sol() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if ( visited[i][j] > 0 ) continue;
            if ( map[i][j] == '-' ) {
                ga++;
                BFSga(i,j);
            }
            else if ( map[i][j] == '|') {
                se++;
                BFSse(i,j);
            }
        }
    }
}
int main() {
    init();
    sol();
    cout << ga + se;

    return 0;
}
