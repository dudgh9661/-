#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M; //정점, 간선
int ans = 0;

vector<int> node[1001];
bool visited[1001] = { false };

void init() {
    cin >> N >> M;
    int from, to;

    for(int i = 0; i < M; i++) {
        cin >> from >> to;
        node[from].push_back(to);
        node[to].push_back(from);
    }
}

void BFS(int start) {
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while( !que.empty() ) {
        int cur = que.front();
        que.pop();

        for(int i = 0; i < node[cur].size(); i++) {
            int next = node[cur][i];
            if( visited[next] ) continue;
            que.push(next);
            visited[next] = true;
        }
    }
}
int main() {
    init();
    for(int i = 1; i <= N; i++) {
        if( !visited[i] ) {
            BFS(i);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
