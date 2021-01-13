#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, r, c, comm;

vector<int> vec; //명령어
vector<vector<int>> map;
vector<int> dice(7,0); //idx 0은 무
vector<int> diceTmp(7,0);

void PrintDice() {
    for(int i = 1; i <= 6; i++) {
        cout << dice[i] << " ";
    }
}
bool isRange(int r, int c) {
    if( r < 0 || r >= N || c < 0 || c >= M ) return false;
    return true;
}
void init() {
    cin >> N >> M >> r >> c >> comm;

    int a;
    for(int i = 0; i < N; i++) {
        vector<int> tmp;
        for(int j = 0; j < M; j++) {
            cin >> a;
            tmp.push_back(a);
        }
        map.push_back(tmp);
        tmp.clear();
    }

    for(int i = 0; i < comm; i++) {
        cin >> a;
        vec.push_back(a);
    }
}
void East() {
    c = c + 1;
    if( !isRange(r,c) ) {
        c = c-1;
        return;
    }

    diceTmp[1] = dice[4];
    diceTmp[2] = dice[2];
    diceTmp[3] = dice[1];
    diceTmp[4] = dice[6];
    diceTmp[5] = dice[5];
    diceTmp[6] = dice[3];
    for(int i = 1; i <= 6; i++) {
        dice[i] = diceTmp[i];
    }

    if( map[r][c] == 0 ) {
        map[r][c] = dice[6];
    } else if( map[r][c] != 0 ) {
        dice[6] = map[r][c]; //칸 -> 주사위 바닥면
        map[r][c] = 0;
    }
//    PrintDice();
    cout << dice[1] << "\n";
}

void West() {
    c = c - 1;
    if( !isRange(r,c) ) {
        c= c + 1;
        return;
    }

    diceTmp[1] = dice[3];
    diceTmp[2] = dice[2];
    diceTmp[3] = dice[6];
    diceTmp[4] = dice[1];
    diceTmp[5] = dice[5];
    diceTmp[6] = dice[4];
    for(int i = 1; i <= 6; i++) {
        dice[i] = diceTmp[i];
    }

    if( map[r][c] == 0 ) {
        map[r][c] = dice[6];
    } else if( map[r][c] != 0 ) {
        dice[6] = map[r][c]; //칸 -> 주사위 바닥면
        map[r][c] = 0;
    }
//    PrintDice();
    cout << dice[1] << "\n";
}

void South() {
    r = r + 1;
    if( !isRange(r,c) ) {
        r = r - 1;
        return;
    }

    diceTmp[1] = dice[2];
    diceTmp[2] = dice[6];
    diceTmp[3] = dice[3];
    diceTmp[4] = dice[4];
    diceTmp[5] = dice[1];
    diceTmp[6] = dice[5];
    for(int i = 1; i <= 6; i++) {
        dice[i] = diceTmp[i];
    }

    if( map[r][c] == 0 ) {
        map[r][c] = dice[6];
    } else if( map[r][c] != 0 ) {
        dice[6] = map[r][c]; //칸 -> 주사위 바닥면
        map[r][c] = 0;
    }
//    PrintDice();
    cout << dice[1] << "\n";
}

void North() {
    r = r - 1;
    if( !isRange(r,c) ) {
        r = r + 1;
        return;
    }

    diceTmp[1] = dice[5];
    diceTmp[2] = dice[1];
    diceTmp[3] = dice[3];
    diceTmp[4] = dice[4];
    diceTmp[5] = dice[6];
    diceTmp[6] = dice[2];
    for(int i = 1; i <= 6; i++) {
        dice[i] = diceTmp[i];
    }

    if( map[r][c] == 0 ) {
        map[r][c] = dice[6];
    } else if( map[r][c] != 0 ) {
        dice[6] = map[r][c]; //칸 -> 주사위 바닥면
        map[r][c] = 0;
    }
//    PrintDice();
    cout << dice[1] << "\n";
}

void sol() {
    for(int i = 0; i < vec.size(); i++) {
        switch(vec[i]) {
            case 1:
//                printf("East 이동 : %d\n", vec[i]);
                East();
                break;
            case 2:
//                printf("West 이동 : %d\n", vec[i]);
                West();
                break;
            case 3:
//                printf("North 이동 : %d\n", vec[i]);
                North();
                break;
            case 4:
//                printf("South 이동 : %d\n", vec[i]);
                South();
                break;
        }
    }
}
int main() {
    init();
    sol();
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            cout << map[i][j] << " ";
//        }
//        cout << "\n";
//    }
    return 0;
}
