#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
1. 공기를 퍼뜨려, 맡닿는 부분들을 기록
2. 녹인다.
3. 반
*/

int r, c = 0;
int startR, startC = 0;
int lastCnt = 0;
int answer = 0;

vector<pair<int,int>> vec;
bool visited[100][100] = { false };
int arr[100][100] = { 0 };
int LR[4] = { 1,-1,0,0};
int UD[4] = { 0,0,-1,1};

void init() {
    cin >> r >> c;
    int a;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a;
            arr[i][j] = a;
        }
    }
}

void Print() {
    for(int i = 0; i < r; i++) {
        for(int j = 0 ; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int melting() {
    for(int i = 0; i < vec.size(); i++) {
        arr[vec[i].first][vec[i].second] = 0;
    }
    return vec.size();
}

void initAll() {
    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) visited[i][j] = false;
    }
    vec.clear();
    vec.resize(0);
}

bool isPossible(int row, int col) {
    if( row >= r || row < 0 || col >= c || col < 0 ) return false;
    return true;
}

void BFS() {
    queue< pair<int,int> > que;
    que.push({startR,startC});
    visited[startR][startC] = true;

    while( !que.empty() ) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];

            if( !isPossible(nr,nc) ) continue;
            //방문했으면 패스
            if( visited[nr][nc] ) continue;
            //방문한 곳이 치즈라면, 해당 좌표 저장하고 패스
            if( arr[nr][nc] == 1 ) {
                vec.push_back({nr,nc});
                visited[nr][nc] = true;
                continue;
            }
            //방문한 곳이 공기라면, 방문 표시 후 큐에 푸시
            if( arr[nr][nc] == 0 ) {
                que.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
}

void findStart() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if( arr[i][j] == 0 ) {
                startR = i;
                startC = j;
                return;
            }
        }
    }
}

int main() {
    init();

    while(1) {
        findStart();
        BFS();
        int tmp = melting();

        if( tmp == 0 ) break;
        else lastCnt = tmp;

        answer++;
//        Print();
        initAll();
    }
    cout << answer << endl;
    cout << lastCnt << endl;
    return 0;
}
