#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int H, W;
int ans = 0;

pair<int,int> start{-1,-1};
pair<int,int> target{-1,-1};
int arr[101][101] = { 0 };
int visited[101][101] = { 0 };

int UD[4] = {1,-1,0,0};
int LR[4] = {0,0,-1,1};
/*
 * output : the number of min mirror
 */

void Print() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if( visited[i][j] == 1e7 ) cout << 0 << " ";
            else cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}
typedef struct pos{
    int r, c, arrow, mir;
}POS;

bool inRange(int r, int c) {
    if (r >= H || r < 0 || c >= W || c < 0 || arr[r][c] == -100 ) return false;
    else return true;
}

void BFS() {
    queue<POS> que; //r,c, arrow
    for(int i = 0; i < 4; i++) {
        que.push({start.first, start.second,i,1});
//        int nr = start.first + UD[i];
//        int nc = start.second + LR[i];
//        if (inRange(nr, nc)) {
//            que.push(POS{nr, nc, i, 0});
//            visited[nr][nc] = 0;
//        }
    }
    visited[start.first][start.second] = 0;

    while( !que.empty() ) {
        int r = que.front().r;
        int c = que.front().c;
        int arrow = que.front().arrow; //pre arrow;
        int mirror = que.front().mir;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];
            int mir = mirror;
            if( nr < 0 || nc < 0 || nr >= H || nc >= W ) continue;
            if( arr[nr][nc] == -100 ) continue;

//            if( inRange(nr,nc) ) {
                if( arrow != i ) mir += 1;
                if( visited[nr][nc] >= mir ) {
                    visited[nr][nc] = mir;
                    que.push({nr,nc,i,mir});
//                }
//                if (arrow == i) {
//                    if (visited[nr][nc] >= mirror) {
//                        visited[nr][nc] = mirror;
//                        que.push({nr, nc, i, mirror});
//                    }
//                } else if (arrow != i) {
//                    if (visited[nr][nc] >= mirror + 1) {
//                        visited[nr][nc] = mirror + 1;
//                        que.push({nr, nc, i, mirror+1});
//                    }
//                }
            }
        }
    }
}

void init() {
    cin >> W >> H;

    char ch;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            visited[i][j] = 1e7;
            cin >> ch;
            if( ch == '.') {
                arr[i][j] = 0;
            } else if (ch == 'C') {
                arr[i][j] = 100;
                if( start.first == -1) {
                    start.first = i;
                    start.second = j;
                } else {
                    target.first = i;
                    target.second = j;
                }

            } else if (ch == '*') {
                arr[i][j] = -100;
            }
        }
    }
}
int main() {
    init();
    BFS();
//    printf("%d %d and %d %d\n", start.first, start.second, target.first, target.second);
//    Print();
    cout << visited[target.first][target.second] - 1<< endl;
    return 0;
}
