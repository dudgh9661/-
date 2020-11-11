#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000001
using namespace std;

int N, M;
int resF, resT;

long arr[1001][1001] = { 0 };
int tmp[1001];
//dist, node
priority_queue< pair<int, int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void init() {
    cin >> N >> M;

    //모든 거리 정보 저장
    for(int i = 1; i <= N; i++) {
        tmp[i] = INF;
        for(int j = 1; j <= N; j++) {
            arr[i][j] = INF;
            arr[i][i] = 0;
        }
    }

    int from, to, value;
    for(int i = 0; i < M; i++) {
        cin >> from >> to >> value;
        if( arr[from][to] > value ) arr[from][to] = value;
    }

    cin >> resF >> resT;
}
void dijk(int start) {
    for(int i = 1; i <= N; i++) {
        if( arr[start][i] != INF && start != i) {
//            cout << i << " : " << arr[start][i] << endl;
            pq.push({arr[start][i], i});
        }
    }
//    pq.push({0, start});

    while( !pq.empty() ) {
        int cur = pq.top().second;
        int curMinDist = pq.top().first; //start에서 cur까지 어떤 노드를 거쳐갔을 때의 최단 길이..?
//        cout << cur << " : " << curMinDist << endl;
        pq.pop();

        for(int i = 1; i <= N; i++) {
            if( arr[cur][i] != INF && cur != i) { //i는 현재 노드에서 인접한 노드를 의미한다.
                    int nextDist = curMinDist + arr[cur][i];

//                    cout << cur << " -> " << i << " : " << curMinDist << " + " << arr[cur][i] << endl;
                    if ( arr[start][i] > nextDist) {
                        arr[start][i] = nextDist;
                        pq.push({nextDist, i});
                    }
            }
        }
    }
}


int main() {
    init();
    dijk(resF);
    cout << arr[resF][resT] << endl;

    return 0;
}
