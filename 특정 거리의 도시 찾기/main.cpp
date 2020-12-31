#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>

#define MAX 300001
#define INF 1e9

using namespace std;

int N, M, K, X;

vector< pair<int,int> > map[MAX];

int d[MAX];
struct cmp{
    bool operator()(pair<int,int> a, pair<int, int> b ) {
        return a.first > b.first;
    }
};

void dijkstra(int to) {
    d[to] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int>>, cmp> pq; //dist, node
    pq.push({0, to});

    while( !pq.empty() ) {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if( d[cur] < dist ) continue; //예를 들어, 1->des 거리가 2, 1->cur가 3이면, 1->cur->des를 비교해봤자 의미가 없으므로 pass.
        for(int i = 0; i < map[cur].size(); i++) {
            int nextDist = dist + map[cur][i].first;
            int next = map[cur][i].second;
            if( d[next] > nextDist ) {
                d[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

}

void init() {
    cin >> N >> M >> K >> X;


    int to, from;
    for(int i = 0; i < M; i++) {
        cin >> to >> from;
        map[to].push_back({1,from});
    }

//    d.push_back(-100);
    for(int i = 1; i <= N; i++) {
        d[i] = INF;
//        d.push_back(INF);
    }
}
int main() {
    init();
    dijkstra(X);

    int flag = 0;
    for(int i = 1; i <= N; i++) {
        if( d[i] == K ) {
            flag = 1;
            cout << i << " ";
        }
    }
    if( flag == 0 ) cout << -1;

    return 0;
}
