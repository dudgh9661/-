#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000

using namespace std;

int N;

vector< pair<int,int> > vec[10001];
vector<int> tmp;
bool visited[10001] = { false };
/*
 *  트리의 지름 : 모든 경로들 중 가장 긴 것의 길이
 */

//각 정점을 기준으로, 다른 정점들로 가는 최단 거리를 계산.

//일단, 한 정점에서 모든 정점으로 최단거리를 BFS로 구현

int MAX = 0;

void BFS(int start) {
    queue< pair<int,int> > que;
    que.push({start, 0});
    visited[start] = true;

    while( !que.empty() ) {
        int front = que.front().first;
        int frontVal = que.front().second;
        que.pop();

        for(int i = 0; i < vec[front].size(); i++) {
            int next = vec[front][i].first;
            int nextVal = vec[front][i].second;

            if( !visited[next]) {
                int val = frontVal + nextVal;
                if( MAX < val ) MAX = val;
                que.push({next, val});
                visited[next] = true;
//                cout << front << " -> " << next << " : " << val << endl;
            }
        }
    }
}

void init() {
    cin >> N;
    if( N == 1 ) {
        return;
    }
    int from,to,val;
    for(int i = 0; i < N-1; i++) {
        cin >> from >> to >> val;
        vec[from].push_back({to, val});
        vec[to].push_back({from, val});
    }
}


int main() {
    init();
    if( N != 1 ) {
        for (int i = 1; i <= N; i++) {
            fill(visited, visited + N + 1, false);
            BFS(i);
        }
    }

    cout << MAX << endl;
    return 0;
}

