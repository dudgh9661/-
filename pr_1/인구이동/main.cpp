#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int N, L, R;
int marking = 1;
int flag = 0;
int ans = 0;
int sum = 0;
int cntOfUni = 0;

int arr[51][51] = {0};
int visited[51][51] = { 0 };
int tmp[2501] = { 0,};

int LR[4] = { -1, 0, 1, 0};
int UD[4] = { 0, -1, 0, 1};


void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}
void init() {
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int input;
            cin >> input;
            arr[i][j] = input;
        }
    }
}
void initVisited() {
    for(int i = 0; i < N; i++) {
        tmp[i] = 0;
        for(int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}
//DFS를 통해서, 단지 번호를 붙힌다. 같은 단지에 속해있는 맵을 만들어, 값 갱신, 반복
void DFS(int row, int col) {
    visited[row][col] = marking;
    sum += arr[row][col];
    cntOfUni++;

    for(int i = 0; i < 4; i++) {
        int nr = row + UD[i];
        int nc = col + LR[i];
        if( nc < 0 || nc >= N || nr < 0 || nr >= N ) continue;


        int val = abs(arr[row][col] - arr[nr][nc]);

        if( val < L || val > R ) continue;
        else if( visited[nr][nc] == 0 ) { //방문하지 않은 값이라면
            DFS(nr,nc);

        }
    }
}

void updateValue() {
    // 연합의 인구수를 갱신한다.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            arr[i][j] = tmp[visited[i][j]];
        }
    }
}

void unionCountry() {
    int value = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if( visited[i][j] == 0 ) {
                DFS(i, j);
                if( cntOfUni == 0 ) value = sum;
                else value = sum / cntOfUni;

                tmp[marking] = value;
                sum = 0;
                cntOfUni = 0;
                marking++;
            }
        }
    }

//    cout << endl;
    if( marking-1 == N*N) {
        flag = 1;
        return;
    }


    updateValue();
    marking = 1;
    ans++;
    initVisited();
}

int main() {
    init();

    while( true ) {
        unionCountry();
        if ( flag == 1 ) break;
    }
    cout << ans << endl;

    return 0;
}


