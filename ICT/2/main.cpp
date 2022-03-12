#include <iostream>
#include <string>
#include <vector>
#include <queue>
 #define INF 1e9
using namespace std;

int d[300000] = {0,};
int d2[300000] = {0,};
vector<pair<int,int>> vec[300000];

 void initD(int n) {
     for (int i = 0; i < n; i++) {
         d[i]= INF;
     }
 }

 void initD2(int n) {
     for (int i = 0; i < n; i++) {
         d2[i]= INF;
     }
 }
void initVec(vector<vector<int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        vec[from].push_back({to,1});
        vec[to].push_back({from, 1});
    }
}

 struct cmp {
     bool operator() (pair<int,int> a, pair<int,int> b) {
         return a.second > b.second;
     }
 };
 void dijkstra(int start, int *dist) {
     priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
     que.push({start, 0});
     dist[start] = 0;

     while (!que.empty()) {
         int cur = que.top().first;
         int distance = que.top().second;
         que.pop();

         if (distance > dist[cur]) continue;
         for (int i = 0; i < vec[cur].size(); i++) {
             int next = vec[cur][i].first;
             int nextDist = dist[cur] + vec[cur][i].second;

             if (dist[next] > nextDist) {
                 dist[next] = nextDist;
                 que.push({next, nextDist});
             }
         }
     }
 }
long long solution(int n, vector<vector<int>> edges) {
    long long answer = 0;

    initVec(edges);

    for (int i = 0; i < n; i++) {
        initD(n);
        dijkstra(i, d); // I에서 모든 노드까지 최단 거리

        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            initD2(n);
            dijkstra(j, d2); // J에서 모든 노드까지 최단 거리

            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;
                int dist1 = d[j];
                int dist2 = d2[k];
                int dist3 = d[k];
                if (dist1 == 0 || dist2 == 0 || dist3 == 0) {
                    cout << "exp : " << i << " -> " << j << " -> " << k << endl;
                    cout << dist1 << " + " << dist2 << " = " << dist3 << " " << endl;
                    continue;
                }

                cout << i << " -> " << j << " -> " << k << endl;
                cout << dist1 << " + " << dist2 << " = " << dist3 << " ";
                if (dist1 + dist2 == dist3) {
                    cout << "is Answer !! " << endl;
                    answer++;
                }
                cout << endl;
            }
        }
    }
    dijkstra(0, d2);
    return answer;
}

int main() {
     // 5, {{0,1}, {0,2},{1,3},{1,4}}
     cout << solution(4, {{2,3}, {0,1},{1,2}});
 }