#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<int> vec[100001];
int parent[100001] = { 0 };
bool visited[100001] = { false };

void BFS() {
    queue<int> que;
    que.push(1);
    visited[1] = true;

    while( !que.empty() ) {
        int cur = que.front();
        que.pop();

        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i];
            if( visited[next] ) continue;
            que.push(next);
            visited[next] = true;
            parent[next] = cur;
        }
    }
}

void init() {
    cin >> N;

    int a,b;
    parent[1] = -1;

    for(int i = 0; i < N-1; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    BFS();

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}
