#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int visited[5][5] = { 0 };
int map[5][5] = { 0 };
int LR[4] = {0,0,1,-1};
int UD[4] = {1,-1,0,0};

typedef struct applier {
    int r, c;
}Applier;

vector<Applier> P;
vector<pair<Applier, Applier>> applierVec; //맨해튼 거리가 2 이하인 사람들의 집합

//맵 초기화
void init(vector<string> input) {
    //map init
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) map[i][j] = 0;
    }
    //P clear
    P.clear();
    P.resize(0);

    for(int i = 0; i < input.size(); i++) {
        for(int j = 0; j < 5; j++) {
            if( 'P' == input[i][j] ) {
                map[i][j] = 1;
                Applier applier{i,j};
                P.push_back({applier.r, applier.c});
            }
            else if ( 'O' == input[i][j] ) map[i][j] = 1;
            else map[i][j] = 0; //파티션
        }
    }
}
void getGroup() {
    applierVec.clear();
    applierVec.resize(0);
    for(int i = 0; i < P.size(); i++) {
        int r1 = P[i].r;
        int c1 = P[i].c;
        for(int j = i+1; j < P.size(); j++) {
            int r2 = P[j].r;
            int c2 = P[j].c;
            int manhatten = abs(r1 - r2) + abs(c1 - c2);
            if( manhatten > 2 ) continue;
            else {
                Applier applier1{r1,c1};
                Applier applier2{r2,c2};
                applierVec.push_back({applier1, applier2});
            }
        }
    }
}
bool inRange(int row, int col) {
    if( row > 4 || row < 0 || col > 4 || col < 0 ) return false;
    return true;
}
bool BFS(Applier start, Applier target) {
    queue<pair<int,int>> que;
    que.push({start.r, start.c});
    visited[start.r][start.c]  = 0;

    while( !que.empty() ) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];
            if( nr == start.r && nc == start.c) continue; //시작점이라면
            if( visited[nr][nc] != 0 ) continue; //이미 방문했다면
            if( nr == target.r && nc == target.c && visited[nr][nc] <= 2) return false; //target에 닿았다는 것은 거리유지 실패란 의미
            if( !inRange(nr, nc) ) continue; //범위밖
            if( map[nr][nc] == 0 ) continue; //in case partition
            visited[nr][nc] = visited[r][c] + 1;
            if( visited[nr][nc] > 2 ) continue; //거리가 2가 넘는건 볼 필요가 없음
            que.push({nr,nc});
        }
    }
    return true;
}
void visitedInit() {
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) visited[i][j] = 0;
    }
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
//    vector<string> test = places[4];
    for(int tc = 0; tc < places.size(); tc++) {
        init(places[tc]);
        getGroup();
        int result = 1;
        for (int i = 0; i < applierVec.size(); i++) {
//            cout << applierVec[i].first.r << "," << applierVec[i].first.c;
//            cout << "와 " << applierVec[i].second.r << "," << applierVec[i].second.c;
            result = BFS(applierVec[i].first, applierVec[i].second);
//            cout << " : " << result << endl;
            if( result == 0 ) break;
            visitedInit();
        }
        answer.push_back(result);
    }

    for( int ans : answer) cout << ans;
    return answer;
}

int main() {
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                              {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                              {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
                                              {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                              {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    solution(places);

    return 0;
}