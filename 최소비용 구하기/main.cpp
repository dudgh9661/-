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
void dijk2(int start) {
    pq.push({0, start});
    tmp[start] = 0;

    for(int i = 1; i <= N; i++) { //시작점과 인접한 노드들을 우선순위큐에 넣는다.
        pq.push({arr[start][i], i});
    }

    while( !pq.empty() ) {
        int current = pq.top().second; //시작점과 가장 가까운 노드
        int dist = pq.top().first;
        pq.pop(); //pop한다는 것은 방문을 의미.

        for(int i = 1; i <= N; i++) {
            int nextDist = tmp[i] + dist; //시작점에서 인접노드 i까지의 최단 거리 + 인접노드 i부터 현재 노드까지의 거리
            if( dist > nextDist ) { //맨처음 노드 -> 현재노드까지 직통 거리 > 돌아서오는 거리
                tmp[current] = nextDist; //바꾼다.
                pq.push({nextDist, i}); //push한다는 것은, 방문 대기 목록에 넣는 것.
            }
        }
    }

}

int main() {
    init();
//    Print();
//    dijk2(resF);
    dijk(resF);
    cout << arr[resF][resT] << endl;

    return 0;
}
