#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define INF 1e9

using namespace std;

int d[100001]; // 노드 간 거리
bool visited[100001] = { false };

vector<int> city[100001];
vector<vector<int>> oneWay;

void BFS(int start) {
    queue<int> que;
    visited[start] = true;
    d[start] = 0;
    que.push(start);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < city[cur].size(); i++) {
            int next = city[cur][i];
            if (visited[next]) continue;

            d[next] = d[cur] + 1;
            visited[next] = true;
            que.push(next);
        }
    }
}

void getOneway(int cityNum) {
    vector<int> tmp;
    for (int i = 1; i <= cityNum; i++) {
        if (d[i] <= 1) tmp.push_back(i);
    }
    oneWay.push_back(tmp);
}
void setDistance(int cityNum) {
    for (int i = 1; i <= cityNum; i++) {
        //visited 초기화
        for (int j = 1; j <= cityNum; j++) {
            visited[j] = false;
            d[j] = INF;
        }
        //거리 갱신
        BFS(i);
        getOneway(cityNum);
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
        d[i] = INF;
    }
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}
int hospital(int city_nodes, vector<int> city_from, vector<int> city_to) {
    city_nodes = 7;
    init(city_from, city_to);
    setDistance(city_nodes);
    int ans = 0;
    while (true) {
        map<int, int> mp;
        mp.clear();
        for (auto v : oneWay) {
            for (auto n : v) {
                cout << n << " ";
                mp[n]++;
            }
            cout << endl;
        }

        vector<pair<int, int>> tmp(mp.begin(), mp.end());
        sort(tmp.begin(), tmp.end(), cmp);
        if (tmp.empty()) cout << "tmp empty!!" << endl;
        int host = tmp[0].first;
        cout << "add hospital : " << host << endl;
        ans++;
        vector<vector<int>> tmpOneway;
        for (int i = 0; i < oneWay.size(); i++) {
            if (find(oneWay[i].begin(), oneWay[i].end(), host) == oneWay[i].end()) {
                tmpOneway.push_back(oneWay[i]);
            }
        }
        if (tmpOneway.empty()) break;
        oneWay = tmpOneway;
    }

    return ans;
}

int main() {
    vector<int> city_from = {1,3,1,3,2,1};
    vector<int> city_to = {2,6,4,7,5,3};
    int a = hospital(city_from.size(), city_from, city_to);
    return 0;
}
