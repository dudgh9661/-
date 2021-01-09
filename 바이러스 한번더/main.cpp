#include <iostream>
#include <vector>

using namespace std;

int N, M;
int ans = 0;

vector<int> vec[101];
bool visited[101] = { false };

void init() {
    cin >> N >> M;

    int from , to;
    for(int i = 0; i < M; i++) {
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }
}
void DFS(int node) {
    visited[node] = true;

    for(int i = 0; i < vec[node].size(); i++) {
        int next = vec[node][i];
        if( visited[next] ) continue;
        ans++;
        DFS(next);
    }
}

int main() {
    init();
    DFS(1);
    cout << ans << endl;
    return 0;
}
