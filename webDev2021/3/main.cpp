#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int UD[4] = {-1,0,1,0};
int LR[4] = {0,-1,0,1};

vector<int> vec;

bool inRange(int r, int c) {
    if ( r < 0 || r >= 3 || c < 0 || c >= 9) return false;
    return true;
}

char map[3][9] = {
        {'q','w','e','r','t','y','u','i','o'},
        {'p','a','s','d','f','g','h','j','k'},
        {'l','z','x','c','v','b','n','m','!'}
};

int visited[3][9] = { 0 };
void initVistied() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 9; ++j) {
           visited[i][j] = 0;
        }
    }
}


int BFS(int r, int c, char target) {
    queue<pair<int,int>> que;
    visited[r][c] = 0;
    que.push({r,c});

    while (!que.empty()) {
        int cr = que.front().first;
        int cc = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + UD[i];
            int nc = cc + LR[i];
            if (nr == r && nc == c) continue;
            if (!inRange(nr, nc) || visited[nr][nc] != 0) continue;
            visited[nr][nc] = visited[cr][cc] + 1;
            if (map[nr][nc] == target) return visited[nr][nc];
            que.push({nr,nc});
        }
    }
}

pair<int,int> getChar(char ch) {
    for (int i = 0 ; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (map[i][j] == ch) return {i,j};
        }
    }
}

void DFS(string s, int limit, int size, int idx, string tmp) {
    if (limit == size) {
        cout << tmp << endl;
        for (int i = 0; i < tmp.size()-1; i++) {
            initVistied();
            int dist = 0;
            if (tmp[i] != tmp[i+1]) {
                auto p = getChar(tmp[i]);
                dist = BFS(p.first, p.second, tmp[i + 1]);
            }
            vec.push_back(dist);
        }
        return;
    }

    if (idx >= s.length()) return;
    tmp.push_back(s[idx]);
    DFS(s, limit, size + 1, idx + 1, tmp);
    tmp.pop_back();
}

void DFS2() {
    for (int i = 0; i < vec.size() / 2; i++) {

    }
}

int solution(string s) {
    int answer = -1;
    for (int i = 0; i < s.size(); i++) {
        DFS(s, 1, 0, i, "");
    }
    return answer;
}

int main() {
    solution("tooth");
    return 0;
}