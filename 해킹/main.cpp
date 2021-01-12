#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

#define INF 1e9

using namespace std;

int comCnt = 0, T = 0;

vector<pair<int,int>> vec[10001];
vector<int> dij(10001, INF);

struct cmp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

void init(int n, int d, int c) {
    for(int i = 0; i <= n; i++) {
        vec[i].clear();
        vec[i].resize(0);
        dij[i] = INF;
    }

    int a,b,s;
    for(int i = 0; i < d; i++) {
        cin >> a >> b >> s;
        vec[b].push_back({a,s}); //a가 b에 의존, b가 감염되면 a도 감염 하지만 a가 감염되면 b는 감염되지 않는다. a<-b로 생각
    }
}

void dijstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({start,0});
    dij[start] = 0;

    while( !pq.empty() ) {
        int cur = pq.top().first;
        int curDist = pq.top().second;
        pq.pop();

        if(dij[cur] < curDist ) continue;
        comCnt++;
        if( T < curDist ) T = curDist;
        for(int i = 0; i < vec[cur].size(); i++) {
           int next = vec[cur][i].first;
           int twoPathDist = curDist + vec[cur][i].second;

           if(dij[next] > twoPathDist ) {
               dij[next] = twoPathDist;
               pq.push({next, twoPathDist});
//               printf("node : %d, val : %d\n", next, twoPathDist);
           }
        }
    }
}
int main() {
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        int n,d,c;
        cin >> n >> d >> c;
        init(n, d, c);
        dijstra(c);
        cout << comCnt << " " << T << "\n";
        comCnt = 0; T = 0;
    }
    return 0;
}
