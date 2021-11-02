#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;

int UD[4] = {-1, 0, 1, 0}; // U, L, D, R
int LR[4] = {0, -1, 0, 1};
bool visited[11][11] = {false};

int ans = 0;

struct info {
  int fromR, fromC, toR, toC;

//  bool operator< (info a, info b) {
//
//      return a.fromR < b.fromR;
//  }
};

set<info> st;
vector<info> vec;

bool inRange(int r, int c) {
    if (r < 0 || r > 10 || c < 0 || c > 10) return false;
    return true;
}

int getDir(char dir) {
    if (dir == 'U') return 0;
    if (dir == 'L') return 1;
    if (dir == 'D') return 2;
    if (dir == 'R') return 3;
    return -1;
}

bool isUnique(info a) {
    for (auto v : vec) {
        if (a.fromR == v.fromR && a.fromC == v.fromC && a.toR == v.toR && a.toC == v.toC) return false;
    }
    return true;
}
void DFS(string dirs, int curIdx, int r, int c) {
    if (curIdx >= dirs.length()) return;

    int dir = getDir(dirs[curIdx]);
    int nr = r + UD[dir];
    int nc = c + LR[dir];

    if (!inRange(nr,nc)) {
        // cout << "무시된 명령어 :" << dir << " idx : " << curIdx << endl;
        DFS(dirs, curIdx + 1, r, c);
    } else {
        info a = {r,c,nr,nc};
        info b = {nr,nc,r,c};
        if (isUnique(a) && isUnique(b)) vec.push_back(a);
//        st.insert({r,c,nr,nc});
//        cout << r << "," << c << "," << nr << "," << nc << endl;
        DFS(dirs, curIdx + 1, nr, nc);
    }
}

// 캐릭터 위치 (5,5)
int solution(string dirs) {
    int answer = 0;
    // visited[5][5] = true;
    DFS(dirs, 0, 5, 5);
    cout << "ans :" << vec.size() << endl;
    answer = vec.size();
    return answer;
}

int main() {
    cout << solution("ULURRDLLU");
    return 0;
}