#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M, R;

int NODE[101] = { 0 };
int d[101] = { 0 };
vector<pair<int,int>> vec[101];

void init() {
    cin >> N >> M >> R;

    int a;
    for(int i = 1; i <= N; i++) {
        cin >> a;
        NODE[i] = a;
        d[i] = INF;
    }

    int from, to, val;
    for(int i = 0; i < R; i++) {
        cin >> from >> to >> val;
        vec[from].push_back({to,val});
        vec[to].push_back({from,val});
    }
}

struct cmp{
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};
void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    d[start] = 0;
    pq.push({start, 0});

    while( !pq.empty() ) {
        int cur = pq.top().first;
        int curDist = pq.top().second;
        pq.pop();

        if( d[cur] < curDist ) continue;
        for(int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;
            int nextDist = vec[cur][i].second;
            int newDist = d[cur] + nextDist;
            if( d[next] > newDist ) {
                d[next] = newDist;
                pq.push({next,newDist});
            }
        }
    }
}
int main() {
    int answer = 0;
    init();
    for(int i = 1; i <= N; i++) {
        int item = 0;
        fill(d, d+N+1, INF);

        dijkstra(i);
        for (int i = 1; i <= N; i++) {
            if( d[i] <= M ) item += NODE[i];
        }
        answer = max(item, answer);
    }

    cout << answer << endl;
    return 0;
}
