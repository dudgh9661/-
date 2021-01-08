#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;

int N, M;
int ansFrom, ansTo;

int map[1001][1001] = {0};
int d[1001] = {0};
struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};
void init() {
    cin >> N;
    cin >> M;

    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) map[i][j] = INF;
    }
    fill(d,d+1001, INF);

    int from, to, val;
    for(int i = 0; i < M; i++) {
        cin >> from >> to >> val;
        if( val < map[from][to] ) map[from][to] = val;
    }

    cin >> ansFrom;
    cin >> ansTo;
}

void dijstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    d[start] = 0;
    pq.push({start, 0});

    while( !pq.empty() ) {
        int cur = pq.top().first;
        int curDist = pq.top().second;
        pq.pop();
        if(d[cur] < curDist) continue;
        for(int i = 1; i <= N; i++) {
            if( map[cur][i] == INF ) continue; //거쳐갈 수 없는, 목적지 노드를 거르는 코드
            if( start == i ) continue;
            int nextNode = i;
            int nextDist = map[cur][nextNode];
            int newDist = d[cur] + nextDist;
            if(d[nextNode] > newDist ) {
                d[nextNode] = newDist;
                pq.push({nextNode, newDist});
            }
        }
    }
}
int main() {
    init();
    dijstra(ansFrom);
    cout << d[ansTo];
//    for(int i = 1; i <= N; i++) {
//        cout << d[i] << "\n";
//    }
    return 0;
}
