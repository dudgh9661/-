#include <iostream>
#include <vector>
#include <queue>

#define INF 200000
using namespace std;

vector< pair<int,int> > arr[20001];
int d[20001] = { 0 };
int V = 0, E = 0, startV = 0;

void printArr() {
    for(int i = 1; i <= V; i++) {
        if ( d[i] == INF ) cout << "INF" << "\n";
        else cout << d[i] << "\n";
    }
}
void init() {
    cin >> V >> E;
    cin >> startV;

    for(int i = 1; i <= V; i++) {
        d[i] = INF;
    }

    for(int i = 0; i < E; i++) {
        int from = 0, to = 0, dist = 0;
        cin >> from >> to >> dist;
        arr[from].push_back({to, dist});
    }

//    printArr();
}

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b){
        if( a.second == b.second ) return a.first > b.first;
        return a.second > b.second;
    }
};

void dij() {
    d[startV] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, cmp > pq;
    pq.push({startV, 0}); //현재노드, 거리

    while ( !pq.empty() ) {
        int current = pq.top().first; //현재 노드
        int dist = pq.top().second; // 출발~현재노드까지의 거리
        pq.pop();
        if( d[current] < dist ) continue;

        for(int i = 0; i < arr[current].size(); i++) {
            int des = arr[current][i].first;
            int nextDis = dist + arr[current][i].second;

            if( d[des] > nextDis ) {
                d[des] = nextDis;
                pq.push({des, nextDis });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    dij();
    printArr();
    return 0;
}
