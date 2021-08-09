#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int row, col;
int sheep = 0, wolf = 0;

vector<pair<int,int>> vec;

bool visited[250][250] = { false };
char arr[250][250];

int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};

void init() {
    cin >> row >> col;

    string str;
    for(int i = 0; i < row; i++) {
        cin >> str;
        for(int j = 0; j < col; j++) {
            arr[i][j] = str[j];
            if ( str[j] == 'v' ) {
                wolf++;
                vec.push_back({i,j});
            }
            else if ( str[j] == 'o') {
                sheep++;
                vec.push_back({i,j});
            }
        }
    }
}

bool inRange(int r, int c) {
    if ( r < 0 || r >= row || c < 0 || c >= col ) return false;
    return true;
}

void BFS (int sr, int sc) {
    queue<pair<int,int>> que;
    int sheepCnt = 0, wolfCnt = 0;

    if (arr[sr][sc] == 'v') {
        wolfCnt++;
    } else if ( arr[sr][sc] == 'o') {
        sheepCnt++;
    }
    visited[sr][sc] = true;

    que.push({sr,sc});


    while (!que.empty()) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];
            if ( visited[nr][nc] ) continue;
            if ( !inRange(nr, nc) ) continue;
            if ( arr[nr][nc] == '#' ) continue; //울타리

            visited[nr][nc] = true;
            que.push({nr,nc});

            if (arr[nr][nc] == 'o') sheepCnt++;
            else if (arr[nr][nc] == 'v') wolfCnt++;
        }
    }

    if (sheepCnt > wolfCnt) {
        wolf -= wolfCnt;
    } else {
        sheep -= sheepCnt;
    }
}

int main() {
    init();
    for( pair<int,int> p : vec ) {
        if ( visited[p.first][p.second] ) continue;
        BFS(p.first,p.second);
    }
    cout << sheep << " " << wolf;
    return 0;
}