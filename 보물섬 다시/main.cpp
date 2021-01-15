#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int R, C;

int MAX = -100;
int map[50][50];
int visited[50][50] = { 0 };
int UD[4] = {1,-1,0,0};

int LR[4] = {0,0,1,-1};

void init() {
    cin >> R >> C;

    char ch;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> ch;
            map[i][j] = ch;

        }
    }
}
bool inRange(int r, int c) {
    if( r < 0 || r >= R || c < 0 || c >= C ) return false;
    return true;
}

void initVisited() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            visited[i][j] = 0;
        }
    }
}
void BFS(int r, int c) {
    queue<pair<int,int>> que;
    que.push({r,c});
    visited[r][c] = 1;

    while( !que.empty() ) {
        int cR = que.front().first;
        int cC = que.front().second;
        if ( MAX < visited[cR][cC] ) MAX = visited[cR][cC];
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nR = cR + UD[i];
            int nC = cC + LR[i];

            if( !inRange(nR,nC) ) continue;
            if( map[nR][nC] != 'L' || visited[nR][nC] != 0 ) continue;

            visited[nR][nC] = visited[cR][cC] + 1;
            que.push({nR,nC});
        }
    }
}

int main() {
    init();

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if( map[i][j] == 'L' ) {
                BFS(i,j);
                initVisited();
            }
        }
    }
    cout << MAX-1 << endl;



    return 0;
}