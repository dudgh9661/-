#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[500][500] = { 0 };
bool visited[500][500] = { false };
int UD[4] = {1,-1,0,0};
int LR[4] = {0,0,-1,1};

int N, M;
int MAX = 0;

void init() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
}
bool inRange(int r, int c) {
    if( r < 0 || r >= N || c < 0 || c >= M ) return false;
    else return true;
}

void DFS(int n, int r, int c, int cnt) {
   if( n == 3) {
       MAX = max(MAX, cnt);
       return;
   }

   for(int i = 0; i < 4; i++) {
       int nr = r + UD[i];
       int nc = c + LR[i];
       if (!inRange(nr,nc)) continue;
       if (visited[nr][nc]) continue;

       visited[nr][nc] = true;

       DFS(n + 1, nr, nc, cnt + arr[nr][nc]);

       visited[nr][nc] = false;
   }
}

int shape(int r, int c) {
    if ( r+1 >= N || c+1 >= M || c+2 >= M ) { // out of range
        return 0;
    } else {
        return arr[r][c] + arr[r][c+1] + arr[r][c+2] + arr[r+1][c+1];
    }
}
int shape2(int r, int c) {
    if( r-1 < 0 || r+1 >= N || c+1 >= M) return 0;
    else {
        return arr[r][c] + arr[r-1][c+1] + arr[r][c+1] + arr[r+1][c+1];
    }
}
int shape3(int r, int c) {
    if (c+1 >= M || c+2 >= M || r+1 >= N) return 0;
    else {
        return arr[r][c] + arr[r][c+1] + arr[r][c+2] + arr[r-1][c+1];
    }
}
int shape4(int r, int c) {
    if( r-1 < 0 || r+1 >= N || c+1 >= M ) return 0;
    else {
        return arr[r][c] + arr[r-1][c] + arr[r+1][c] + arr[r][c+1];
    }
}

int main() {
    init();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = true;
            DFS(0, i, j, arr[i][j]);
            visited[i][j] = false;

            MAX = max(MAX, shape(i,j));
            MAX = max(MAX, shape2(i,j));
            MAX = max(MAX, shape3(i,j));
            MAX = max(MAX, shape4(i,j));
        }
    }

    cout << MAX;
    return 0;
}
