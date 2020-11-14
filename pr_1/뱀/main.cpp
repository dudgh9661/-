#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};
int arr[100][100] = { 0 };
int body[100][100] = { false };
vector< pair<int, char> > vec;
queue< pair<int, int> > snake;
int N, K;
//L일 경우 방향 변환 함수
int caseL( int currentArrow ) {
    if( currentArrow == 0 ) return 2; //동
    else if( currentArrow == 1 ) return 3; //서
    else if( currentArrow == 3 ) return 0; //남
    else if( currentArrow == 2 ) return 1; //북
}

//R일 경우 방향 변환 함수
int caseR( int currentArrow ) {
    if( currentArrow == 0 ) return 3; //동
    else if( currentArrow == 1 ) return 2; //서
    else if( currentArrow == 3 ) return 1; //남
    else if( currentArrow == 2 ) return 0; //북
}

int moveIdx( int currentArrow ) {
    if( currentArrow == 0 ) return 3; //동
    else if( currentArrow == 1 ) return 1; //서
    else if( currentArrow == 3 ) return 2; //남
    else if( currentArrow == 2 ) return 0; //북
}


//머리 내미는 함수
//int goHeadIdx(int currentArrow) {
//    if( currentArrow == 0 ) return 4; //동
//    else if( currentArrow == 1 ) return 1; //서
//    else if( currentArrow == 3 ) return 2; //남
//    else if( currentArrow == 2 ) return 0; //북
//}

void wallInit(int N) {
    for(int col = 0; col < N; col++) {
        arr[0][col] = -1;
    }
    for(int row = 0; row < N; row++) {
        arr[row][0] = -1;
    }
    for(int row = 0; row < N; row++) {
        arr[row][N-1] = -1;
    }
    for(int col = 0; col < N; col++) {
        arr[N-1][col] = -1;
    }
}

void Print(int N) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", body[row][col]);
        }
        printf("\n");
    }
}

void Printarr(int N) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
}

int vecIdx = 0;
int TIME = 0;

void DFS(int row, int col, int arrow) {

    body[row][col] = true;
    snake.push( {row, col});
    //방향 전환에 대한 로직도 처리해주어야한다.
    int nextArrow;
    int nextRow, nextCol;
    int mvIdx;

//    printf("Time : %d\n", TIME);

    if( TIME == vec[vecIdx].first ) { //시간이 됐을 때, 방향 전환을 한다.

        if( 'D' == vec[vecIdx].second ) { //Right
            nextArrow = caseR(arrow);
            mvIdx = moveIdx(nextArrow);
            nextRow = row + UD[mvIdx];
            nextCol = col + LR[mvIdx];

//            printf("in Right %d, %d idx : %d\n", nextRow, nextCol, mvIdx);
        } else if ( 'L' == vec[vecIdx].second ) { //Left
            nextArrow = caseL(arrow);
            mvIdx = moveIdx(nextArrow);
            nextRow = row + UD[mvIdx];
            nextCol = col + LR[mvIdx];

//            printf("in Left %d, %d idx : %d\n", nextRow, nextCol, mvIdx);
        }

        vecIdx++;

    }
    else {
        nextArrow = arrow;
        //먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        mvIdx = moveIdx(nextArrow);
        nextRow = row + UD[mvIdx];
        nextCol = col + LR[mvIdx];

//        printf("in straight %d, %d idx : %d\n", nextRow, nextCol, mvIdx);
    }

    if( nextRow < 0 || nextRow > N-1 || nextCol < 0 || nextCol > N-1) return;
    TIME++;

    if( body[nextRow][nextCol]  ) { //머리가 몸에 닿은 경우
//        printf("ishere? %d, %d\n", nextRow, nextCol);
        TIME--;
        return;
    }
    //만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
    if( arr[nextRow][nextCol] == 1 ) {
        arr[nextRow][nextCol] = 0;
//        body[nextRow][nextCol] = true;
//        snake.push( { nextRow, nextCol} );
        DFS(nextRow, nextCol, nextArrow);
    }
    //만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
    else if ( arr[nextRow][nextCol] == 0 ) {
//        body[nextRow][nextCol] = true;        printf("사과없는 %d, %d\n", nextRow, nextCol);
        //꼬리가 위치한 곳에 false를 해주어야 한다.
        int tailRow = snake.front().first;
        int tailCol = snake.front().second;
        snake.pop();
        body[tailRow][tailCol] = false;
        DFS(nextRow, nextCol, nextArrow);
    }
}

int main() {
    //게임은 벽 또는 자기자신과 부딪히면 끝난다.
    //보드의 상하좌우 끝에 벽이 있다. 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.



    scanf("%d %d", &N, &K);

//    wallInit(N);

    for(int i = 0; i < K; i++) {
        int inputR, inputC;
        scanf("%d %d", &inputR, &inputC);
//        printf("input : %d %d\n", inputR, inputC);
        arr[inputR-1][inputC-1] = 1; //사과 표시
    }


    int L;
    scanf("%d", &L);
    for(int i = 0; i < L; i++) {
        int input;
        char ch;
        scanf("%d %c", &input, &ch);
        vec.push_back({input,ch});
    }

//    Printarr(N);
    DFS(0, 0, 0);
//    Print(N);
//    Printarr();
//    printf("vec : %c", vec[0].second);
printf("%d", TIME+1);



    return 0;
}
