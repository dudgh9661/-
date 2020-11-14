#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[25][25] = { 0 };
bool visit[25][25]= { false };

int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};

void Print(int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d", visit[i][j]);
        }
        printf("\n");
    }
}
int N;
int cnt = 0;
int answer = 0;
void DFS(int row, int col) {
    visit[row][col] = true;
    cnt++;

    for(int i = 0; i < 4; i++) {
        int nextRow = row + UD[i];
        int nextCol = col + LR[i];

        if( nextRow < 0 || nextRow > N  || nextCol < 0 || nextCol > N ) continue;

        if( visit[nextRow][nextCol] || arr[nextRow][nextCol] == 0 ) {
//            printf("%d, %d\n", nextRow, nextCol);
            continue;
        }
        else if(  arr[nextRow][nextCol] == 1 && !visit[nextRow][nextCol] ) {
            DFS(nextRow, nextCol);
        }
    }

}
int main() {


    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int itr = 0; itr < input.length(); itr++) {
            int num = input[itr] - '0';
            arr[i][itr] = num;
        }
    }

    vector<int> ans;

    for( int row = 0; row < N; row++) {

        for(int col = 0; col < N; col++) {
            if( arr[row][col] == 1 && !visit[row][col] ) {
                DFS(row, col);
                if( cnt > 0 ) {
                    ans.push_back(cnt);
                    answer++;
//                Print(N);
//                printf("\n");
                }
            }
            cnt = 0;

        }
    }

    printf("%d\n", answer);
    sort(ans.begin(), ans.end(), less<int>());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }


    //DFS로 단지 탐색
    //DFS depth가 집의 수임
    return 0;
}
