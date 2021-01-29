#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int row, col, height;
struct POS {
    int h, r, c;
};
vector<POS> tomato; //익은 토마토
vector<POS> updatingTomato; //익게 될 토마토

int map[100][100][100];
bool visited[100][100][100] = { false };
int UD[4] = {1, -1, 0, 0};
int LR[4] = {0, 0, 1, -1};
int FB[2] = {-1, 1}; //앞,뒤
void init() {
    cin >> col >> row >> height;
    int input;

    for (int h = 0; h < height; h++) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                cin >> input;
                map[h][r][c] = input; //높이, 행, 열
                if (input == 1) tomato.push_back({h, r, c});
            }
        }
    }
}

bool inRange(int h, int r, int c) {
    if (h < 0 || h >= height || r < 0 || r >= row || c < 0 || c >= col) return false;
    return true;
}

void Search() {
    //익은 토마토들을 기준으로, 익게 될 토마토들의 정보를 저장한다.
    for(int all = 0; all < tomato.size(); all++) {
        int ph = tomato[all].h;
        int pr = tomato[all].r;
        int pc = tomato[all].c;

        //4방향
        for (int i = 0; i < 4; i++) {
            int nr = pr + UD[i];
            int nc = pc + LR[i];
            if(visited[ph][nr][nc]) continue;
            if(!inRange(ph, nr, nc) || map[ph][nr][nc] != 0) continue;
            updatingTomato.push_back({ph, nr, nc});
            visited[ph][nr][nc] = true;
        }
        //앞,뒤
        for (int i = 0; i < 2; i++) {
            int nh = ph + FB[i];
            if(visited[nh][pr][pc]) continue;
            if (!inRange(nh, pr, pc) || map[nh][pr][pc] != 0) continue;
            updatingTomato.push_back({nh, pr, pc});
            visited[nh][pr][pc] = true;
        }
    }
}

bool isAllClear() {
    for (int h = 0; h < height; h++) {
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if( map[h][r][c] == 0 ) {
//                    cout << "안익은 토마토 존재!" << endl;
                    return false;
                }
            }
        }
    }
    return true;
}

void update() {
    for(int i = 0; i < updatingTomato.size(); i++) {
        map[updatingTomato[i].h][updatingTomato[i].r][updatingTomato[i].c] = 1;
    }
    tomato.clear();
    tomato.resize(0);
    tomato = updatingTomato; //익게 될 토마토들을 익은 토마토로 저장해준다.

    updatingTomato.clear(); //익게 될 토마토들을 모두 익게 해줬으므로 초기화.
    updatingTomato.resize(0);
}


int main() {
    int day = 0;
    init();
    while(1) {
        Search();
        if( updatingTomato.empty() ) {
//            cout << "더 이상 익을 토마토가 존재하지 않으므로, 모두 다 익었는지 확인" << endl;
            if( !isAllClear() ) day = -1;
//            if( isAllClear() ) cout << "모두 다 익었다" << endl;
//            else cout << "모두 다 익지 못함" << endl;
            break;
        }
        update();
        day++;
    }
    cout << day << endl;
    return 0;
}

