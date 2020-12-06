#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * 제약 조건
 * 1. 말은 지금까지 지나온 알파벳과 다른 알파벳으로만 이동할 수 있다.
 * 2. 말이 지나는 칸은 좌측 상단의 칸도 포함
 * 3. 상하좌우로 인접한 네 칸 중의 한 칸
 *
 * 방문 표시를 안지워도 되나? 어차피 못가는 곳이니깐..?
 *
 * 출력 : 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성
 */

int R, C; //R C열

bool alpha[25] = { false };
char map[21][21] = { 0 };

int UD[4] = { -1,0,1,0};
int LR[4] = {0,1,0,-1};

int MAX = -100;

void init() {
    cin >> R >> C;
    char input;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> input;
            map[i][j] = input;
        }
    }

    //init first horse position
    alpha[map[0][0] - 'A'] = true;
}

bool inRange(int row, int col) {
    return row >= 0 && col >= 0 && row < R && col < C;
}
void DFS(int row, int col, int cnt) {
    if (MAX < cnt) {
        MAX = max(MAX, cnt);
    }

    for(int i = 0; i < 4; i++) {
        int nr = row + UD[i];
        int nc = col + LR[i];
        int nextAlphaIdx = map[nr][nc] - 'A';

        if( inRange(nr, nc) && !alpha[nextAlphaIdx] ) {
            alpha[nextAlphaIdx] = true;
            DFS(nr, nc, cnt + 1);
            alpha[nextAlphaIdx] = false;
        }
//        else if ( !inRange(nr, nc) ) {
//            cout << " fail out of range : " << nr << "," << nc << endl;
//        } else if ( alpha[nextAlphaIdx]) {
//            cout << " fail already visited : " << nr << "," << nc << endl;
//        }
//        else {
//            cout << " fail : " << nr << "," << nc << endl;
//        }
    }
}
int main() {
    init();
    DFS(0,0,1);
    cout << MAX << endl;
    return 0;
}
