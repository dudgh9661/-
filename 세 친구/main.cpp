#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int MIN = 1e9;

vector<int> friends;

bool relation[4001][4001] = { false };
int inDegree[4001] = { 0 };
void init() {
    cin >> N >> M;
    int to, from;
    for(int i = 0; i < M; i++) {
        cin >> to >> from;
        relation[to][from] = true;
        relation[from][to] = true;
        inDegree[to]++;
        inDegree[from]++;
    }
}

bool isFriends(int cur) {
    if ( friends.empty() ) return true;
    for (int fr : friends) {
        if ( !relation[cur][fr] ) return false;
    }
    return true;
}

void DFS(int cnt, int start) {
    if ( cnt == 3 ) {
        int sum = 0;
        for(int fr : friends) {
            sum += inDegree[fr];
        }
        sum -= 6;
        MIN = min(MIN, sum);
        return;
    }

    for(int i = start; i <= N; i++) {
        if (!isFriends(i)) continue;
        friends.push_back(i);
        DFS(cnt+1, i+1);
        friends.pop_back();
    }
}
int main() {
    init();
    DFS(0,1);
    if ( MIN == 1e9 ) cout << -1;
    else cout << MIN;
    return 0;
}
