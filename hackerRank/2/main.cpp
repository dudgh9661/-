#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int d[100001][100001] = {0}; // 노드 간 거리
vector<int> city[100001];
bool visited[100001] = { false };

void BFS(int start) {
    queue<int> que;
    visited[start] = true;
    d[start][start] = 0;
    que.push(start);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < city[cur].size(); i++) {
            int next = city[cur][i];
            if (visited[next]) continue;

            d[start][next] = d[start][cur] + 1;
            visited[next] = true;
            que.push(next);
        }
    }
}

void setD(int cityNum) {
    for (int i = 1; i <= cityNum; i++) {
        //visited 초기화
        for (int j = 0; j < 100001; j++) visited[j] = false;
        BFS(i);
    }
}

void init(vector<int> city_from, vector<int> city_to) {
    for (int i = 0; i < city_from.size(); i++) {
        int from = city_from[i];
        int to = city_to[i];
        city[from].push_back(to);
        city[to].push_back(from);
    }

    for (int i = 0; i < 100001; i++) {
        for (int j = 0; j < 100001; j++) {
            d[i][j] = INF;
        }
    }
}
int hospital(int city_nodes, vector<int> city_from, vector<int> city_to) {
    init(city_from, city_to);
    setD(city_nodes);

    for (int i = 1; i <= city_nodes; i++) {
        for (int j = 1; j <= city_nodes; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return -1;
}

int main() {
//    vector<int> city_from = {1,3,1,3,2,1};
//    vector<int> city_to = {2,6,4,7,5,3};
//    int a = hospital(city_from.size(), city_from, city_to);
    return 0;
}
