#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

vector<int> vec[1001];
bool visited[1001] = { false };

void init() {
    cin >> N >> M >> V;
    int from, to;
    for(int i = 0; i < M; i++) {
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    //sort
    for(int i = 1; i <= N; i++) {
        sort(vec[i].begin(), vec[i].end(), less<>());
    }
}

void DFS(int start) {
    visited[start] = true;
    cout << start << " ";

    for(int i = 0; i < vec[start].size(); i++) {
        int next = vec[start][i];
        if( visited[next] ) continue;
        DFS(next);
    }
}

void BFS(int start) {
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while( !que.empty() ) {
        int cur = que.front();
        cout << cur << " ";
        que.pop();

        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i];
            if( visited[next] ) continue;
            visited[next] = true;
            que.push(next);
        }
    }
}
int main() {
    init();
    DFS(V);
    fill(visited,visited+1001, false);
    cout << "\n";
    BFS(V);
    return 0;
}

