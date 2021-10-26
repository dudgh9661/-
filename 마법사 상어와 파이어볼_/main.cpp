#include <iostream>
#include <vector>

using namespace std;

struct fireball {
    int m,d,s; //질량,방향,속도
};

vector<int> dir[8] = {{-1,0}, {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int N, M, K;

vector<fireball> tmpMap[51][51];
vector<fireball> originMap[51][51];

// 범위 밖으로 벗어날 경우 -> 1행 <-> N번 행, 1열 <-> N번
pair<int,int> inRange(int nr, int nc) {
//    int resR = nr % N;
//    if (resR < 0) resR += N;
//
//    int resC = nc % N;
//    if (resC < 0) resC += N;
    int resR = nr, resC = nc;

    if (nr == 0) resR = N;
    else if ( nr < 0) {
        if (abs(nr) % N == 0) resR = N;
        else resR = N - abs(nr) % N;
    } else if (nr > N) {
        if (nr % N == 0) resR = N;
        else resR = nr % N;
    }

    if (nc == 0) resC = N;
    else if ( nc < 0) {
        if (abs(nc) % N == 0) resC = N;
        else resC = N - abs(nc) % N;
    } else if (nc > N) {
        if (nc % N == 0) resC = N;
        else resC = nc % N;
    }

    return {resR,resC};
}

void init() {
    cin >> N >> M >> K;
    int r,c,m,d,s;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        originMap[r][c].push_back({m,d,s});
    }
}

void move() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            vector<fireball> tmp = originMap[i][j];
            if (tmp.empty()) continue;
            for (auto ball : tmp) {
                int nr = i + dir[ball.d][0] * ball.s;
                int nc = j + dir[ball.d][1] * ball.s;
                auto p = inRange(nr,nc);
                nr = p.first;
                nc = p.second;
                tmpMap[nr][nc].push_back(ball);
            }
        }
    }
}

void doSpread(int r, int c, int m, int s, bool isAllCondition) {
    if (isAllCondition) {
        for (int i = 0; i <= 6; i += 2) {
            tmpMap[r][c].push_back({m, i, s}); // 질량, 방향, 속도
        }
    } else {
        for (int i = 1; i <= 7; i += 2) {
            tmpMap[r][c].push_back({m, i, s}); // 질량, 방향, 속도
        }
    }
}
void spread() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (tmpMap[i][j].size() >= 2) {
                int sumM = 0;
                int sumS = 0;
                bool isAllOdd = true;
                bool isAllEven = true;
                for (auto ball : tmpMap[i][j]) {
                    sumM += ball.m;
                    sumS += ball.s;
                    if (ball.d % 2 != 0) isAllEven = false;
                    else if (ball.d % 2 == 0) isAllOdd = false;
                }
                sumM /= 5; sumS /= (int)tmpMap[i][j].size();
                tmpMap[i][j].clear(); // 해당 좌표의 파이어볼 초기화
                if (sumM <= 0) continue;
                // 4개의 파이어볼로 나누기
                if (isAllOdd || isAllEven) {
                    doSpread(i,j,sumM,sumS, true);
                } else {
                    doSpread(i,j,sumM,sumS, false);
                }
            }
        }
    }
}

void setInit() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            originMap[i][j] = tmpMap[i][j];
            tmpMap[i][j].clear();
            tmpMap[i][j].resize(0);
        }
    }
}

void getAns() {
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (originMap[i][j].empty()) continue;
            for (auto ball : originMap[i][j]) {
                sum += ball.m;
            }
        }
    }
    cout << sum << endl;
}
int main() {
    init();
    for (int i = 0; i < K; i++) {
        // 1. move
        move();
        // 2. spread
        spread();
        setInit();
        // 3. spread 이후, 2개 이상이 된 곳 유무 검사
    }
    getAns();

    return 0;
}
