#include <iostream>
#include <cstdio>

using namespace std;

int N;
int answer = 0;
int curR, curC, ARROW = 0;

int arr[500][500];
int visited[500][500] = { 0 };
int leftR[4] = {1,0,-1,0}; //왼,아래,오른,위
int leftC[4] = {0,1,0,-1};
int UD[4] = {-1, 0, 1, 0};
int LR[4] = { 0 ,-1, 0, 1};
int changeArrow[4] = {0,1,2,3}; //왼,아래,오른,위

//***** 범위가 벗어난 a인 경우에도 answer에 추가해줘야함******
void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void init() {
    cin >> N;

    int a;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
          cin >> a;
          arr[i][j] = a;
        }
    }
}
bool goLeft(int r, int c, int arrow) {
    if( visited[r+leftR[arrow]][c+leftC[arrow]] != 0 ) return false;
    return true;
}
bool inRange(int r, int c) {
    if( r < 1 || r > N || c < 1 || c > N ) return false;
    return true;
}
void left(int r, int c) {
        int nr, nc;
        int sum = 0;
        //2%
        nr = r-2; nc = c;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 2 / 100;
            sum += arr[r][c] * 2 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 2 / 100;
            sum += arr[r][c] * 2 / 100;
        }

        nr = r+2;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 2 / 100;
            sum += arr[r][c] * 2 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 2 / 100;
            sum += arr[r][c] * 2 / 100;
        }

        //7%
        nr= r-1; nc = c;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 7 / 100;
            sum += arr[r][c] * 7 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 7 / 100;
            sum += arr[r][c] * 7 / 100;
        }

        nr= r+1; nc = c;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 7 / 100;
            sum += arr[r][c] * 7 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 7 / 100;
            sum += arr[r][c] * 7 / 100;
        }

        //10%
        nr= r-1; nc = c-1;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 10 / 100;
            sum += arr[r][c] * 10 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 10 / 100;
            sum += arr[r][c] * 10 / 100;
        }

        nr= r+1; nc = c-1;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 10 / 100;
            sum += arr[r][c] * 10 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 10 / 100;
            sum += arr[r][c] * 10 / 100;
        }

        //5%
        nr= r; nc = c-2;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 5 / 100;
            sum += arr[r][c] * 5 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 5 / 100;
            sum += arr[r][c] * 5 / 100;
        }

        //1%
        nr= r-1; nc = c+1;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 1 / 100;
            sum += arr[r][c] * 1 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 1 / 100;
            sum += arr[r][c] * 1 / 100;
        }
        nr= r+1; nc = c+1;
        if( !inRange(nr,nc) ) {
            answer += arr[r][c] * 1 / 100;
            sum += arr[r][c] * 1 / 100;
        } else {
            arr[nr][nc] += arr[r][c] * 1 / 100;
            sum += arr[r][c] * 1 / 100;
        }

    //'a'
    nr = r; nc = c-1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] - sum;
    } else {
        arr[nr][nc] += arr[r][c] - sum;
    }

//    printf("in left, answer : %d\n", answer);
}
void down(int r, int c) {
    int nr, nc;
    int sum = 0;

    //2%
    nr = r;
    nc = c - 2;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    }

    nr = r;
    nc = c + 2;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    }

    //7%
    nr = r;
    nc = c - 1;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    }

    nr = r;
    nc = c + 1;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    }

    //10%
    nr = r + 1;
    nc = c - 1;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    }

    nr = r + 1;
    nc = c + 1;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    }

    //5%
    nr = r + 2;
    nc = c;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 5 / 100;
        sum += arr[r][c] * 5 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 5 / 100;
        sum += arr[r][c] * 5 / 100;
    }

    //1%
    nr = r - 1;
    nc = c - 1;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    }
    nr = r - 1;
    nc = c + 1;
    if (!inRange(nr, nc)) {
        answer += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 0.01;
        sum += arr[r][c] * 0.01;
    }

    //'a'
    nr = r+1; nc = c;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] - sum;
    } else {
        arr[nr][nc] += arr[r][c] - sum;
    }

//    printf("in down, answer : %d\n", answer);
}
void right(int r, int c) {
    int nr, nc;
    int sum = 0;

    //2%
    nr = r-2; nc = c;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    }

    nr = r+2;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    }

    //7%
    nr= r-1; nc = c;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    }

    nr= r+1; nc = c;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    }

    //10%
    nr= r-1; nc = c+1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    }

    nr= r+1; nc = c+1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    }

    //5%
    nr= r; nc = c+2;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 5 / 100;
        sum += arr[r][c] * 5 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 5 / 100;
        sum += arr[r][c] * 5 / 100;
    }

    //1%
    nr= r-1; nc = c-1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    }
    nr= r+1; nc = c-1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    }

    //'a'
    nr = r; nc = c+1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] - sum;
    } else {
        arr[nr][nc] += arr[r][c] - sum;
    }

//    printf("in right, answer : %d\n", answer);
}
void up(int r, int c) {
    int nr, nc;
    int sum = 0;
    //2%
    nr = r; nc = c-2;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    }

    nr = r; nc = c+2;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 2 / 100;
        sum += arr[r][c] * 2 / 100;
    }

    //7%
    nr= r; nc = c-1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    }

    nr= r; nc = c+1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 7 / 100;
        sum += arr[r][c] * 7 / 100;
    }

    //10%
    nr= r-1; nc = c-1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    }

    nr= r-1; nc = c+1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 10 / 100;
        sum += arr[r][c] * 10 / 100;
    }

    //5%
    nr= r-2; nc = c;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 5 / 100;
        sum += arr[r][c] * 5 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 5 / 100;
        sum += arr[r][c] * 5 / 100;
    }

    //1%
    nr= r+1; nc = c-1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    }

    nr= r+1; nc = c+1;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    } else {
        arr[nr][nc] += arr[r][c] * 1 / 100;
        sum += arr[r][c] * 1 / 100;
    }

    //'a'
    nr = r-1; nc = c;
    if( !inRange(nr,nc) ) {
        answer += arr[r][c] - sum;
    } else {
        arr[nr][nc] += arr[r][c] - sum;
    }

//    printf("in up, answer : %d\n", answer);
}
void spread(int r, int c, int arrow) {
    if( arrow == 0 ) left(r,c);
    else if (arrow == 1 ) down(r,c);
    else if (arrow == 2 ) right(r,c);
    else if (arrow == 3 ) up(r,c);
}
void move(int r,int c, int arrow) {
    if( arrow == 0 ) curC -= 1;
    else if (arrow == 1 ) curR += 1;

    else if (arrow == 2 ) curC += 1;
    else if (arrow == 3 ) curR -= 1;
}
void sol() {
    if( N % 2 != 0 ) { //홀수
        curR = N / 2 + 1;
        curC = N / 2 + 1;
    } else {
        curR = N / 2;
        curC = N / 2;
    }
    //초기셋팅
    int cnt = 1;
    visited[curR][curC] = cnt++;
//    printf("처음 좌표 (%d, %d), %d\n", curR, curC, ARROW);

    while(true) {
        //1. 토네이도 이동
        move(curR,curC,ARROW);
        if( curR < 1 || curC < 1 ) break;
        visited[curR][curC] = cnt++;
        //2. 그 위치에서 spread
        spread(curR,curC,ARROW);
//        printf("(%d,%d)에서 %d 방향으로 토네이도가 일어남\n", curR, curC, ARROW);
        arr[curR][curC] = 0;
//        Print();
        //3. 방향 전환
        if(goLeft(curR,curC,ARROW)) { //방향 전환이 가능하면, 방향을 바꾼다.
            ARROW = changeArrow[(ARROW+1)%4];
        }

    }
}
int main() {
    init();
    sol();
//    cout << 10*0.02 << endl;
    cout << answer << endl;
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            cout << visited[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
