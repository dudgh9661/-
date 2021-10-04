#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
// output : 크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형의 개수
//1:32
int arr[101][101] = { 0 };
int degree90[4] = {3, 0, 1, 2};
int degree180[4] = {2, 3, 0, 1};

stack<int> st;
queue<int> que;

struct dragonCurv {
    int startR, startC;
    int startArrow;
    int generation;
};

vector<dragonCurv> dragonInfo;


void init() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y,d,g;
        cin>>x>>y>>d>>g;
        dragonInfo.push_back(dragonCurv{y,x,d,g});
    }
}

pair<int,int> move(int arrow, int r, int c) {
    if (arrow == 0) { //right
        arr[r][c] = 1;
        arr[r][c+1] = 1;
        return {r,c+1};
    } else if (arrow == 1) { //up
        arr[r][c] = 1;
        arr[r-1][c] = 1;
        return {r-1,c};
    } else if (arrow == 2) { //left
        arr[r][c] = 1;
        arr[r][c-1] = 1;
        return {r,c-1};
    } else if (arrow == 3) { //down
        arr[r][c] = 1;
        arr[r+1][c] = 1;
        return {r+1,c};
    }
}

void makePos() {
    que = queue<int>();
    stack<int> stTmp = st;

    while (!stTmp.empty()) {
        que.push(degree180[degree90[stTmp.top()]]);
        stTmp.pop();
    }
}

void DFS(int sR, int sC, int generation) {
    if (st.size() == pow(2,generation)) {
        return; // 0g : 2^0, 1g : 2^1, 2g : 2^2
    }

    //1. draw
    pair<int, int> p = {sR,sC};
    makePos();
    while (!que.empty()) {
        int front = que.front();
        p = move(front, p.first, p.second);
        que.pop();
        st.push(front);
    }
    //2. pass start info
    DFS(p.first, p.second, generation);
}
void sol() {
    for (int i = 0; i < dragonInfo.size(); ++i) {
        st = stack<int>(); // Init stack
        pair<int,int> p = move(dragonInfo[i].startArrow, dragonInfo[i].startR, dragonInfo[i].startC);
        st.push(dragonInfo[i].startArrow);
        DFS(p.first, p.second, dragonInfo[i].generation);
    }
}

int getAns() {
    int cnt = 0;

    for(int i = 0; i <= 99; ++i) {
        for (int j = 0; j <= 99; ++j) {
            if (arr[i][j] == 1 & arr[i][j+1] == 1 && arr[i+1][j] == 1 && arr[i+1][j+1] == 1 ) cnt++;
        }
    }
    return cnt;
}

void Print(int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    init();
    sol();
//    Print(9);
    cout << getAns();
    return 0;
}
