#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101] = { 0 };
int T[101][101] = { 0 };
int row = 0, col = 0;

vector<pair<int,int>> store;
pair<int,int> dong;
pair<int,int> pos;

void init() {
    cin >> col >> row;
    int a;
    cin >> a;
    int pos, dis;
    for(int i = 0; i < a; i++) {
        cin >> pos >> dis;
        if ( pos == 1 ) {
            arr[0][dis] = 1;
            store.push_back({0,dis});
        } else if ( pos == 2) {
            arr[row][dis] = 1;
            store.push_back({row,dis});
        } else if ( pos == 3 ) {
            arr[dis][0] = 1;
            store.push_back({dis, 0});
        } else if ( pos == 4 ) {
            arr[dis][col] = 1;
            store.push_back({dis,col});
        }
    }
    cin >> pos >> dis;
    dong = make_pair(pos,dis);

    for( pair<int,int> p : store ) {
        T[p.first][p.second] = 1e9;
    }
}

pair<int,int> getInitPos() {
    int pos = dong.first;
    int cur = dong.second;

    if ( pos == 1 ) {
        arr[0][cur] = 100;
        return {0,cur};
    } else if ( pos == 2) {
        arr[row][cur] = 100;
        return {row,cur};
    } else if ( pos == 3 ) {
        arr[cur][0] = 100;
        return {cur, 0};
    } else if ( pos == 4 ) {
        arr[cur][col] = 100;
        return {cur,col};
    }
}

bool isStore(int r, int c, int t) {
    for(pair<int,int> p : store) {
        if ( r == p.first && c == p.second ) {
//            cout << r << " , " << c << " : " << t << endl;
            T[r][c] = min(t, T[r][c]);
            return true;
        }
    }
    return false;
}

void arrowClock() {
    pos = getInitPos();
    int arrow = dong.first;
    int curR = pos.first;
    int curC = pos.second;
    int t = 0;
    int findCnt = 0;

    while ( findCnt != store.size() ) {
        if ( isStore(curR, curC, t) ) findCnt++;

        if (curR == row && curC == 0 ) {
            arrow = 3;
        } else if (curR == 0 && curC == 0) {
            arrow = 1;
        } else if (curR == 0 && curC == col) {
            arrow = 4;
        } else if (curR == row && curC == col) {
            arrow = 2;
        }

        if ( arrow == 1 ) {
            curC++;
            t++;
        } else if (arrow == 2) {
            curC--;
            t++;
        } else if (arrow == 3) {
            curR--;
            t++;
        } else if (arrow == 4) {
            curR++;
            t++;
        }
    }
}

void unArrowClock() {
    int arrow = dong.first;
    int curR = pos.first;
    int curC = pos.second;
    int t = 0;
    int findCnt = 0;

    while ( findCnt != store.size() ) {
        if ( isStore(curR, curC, t) ) findCnt++;

        if (curR == row && curC == 0 ) {
            arrow = 2;
        } else if (curR == 0 && curC == 0) {
            arrow = 3;
        } else if (curR == 0 && curC == col) {
            arrow = 1;
        } else if (curR == row && curC == col) {
            arrow = 4;
        }

        if ( arrow == 1 ) {
            curC--;
            t++;
        } else if (arrow == 2) {
            curC++;
            t++;
        } else if (arrow == 3) {
            curR++;
            t++;
        } else if (arrow == 4) {
            curR--;
            t++;
        }
    }
}

int main() {
    init();
    arrowClock();
    unArrowClock();

    int sum = 0;
    for(auto p : store) {
        sum += T[p.first][p.second];
    }
    cout << sum << endl;
    return 0;
}
