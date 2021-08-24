#include <iostream>
#include <queue>

using namespace std;

int N;

int mvR[6] = {-2,-2,0,0,2,2};
int mvC[6] = {-1,1,-2,2,-1,1};

pair<int, int> from;
pair<int, int> to;
int visited[200][200] = { 0 };

bool inRange(int r, int c) {
    if ( r < 0 || r >= N || c < 0 || c >= N ) return false;
    return true;
}

void BFS() {
    queue<pair<int,int>> que;
    que.push({from.first, from.second});

    while( !que.empty()) {
        int cr = que.front().first;
        int cc = que.front().second;
        que.pop();

        for(int i = 0; i < 6; i++) {
            int nr = cr + mvR[i];
            int nc = cc + mvC[i];
            if (nr == from.first && nc == from.second) continue;
            if ( !inRange(nr,nc) ) continue;
            if ( visited[nr][nc] != 0 ) continue;

            visited[nr][nc] = visited[cr][cc] + 1;
            //find target
            if (nr == to.first && nc == to.second) return;
            que.push({nr,nc});
        }
    }
}
void init() {
    cin >> N;
    cin >> from.first >> from.second >> to.first >> to.second;
}

int main() {
    init();
    if (from.first == to.first && from.second == to.second ) {
        cout << 0;
        return 0;
    }
    BFS();
    int ans = visited[to.first][to.second];
    if (ans == 0) cout << -1;
    else cout << ans;
    return 0;
}
