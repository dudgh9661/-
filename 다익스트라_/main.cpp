#include <iostream>
#include <vector>
#include <queue>

#define INF 200000
#define MAX 20001

using namespace std;

int V, E, K;

vector< pair<int,int> > vec[MAX];
int arr[MAX] = { 0 };

void init() {
    cin >> V >> E;
    cin >> K;

    int from, to, value;
    for(int i = 0; i < E; i++) {
        cin >> from >> to >> value;
        vec[from].push_back({to, value});
    }

    for(int i = 1; i <= V; i++) {
        arr[i] = INF;
    }
}

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if( a.second == b.second ) return a.first > b.first;
        else return a.second > b.second;
    }
};

void dijkstra(int start) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, cmp > pq;
    arr[start] = 0;
    pq.push({start, 0});

    while( !pq.empty() ) {
        int current = pq.top().first;
        int curVal = pq.top().second;
        pq.pop();
        
        if( arr[current] < curVal ) continue;
        for(int i = 0; i < vec[current].size(); i++) {
            int next = vec[current][i].first;
            int nextVal = vec[current][i].second;

            if( arr[next] > curVal + nextVal) {
                arr[next] = curVal + nextVal;
                pq.push({next, curVal + nextVal});
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    dijkstra(K);

    for(int i = 1; i <= V; i++) {
        if( arr[i] == INF ) cout << "INF" << "\n";
        else cout << arr[i] << "\n";
    }
    return 0;
}
