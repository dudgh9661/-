#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[1001];
bool visited[1001] = { false };

int N, M;
int cnt = 0;


void init() {
    
    
    for(int i = 0; i < 1001; i++) vec[i].clear();
    fill(visited, visited + 1001, false);
    
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }
}

void BFS(int start) {
    queue<int> que;
    que.push(start);
    visited[start] = true;
    
    while( !que.empty() ) {
        int front = que.front();
        que.pop();
        
        for(int i = 0; i < vec[front].size(); i++) {
            int next = vec[front][i];
            if( visited[next] ) continue;
            
            visited[next] = true;
            que.push(next);
            cnt++;
        }
    }
}

int main()
{
    int tc = 0;
    cin >> tc;
    
    for(int i = 0; i < tc; i++) {
        init();
        BFS(1);
        cout << cnt << endl;
        cnt = 0;
    }
    return 0;
}

