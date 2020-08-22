#include <iostream>
#include <stdio.h>

using namespace std;

int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};

int arr[50][50] = { 0 };
bool clean[50][50] = { false };

int N, M;
int ans = 0;

int Stare(int arrow) {
    if( arrow == 0 ) return 3;
    else if ( arrow == 1 ) return 0;
    else if ( arrow == 2 ) return 1;
    else if ( arrow == 3 ) return 2;
}

int Arrow(int arrow) {
    if( arrow == 0 ) return 1;
    else if ( arrow == 1 ) return 0;
    else if ( arrow == 2 ) return 3;
    else if ( arrow == 3 ) return 2;
}

int backArrow(int arrow) {
    if( arrow == 0 ) return 2;
    else if ( arrow == 1 ) return 1;
    else if ( arrow == 2 ) return 0;
    else if ( arrow == 3 ) return 3;
}

void DFS(int r, int c, int arrow, int cnt) {
    //1. 현재 위치를 청소한다.
    clean[r][c] = true;

    //2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
    int nextArrow = Stare(arrow);

    int nextArrowIdx = Arrow(arrow);
    int nextR = r + UD[nextArrowIdx];
    int nextC = c + LR[nextArrowIdx];
    //왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
    if( !clean[nextR][nextC] && arr[nextR][nextC] == 0 ) {
        cnt = 0;
        ans++;
        DFS( nextR, nextC, nextArrow, cnt);
    }
    //왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    else if ( clean[nextR][nextC] || arr[nextR][nextC] == 1) {
        cnt++;
        //네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
        if ( cnt == 4 ) {
            nextArrow = Stare(arrow);
            nextArrowIdx = backArrow(nextArrow);
            nextR = r + UD[nextArrowIdx];
            nextC = c + LR[nextArrowIdx];

            if( arr[nextR][nextC] != 1 ) {
                cnt = 0;
                DFS(nextR, nextC, nextArrow, cnt);
            } else if ( arr[nextR][nextC] == 1 ) {
//                arrow = Stare(arrow);

                return;
            }
        }
        else DFS(r, c, nextArrow, cnt);
    }

    //네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
}

int main() {
    scanf("%d %d", &N, &M);

    int r,c, arrow;
    scanf("%d %d %d", &r, &c, &arrow);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int input = 0;
            scanf("%d", &input);
            arr[i][j] = input;
        }
    }

    DFS(r,c,arrow, 0);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", clean[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", ans+1);
    return 0;
}