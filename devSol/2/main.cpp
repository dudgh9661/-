#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int arr[7][7] = { 0 };

int UD[4] = {-1,1,0,0};
int LR[4] = {0,0,-1,1};
bool visited[7][7] = { false };

bool check = true;

bool inRange(int r, int c) {
    if ( r < 1 || r > 6 || c < 1 || c > 6 ) return false;
    return true;
}

void BFS(int r, int c, int color, vector<pair<int,int>>& pos) {
    queue<pair<int,int>> que;
    que.push({r,c});
    visited[r][c] = true;
    pos.push_back({r,c});

    while (!que.empty()) {
        int cr = que.front().first;
        int cc = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + UD[i];
            int nc = cc + LR[i];
            if (!inRange(nr,nc) || visited[nr][nc] || arr[nr][nc] != color) continue;

            que.push({nr,nc});
            pos.push_back({nr,nc});
            visited[nr][nc] = true;
        }
    }
}

void boom(vector<pair<int,int>>& pos) {
    if (pos.size() >= 3) {
        check = true;
        for (auto p : pos) {
            arr[p.first][p.second] = 0;
        }
    }
}

void setMap(int col, int color) {
    for (int r = 6; r >= 1; r--) {
        if (arr[r][col] == 0 ) {
            arr[r][col] = color;
            return;
        }
    }
}

void Print() {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void doMove() {
    for (int c = 1; c <= 6; c++) {
        cout << "hi";
        int pos = -1;
        vector<int> tmp;
        for (int r = 6; r >= 1; r--) {
            if (arr[r][c] == 0) {
                pos = r;
                break;
            }
        }
        cout << "pos : " << pos << endl;
        if (pos == -1) continue;
        for (int r = pos; r >= 1; r--) {
            if (arr[r][c] != 0) tmp.push_back(arr[r][c]);
        }

        for (int i = 0; i < tmp.size(); i++) {
            arr[pos--][c] = tmp[i];
        }
    }
}


void visitedInit() {
    for(int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) visited[i][j] = false;
    }
}
vector<string> solution(vector<vector<int>> macaron) {
    vector<string> answer;

    for(auto m : macaron) {
        setMap(m[0],m[1]);
        check = true;

        while (check == true) {
            check = false;
            for(int i = 1; i <= 6; i++) {
                for (int j = 1; j <= 6; j++) {
                    if (arr[i][j] == 0) continue;
                    vector<pair<int,int>> pos;
                    BFS(i,j,arr[i][j],pos);
                    boom(pos);
                    visitedInit();
                    doMove();
                }
            }
            break;
        }
    }
    // 2. 터질것이 있는지 확인
    // 3. 1을 반복

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return answer;
}

int main() {
    solution({{1, 1}, {2, 1}, {1, 2}, {3, 3}, {6, 4}, {3, 1}, {3, 3}, {3, 3}, {3, 4}, {2, 1}});
    return 0;
}