#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9;
using namespace std;

int arr[100] = { 0 };
vector<pair<int,int>> vec[100];
int d[100][100];

int n, m, r;

void init() {
    cin >> n >> m >> r;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr[i] = input;
        for (int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < r; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        vec[from-1].push_back({to-1, val});
        vec[to-1].push_back({from-1, val});
    }
}

struct cmp {
    bool operator() (pair<int,int> p1, pair<int,int> p2) {
        return p1.second > p2.second;
    }
};

void dijkstra (int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> que; // 지역, 거리
    que.push({start, 0});
    d[start][start] = 0;

    while (!que.empty()) {
        int cur = que.top().first;
        int dist = que.top().second;
        que.pop();

        if (dist > d[start][cur]) continue;
        for (int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].first;
            int nextDist = vec[cur][i].second;
            if (d[start][next] > dist + nextDist) {
                d[start][next] = dist + nextDist;
                que.push({next, dist + nextDist});
            }
        }
    }
}
int main() {
    init();
    for (int i = 0; i < n; i++) {
        dijkstra(i);
    }

    int MAX = 0;
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (d[i][j] > m) continue;
            ans += arr[j];
        }
        MAX = max(MAX, ans);
    }

    cout << MAX << endl;
    return 0;
}
