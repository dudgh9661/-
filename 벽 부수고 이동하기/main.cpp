#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int MIN = 10000;

vector< vector<int> > vec;
vector< pair<int,int> > onePos;

int visited[1000][1000][2] = { 0 };
int UD[4] = {-1, 0, 1, 0};
int LR[4] = { 0, -1, 0 ,1};

/*
 * 1. 1을 제거하고, BFS를 돌린다.
 *
 * "sol"
 *
 * 벽 부수기를 사용했을 경우와 안했을 경우로 케이스가 나뉜다.
 * 1. 다음칸이 벽이고, 벽 부수기 사용 안했을 경우
 * 2. 다음칸이 벽이 아니고, 방문하지 않았을 경우 이 2가지만 queue에 들어갈 수 있는 조건이 됨.
 */
void init() {
    cin >> N >> M;
    string input;

    for(int i = 0; i < N; i++) {
        vector<int> tmp;
        cin >> input;

        for(int j = 0; j < M; j++) {
            tmp.push_back(input[j]-'0');
            if( input[j]-'0' == 1 ) onePos.push_back({i,j});
        }

        vec.push_back(tmp);
    }
}

int BFS() {
    queue<pair<pair<int, int>, int> > que;
    que.push({{0, 0}, 0});

    while (!que.empty()) {

        int curR = que.front().first.first;
        int curC = que.front().first.second;
        int isBroken = que.front().second; //0 : 미사용, 1 : 사용
        que.pop();

        if (curR == N - 1 && curC == M - 1) {
            return visited[curR][curC][isBroken];
        }

        for (int i = 0; i < 4; i++) {
            int nextR = curR + UD[i];
            int nextC = curC + LR[i];
            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) continue;

            //다음칸이 벽이고, 벽을 안부쉈다면
            if (vec[nextR][nextC] == 1 && isBroken == 0) {
                visited[nextR][nextC][1] = visited[curR][curC][isBroken] + 1;
                que.push({{nextR, nextC}, 1});
            } else if (vec[nextR][nextC] == 0 && visited[nextR][nextC][isBroken] == 0) { //다음칸이 벽이 아니고, 방문하지 않았으면
                visited[nextR][nextC][isBroken] = visited[curR][curC][isBroken] + 1;
                que.push({{nextR, nextC}, isBroken});
            }
        }

    }

    return -2;
}


//void initVisited() {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0;  j < M; j++) {
//            visited[i][j] = 0;
//        }
//    }
//}
int main() {
    init();
    cout << BFS() + 1;


//    if( MIN == 10000 ) cout << -1 << endl;
//    else cout << MIN << endl;

    return 0;
}
