#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

struct FIRE {
    int r,c,m,s,d;
};
vector<pair<int,int>> dir = {{-1,0}, {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
vector<FIRE> arr[50][50];
vector<FIRE> fireVec;

int N, M, K;

void init() {
    cin >> N >> M >> K;
    int r,c,m,s,d;
    for (int i = 0; i < M; ++i) {
        cin >>r>>c>>m>>s>>d;
        fireVec.push_back({r-1,c-1,m,s,d});
    }
}

void move() {
    for(int i = 0; i < fireVec.size(); i++) {
        int r = fireVec[i].r;
        int c = fireVec[i].c;
        int m = fireVec[i].m;
        int s = fireVec[i].s;
        int d = fireVec[i].d;

        int nr = (r + (dir[d].first * s)) % N;
        if (nr < 0) nr += N;

        int nc = (c + (dir[d].second * s)) % N;
        if (nc < 0) nc += N;

        fireVec[i].r = nr;
        fireVec[i].c = nc;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arr[i][j].clear();
        }
    }

    for(int i = 0; i < fireVec.size(); i++) {
        arr[fireVec[i].r][fireVec[i].c].push_back(fireVec[i]);
    }
}

void nextMove() {

    fireVec.clear();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j].size() == 1) fireVec.push_back(arr[i][j][0]);
            else if (arr[i][j].size() >= 2){
                int _m = 0; // 질량
                int _s = 0; // 속력

                bool isEven = true;
                bool isOdd = true;

                for(FIRE fire : arr[i][j]) {
                    _m += fire.m;
                    _s += fire.s;
                    if (fire.d % 2 == 0) isOdd = false;
                    else isEven = false;
                }
                _m = _m / 5;
                _s = _s / (int)arr[i][j].size();

                if (_m == 0) continue;

                if (isEven || isOdd) {
                    fireVec.push_back({i, j, _m, _s, 0});
                    fireVec.push_back({i, j, _m, _s, 2});
                    fireVec.push_back({i, j, _m, _s, 4});
                    fireVec.push_back({i, j, _m, _s, 6});
                } else {
                    fireVec.push_back({i, j, _m, _s, 1});
                    fireVec.push_back({i, j, _m, _s, 3});
                    fireVec.push_back({i, j, _m, _s, 5});
                    fireVec.push_back({i, j, _m, _s, 7});
                }
            }
        }
    }
}

int getSum() {
    int ans = 0;
    for (FIRE f : fireVec) {
        ans += f.m;
    }
    return ans;
}

int main() {
    init();
    for(int i = 0; i < K; i++) {
        move();
        nextMove();
    }

    cout << getSum();
    return 0;
}
