#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int answer  = 1;

string room[101][101];
vector<pair<int,int>> vec[101][101]; //스위치 정보
bool visited[101][101] = { false };
int UD[4] = {-1,1,0,0};
int LR[4] = {0,0,-1,1};

bool cmp(pair<int,int> a, pair<int,int> b) {
    if( a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
void init() {
    cin >> N >> M;

    int a,b,c,d;
    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d;
        vec[a][b].push_back({c,d});
        sort(vec[a][b].begin(), vec[a][b].end(), cmp);
    }
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            room[i][j] = "OFF";
        }
    }
    room[1][1] = "ON";
}

bool inRange(int r, int c) {
    if( r < 1 || r > N || c < 1 || c > N ) return false;
    return true;
}

void turnOn(int r, int c) {
    for(int i = 0; i < vec[r][c].size(); i++) {
        int _r = vec[r][c][i].first;
        int _c = vec[r][c][i].second;
        if( room[_r][_c] == "OFF" ) {
//            printf("(%d,%d) turn on (%d,%d)\n", r, c, _r, _c);
            room[_r][_c] = "ON";
            answer++;
        }
    }
}
void BFS() {
    queue<pair<int,int>> que;
    visited[1][1] = true;
    que.push({1,1});

    while( !que.empty() ) {
        int r = que.front().first;
        int c = que.front().second;
        turnOn(r,c);
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];

            if( visited[nr][nc] || !inRange(nr,nc) || room[nr][nc] == "OFF" ) continue;

            visited[nr][nc] = true;
            que.push({nr,nc});
        }
    }
}

void initVisited() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            visited[i][j] = false;
    }
}
int main() {
    init();
    while(true) {
        initVisited();
        int tmp = answer;
        BFS();
        if( tmp == answer ) break;
    }
    cout << answer << endl;
}

