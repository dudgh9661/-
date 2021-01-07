#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int V, E, K;

int d[20001] = { 0 };
vector<pair<int,int>> vec[20001];

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

void init() {
    cin >> V >> E; //정점, 간선의 개수
    cin >> K;

    int from, to, val;
    for(int i = 0; i < E; i++) {
        cin >> from >> to >> val;
        vec[from].push_back({to, val});
    }
    fill(d, d+20001, INF);
}
void dijstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    d[K] = 0;
    pq.push({K,0});

    while( !pq.empty() ) {
        int cur = pq.top().first;
        int curDis = pq.top().second;
        pq.pop();

//        if( d[cur] < curDis ) continue;
        for(int i = 0; i < vec[cur].size(); i++) {
            int nextNode = vec[cur][i].first;
            int nextDist = vec[cur][i].second;

            int newDist = nextDist + d[cur];
            if( d[nextNode] > newDist ) {
                d[nextNode] = newDist;
                pq.push({nextNode, newDist});
            }
        }
    }
}
int main() {
    init();
    dijstra();
    for(int i = 1; i <= V; i++) {
        if( d[i] == INF ) cout << "INF" << "\n";
        else cout << d[i] << "\n";
    }
    return 0;
}
