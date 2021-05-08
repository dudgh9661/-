#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int INF = 1e9;

int d[1001] = { 0 };
int map[1001][1001];

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

void init(vector<vector<int>> roads) {
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            map[i][j] = INF;
        }
    }
    for(int i = 0; i < roads.size(); i++) {
        int from = roads[i][0];
        int to = roads[i][1];
        int val = roads[i][2];

        map[from][to] = min(map[from][to], val);
    }

    //최단 거리 초기화
    for(int i = 1; i <= 1000; i++) d[i] = INF;
}
bool isTrap(int node, vector<int> traps) {
    for(int i = 0; i < traps.size(); i++) {
        if( node == traps[i] ) return true;
    }
    return false;
}

//방향을 바꾸는 함수
void trapTrigger(int node, int total) {
    for(int i = 1; i <= total; i++) {
        if( map[node][i] != INF ) {
            int tmp = map[node][i];
            map[node][i] = INF;
            map[i][node] = tmp;
//            cout << "case !INF : " << node << "->" << i << " <<change>> " << node << " <- " << i << " value : " << tmp << endl;
        } else if ( map[node][i] == INF ) {
            if( map[i][node] != INF ) {
                int tmp = map[i][node];
                map[node][i] = tmp;
                map[i][node] = INF;
//                cout << "case INF : " << node << "->" << i << " <<change>> " << node << " <- " << i << " value : " << tmp << endl;
            }
        }
    }
}
void dijstra(int start, int end, int total, vector<int> traps) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp > pq;
    pq.push({start, 0});
    d[start] = 0;

    while( !pq.empty() ) {
        int cur = pq.top().first;
        int curDist = pq.top().second;
        pq.pop();

//        if( isTrap(cur, traps) ) {
//            cout << "push trap : " << cur << endl;
//            trapTrigger(cur, total);
//        }
        if( d[cur] < curDist ) continue;
        for(int i = 1; i <= total; i++) {
            if( map[cur][i] == INF ) continue; //warning
            int next = i;
            int nextDist = map[cur][next];
            int newDist = d[cur] + nextDist;
            if( next == end ) {
//                cout << d[end] << " and " << newDist << endl;
                d[end] = min(d[end], newDist);
                newDist = d[end];
            } else {
//            if( d[next] > INF ) {
                d[next] = newDist;
            }
                pq.push({next, newDist});
//                cout << "next : " << next << " newDist " << newDist << endl;
                if (isTrap(next, traps)) {
//                    cout << "push trap : " << next << endl;
                    trapTrigger(next, total);
//                }
                }

        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    init(roads);
    dijstra(start,end, n,traps);
    cout << d[end] << endl;
    answer = d[end];
    return answer;
}

int main() {
    solution(4,1,4,{{1,2,1},{3,2,1},{2,4,1}},{2,3});
    return 0;
}