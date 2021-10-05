// 21 : 41 시작 , 20 : 54 종료, 총 1시간 13분 소요
#include <iostream>
#include <queue>

using namespace std;
// 4개 이상 상하좌우 연결 -> 연결된 같은색 뿌요들 한번에 없어짐 -> 1연쇄 시작
// 없어진 이후, 위에 다른 뿌요들이 있다면, 중력의 영향을 받아 차례대로 떨어짐 -> 떨어졌을때 4개이상 연결되면 터짐 -> 1연쇄 추가
// ** 터질 수 있는 뿌요가 여러 그룹이면, "동시에  터진다" -> 여러 그룹이더라도 "1연쇄 추가!"

char arr[12][6];
int LR[4] = {-1,0,1,0};
int UD[4] = { 0,-1,0,1};
bool visited[12][6] = { false };

int ans = 0;
bool findFlag;

void init() {
    for(int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; ++j) {
            cin >> arr[i][j];
        }
    }
}

void visitedInit() {
    for(int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; ++j) {
            visited[i][j] = false;
        }
    }
}

bool inRange(int r, int c) {
    if ( r < 0 || r >= 12 || c < 0 || c >= 6) return false;
    return true;
}

void findPuyo(int r, int c) {
    queue<pair<int,int>> que;
    que.push({r,c});
    visited[r][c] = true;

    char target = arr[r][c];
    int findCnt = 1;
    while (!que.empty()) {
        int cR = que.front().first;
        int cC = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nr = cR + UD[i];
            int nc = cC + LR[i];

            if (visited[nr][nc]) continue;
            if (!inRange(nr,nc)) continue;
            if (arr[nr][nc] != target) continue;

            findCnt++;
            visited[nr][nc] = true;
            que.push({nr,nc});
        }
    }
    if (findCnt >= 4) {
        findFlag = true;
        return;
    }
    else {
        visitedInit();
        return;
    }
}

void Boom() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (visited[i][j]) {
                arr[i][j] = '.';
            }
        }
    }
}

void downPuyo() {
    for(int c = 0; c < 6; c++){
        queue<char> que;
        int noneIdx = -1;
        bool findNone = false;

        for(int r = 11; r >= 0; r--) {
            if (arr[r][c] == '.' && !findNone) { // .이고, 그것이 처음 발견된 것이라면
                noneIdx = r;
                findNone = true;
            } else if (findNone && arr[r][c] != '.') {
                que.push(arr[r][c]);
                arr[r][c] = '.';
            }
        }

        if (noneIdx == -1) continue; // if all puyo, pass
        //down puyo
        while (!que.empty()) {
            char puyo = que.front();
            que.pop();
            arr[noneIdx--][c] = puyo;
        }
    }
}

void Print() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
void sol() {
    while (true) {
        findFlag = false;
        visitedInit();

//        cout << "<<Before>>" << endl;
//        Print();
        // 1. 4개 연결된 곳을 찾는다.
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (arr[i][j] == '.') continue;
                findPuyo(i, j);
                Boom();
            }
        }
        if (!findFlag) break;

        // 2. 연결된 곳을 한번에 터뜨린다.
//        cout << "<<After>>" << endl;
//        Print();

        // 3. 1연쇄를 더해준다.
        ans++;

        // 4. 뿌요가 내려온다.
        downPuyo();
//        cout << "<<Down>>" << endl;
//        Print();
        // 5. 1번을 실행해 연결된 곳이 없으면, 종료한다.
    }
}
int main() {
//    freopen("input.txt","r",stdin);
    init();
    sol();
    cout << ans;
    return 0;
}
