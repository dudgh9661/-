#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
int N; // The number of Queen

bool visited[15][15] = { false };
vector<pair<int,int>> vec;

bool inRange(int r, int c) {
    if ( r < 0 || r >= N || c < 0 || c >= N ) return false;
    return true;
}

bool canMv(int nr, int nc) {
    for(int i = 1; i <= nr; i++) {
        if (inRange(nr-i,nc)) {
            if (visited[nr-i][nc]) return false;
        }
        if (inRange(nr-i, nc-i)) {
            if (visited[nr-i][nc-i]) return false;
        }
        if (inRange(nr-i,nc+i)) {
            if (visited[nr-i][nc+i])  return false;
        }
        if (inRange(nr,nc+i)) {
            if (visited[nr][nc+i])  return false;
        }
        if (inRange(nr,nc-i)) {
            if (visited[nr][nc-i])  return false;
        }
    }
    return true;
}

void DFS(int cr) {
    if ( cr == N ) {
//        cout << "find!" << endl;
//        for(pair<int,int> p : vec) {
//            cout << p.first << " , " << p.second << endl;
//        }
        cnt++;
        return;
    }

    for(int i = 0; i < N; i++) {
//        if (cr+1 >= N) return;
        if (canMv(cr,i)) {
            vec.push_back({cr,i});
            visited[cr][i] = true;
            DFS(cr+1);
            vec.pop_back();
            visited[cr][i] = false;
        }
    }
}
int main() {
    cin >> N;
    DFS(0);
    cout << cnt;
    return 0;
}
