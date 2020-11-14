#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>

using namespace std;
int LR[4] = {-1, 0, 1, 0};
int UD[4] = {0, -1, 0, 1};

void Print(int N, int M, int **arr) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
           }
        printf("\n");
       }
}

void BFS(int N, int M, int **arr, int **visit) {
    queue< pair<int, int> > que;
    que.push( {0,0});
    visit[0][0] = true;
    
    while( !que.empty() ) {
        int row = que.front().first;
        int col = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++) {
            int Nrow = row+UD[i];
            int Ncol = col+LR[i];
            
            if( Nrow < 0 || Nrow > N - 1 || Ncol < 0 || Ncol > M - 1) continue;
            
            if( arr[Nrow][Ncol] == 1 && visit[Nrow][Ncol] == 0 ) {
                que.push( {Nrow, Ncol} );
                visit[Nrow][Ncol] = visit[row][col] + 1;
            }
            
        }
    }
    
}

int main() {
    int N = 0, M = 0;
    
    scanf("%d %d", &N, &M);
    int **arr = new int *[N];
    int **visit = new int *[N];
    for(int i = 0; i < N; i++) {
        arr[i] = new int[M];
        visit[i] = new int[M];
    }
    
    
    string input;
    for(int i = 0; i < N; i++) {
        cin >> input;

        for(int j = 0; j < input.length(); j++) {
            int num = input[j] -'0';
            arr[i][j] = num;
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visit[i][j] = 0;
        }
    }
    
    BFS(N, M, arr, visit);
//    Print(N,M, visit);
    
    printf("%d\n", visit[N-1][M-1]);
    return 0;
}
