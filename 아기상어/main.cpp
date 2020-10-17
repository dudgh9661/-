#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0;
int Time = 0;
int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};
int flag = 1;

typedef struct shark{
    int size = 2;
    int row = 0;
    int col = 0;
    int eat = 0;
}Shark;

typedef struct fish{
    int row = 0;
    int col = 0;
    int dis = 0;
}Fish;

Shark shark;
vector<Fish> FISH;
vector< vector<int> > vec;
vector< vector<int> > visit;

void PrintFish() {
    for(int i = 0; i < FISH.size(); i++) {
        cout << FISH[i].row << " , " << FISH[i].col << " : " << FISH[i].dis << endl;
    }
}
void allInit() {
    FISH.clear();
    FISH.resize(0);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visit[i][j] = 0;
        }
    };
}
void eatFish() {
    vec[shark.row][shark.col] = 0;
//    cout << "원래 상어 위치 : " << shark.row << "," << shark.col << endl;
    int targetR = FISH[0].row;
    int targetC = FISH[0].col;

    shark.row = targetR;
    shark.col = targetC;
    shark.eat++;
    if( shark.eat == shark.size ) {
        shark.size++;
        shark.eat = 0;
    }
    Time += FISH[0].dis;
    vec[shark.row][shark.col] = 9;
//    cout << "이후 상어 위치 : " << shark.row << "," << shark.col << endl;

    allInit();

}
bool cmp(Fish f1, Fish f2) {
    if( f1.dis == f2.dis ) {
        if( f1.row == f2.row ) {
            return f1.col < f2.col;
        }
        return f1.row < f2.row;
    }
    return f1.dis < f2.dis;
}
void PrintVec() {
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << vec[i][j];
        }
        cout << endl;
    }
}
void PrintVisit() {
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << visit[i][j];
        }
        cout << endl;
    }
}
void init() {
    vector<int> tmp;
    vector<int> tmp2(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input = 0;
            cin >> input;
            if ( input == 9 ) {
                shark.row = i;
                shark.col = j;
            }
            tmp.push_back(input);
        }
        vec.push_back(tmp);
        tmp.clear();
        visit.push_back(tmp2);
    }

}
void BFS() { //상어가 먹을 수 있는 물고기들의 위치와 거리정보를 저장한다.
    queue< pair<int,int> > que;
    que.push({shark.row, shark.col});
    visit[shark.row][shark.col] = 0;

    while( !que.empty()) {
        int row = que.front().first;
        int col = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nextR = row + UD[i];
            int nextC = col + LR[i];

            if( nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) continue;

            if( vec[nextR][nextC] <= shark.size && visit[nextR][nextC] == 0 && vec[nextR][nextC] != 9 ) {
                if ( vec[nextR][nextC] < shark.size && vec[nextR][nextC] != 0 ) {
                    int dis = visit[row][col] + 1;
                    visit[nextR][nextC] = visit[row][col] + 1; // +1을 하면 초기값이 1이였던 점을 감
                    Fish fish;
                    fish.row = nextR;
                    fish.col = nextC;
                    fish.dis = dis;
                    FISH.push_back(fish);

                    que.push({nextR, nextC});
                    continue;
                }
                visit[nextR][nextC] = visit[row][col] + 1;
                que.push({nextR, nextC});
            }
        }
    }
    que = queue< pair<int,int> >();

    if( FISH.empty()) flag = 0;
    sort(FISH.begin(), FISH.end(), cmp);
    if ( flag == 0 ) {
//        cout << Time << endl;
        return;
//        cout << " 더 이상 먹을 물고기가 없다 " << endl;
//        cout << " time : " << Time << endl;

    }
    else eatFish();
}

int main() {
    cin >> N;
    init();
    int cycle = 1;
    while(flag == 1) {
        BFS();
//        cout << Time << endl;
//        cout << "cycle : " << cycle++ << " time : " << Time << " shark size : " << shark.size << " shark eat :  " << shark.eat << endl;
//        cout << " << map >> " << endl;
//        PrintVec();
//        cout << " << Visit >> " << endl;
//        PrintVisit();
//        cout << endl;

    }
    cout << Time << endl;
    return 0;
}
