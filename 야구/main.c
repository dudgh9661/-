#include <stdio.h>
#include <stdbool.h>

int arr[50][9] = { 0 };
int ground[3] = { 0 };

int score = 0;
int out = 0;
int MAX = 0;
int turn[9] = { 0 };
bool visit[9] = { false };

void Print() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void PrintTurn() {
        for(int j = 0; j < 9; j++) {
            printf("%d ", turn[j]);
        }
        printf("\n");
}

void hit(int result) {
    if (result == 1) {
        if( ground[2] == 1 ) {
            score++;
            ground[2] = 0;
        }
        if ( ground[1] == 1) {
            ground[2] = ground[1];
            ground[1] = 0;
        }
        if ( ground[0] == 1 ) {
            ground[1] = ground[0];
            ground[0] = 0;
        }
        ground[0] = 1;
    } else if ( result == 2) {
        if( ground[2] == 1 ) {
            score++;
            ground[2] = 0;
        }
        if ( ground[1] == 1) {
            score++;
            ground[1] = 0;
        }
        if( ground[0] == 1 ) {
            ground[2] = ground[0];
            ground[0] = 0;
        }
        ground[1] = 1;

    } else if ( result == 3 ) {
        if ( ground[2] == 1) {
            score++;
            ground[2] = 0;
        }
        if ( ground[1] == 1 ) {
            score++;
            ground[1] = 0;
        }
        if ( ground[0] == 1 ) {
            score++;
            ground[0] = 0;
        }
        ground[2] = 1;

    } else if ( result == 4) {
        for(int i = 0; i < 3; i++) {
            if ( ground[i] == 1 ) {
                score++;
                ground[i] = 0;
            }
        }
        score++;
    } else if ( result == 0 ) {
        out++;
    }
}

int Play(int num) {
    int hitTurn = 0;
    score = 0;

    for(int ening = 0; ening < num; ening++) {
        //새로운 이닝 시작 전, 그라운드를 초기화.
        for(int i = 0; i < 3; i++) {
            ground[i] = 0;
        }
        while ( out != 3 ) {
            int player = turn[hitTurn];
            int result = arr[ening][player];

            hit(result);
            hitTurn++;
            if( hitTurn == 9 ) hitTurn = 0;
        }
        out = 0;
    }

    return score;
}
void makeTurn(int idx, int num) {
    if ( idx == 9 ) {
        int scoreTmp = Play(num);
        if( MAX < scoreTmp ) MAX = scoreTmp;
        return;
    }

    if ( idx == 3 ) {
        turn[idx] = 0; // 4번째 타석엔 1번째 선수가 들어간다. 무조건.
        makeTurn(idx + 1, num );
    }
    else for(int i = 1; i < 9; i++) {
        if( !visit[i] ) {
            visit[i] = true;
            turn[idx] = i;
            makeTurn(idx+1, num);
            visit[i] = false;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 9; j++) {
            int input = 0;
            scanf("%d", &input);
            arr[i][j] = input;
        }
    }

    makeTurn(0, N);
    printf("%d\n", MAX);
    return 0;
}