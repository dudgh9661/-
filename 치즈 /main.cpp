#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector< pair<int,int>> doMeltCheese; // row, col
vector< pair<int,int>> cheese; // row, col
int UD[4] = {1,-1,0,0};
int LR[4] = {0,0,-1,1};
int arr[101][101] = { 0 };
bool visited[101][101] = { false };
void init() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = -1;
        }
    }
    int input;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> input;
            if( input == 1 ) {
                arr[i][j] = 1;
                cheese.push_back({i,j});
            }
        }
    }
}
bool inRange(int row, int col ) {
    if( row < 0 || col < 0 || row >= N || col >= M ) return false;
    else return true;
}
void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void BFS(int r, int c) {
    queue<pair<int,int>> que;
    visited[r][c] = true;
    arr[r][c] = 0;
    que.push({r,c});
    while( !que.empty() ) {
        int cR = que.front().first;
        int cC = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nr = cR + UD[i];
            int nc = cC + LR[i];
            if( inRange(nr, nc) ) {
                if( arr[nr][nc] == -1 && !visited[nr][nc] ) {
                    que.push({nr,nc});
                    visited[nr][nc] = true;
                    arr[nr][nc] = 0;
                }
            }
        }
    }
}
//녹아야 될 치즈값 저장
void meltedCheese(int row, int col) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int nr = row + UD[i];
        int nc = col + LR[i];
        if( inRange(nr,nc) ) {
            if( arr[nr][nc] == 0 ) cnt++;
        }
    }
    if( cnt >= 2 ) doMeltCheese.push_back({row, col}); //녹는 치즈라면, vec에 정보를 저장한다.
}
bool melting() {
    int isMelted = false;
    for(int i = 0; i < doMeltCheese.size(); i++) { //melting
        arr[doMeltCheese[i].first][doMeltCheese[i].second] = 0;
        isMelted = true;
    }
    return isMelted;
}
void initV() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if( arr[i][j] != 1 ) arr[i][j] = -1;
            else if ( arr[i][j] == 1 ) cheese.push_back({i,j});
        }
    }
}
int main() {
    init();
    int hour = 0;
    while( true ) {
        BFS(0, 0);
        //녹을 치즈 정보를 찾는다.
        for(int i = 0; i < cheese.size(); i++) {
            meltedCheese(cheese[i].first, cheese[i].second);
        }
        //녹을 치즈(doMeltCheese에 저장된)들을 녹인다. 만약, 녹일 치즈가 없다면 탈출한다.
        if( !melting() ) break;
        //
        doMeltCheese.clear();
        doMeltCheese.resize(0);
        cheese.clear();
        cheese.resize(0);
        initV();
        hour++;
    }
    cout << hour << endl;
    return 0;
}