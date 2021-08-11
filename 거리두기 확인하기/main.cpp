#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>


using namespace std;

bool visited[5][5] = { false };
vector<pair<int,int>> pos;

int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};

int manhatten(pair<int, int> a, pair<int,int> b) {
    int dist = abs(a.first - b.first) + abs(a.second - b.second);
    return dist;
}

bool inRange(int r, int c) {
    if ( r < 0 || r > 4 || c < 0 || c > 4 ) return false;
    return true;
}

//맨해튼 거리가 <= 2인 경우
int BFS(int sr, int sc, int tr, int tc, vector<string> place) {
    queue<pair<int,int>> que;
    visited[sr][sc] = true;
    que.push({sr,sc});

    while (!que.empty()) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for(int i = 0 ; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];

            if (visited[nr][nc]) continue;
            if (!inRange(nr,nc)) continue;
            if (place[nr][nc] == 'X') continue;

            int dist = manhatten({sr,sc},{nr,nc});
            if (dist > 2) continue;
            if ( dist <= 2) {
                if (place[nr][nc] == 'P') {
                    return 0;
                }
                que.push({nr,nc});
                visited[nr][nc] = true;
            }
        }
    }

    return 1;
}

void initVisited() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            visited[i][j] = false;
        }
    }
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int tc = 0; tc < places.size(); tc++) {
        pos.clear();
        pos.resize(0);

        //pos init
        for (int i = 0; i < places[tc].size(); i++) {
            for (int j = 0; j < places[tc][i].size(); j++) {
                if (places[tc][i][j] == 'P') pos.push_back({i, j});
            }
        }

        //do
        int res = 1;
        for (int i = 0; i < pos.size(); i++) {
            pair<int, int> a = pos[i];

            for (int j = i + 1; j < pos.size(); j++) {
                pair<int, int> b = pos[j];
                if (manhatten(a, b) <= 2) {
                    initVisited();
                    res = BFS(a.first, a.second, b.first, b.second, places[tc]);
                    if (res == 0) { // 거리두기 불충족
                        break;
                    }
                }
            }
            if ( res == 0 ) break;
        }

        //result
        answer.push_back(res);
    }

    return answer;
}

int main() {
    solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
              {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
              {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
    return 0;
}