#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int arr[101][101] = { 0 };

// 배열에 각 선수의 경기 정보 저장
void init(vector<vector<int>> results) {
    for(int i = 0; i < results.size(); i++) {
        int win = results[i][0];
        int lose = results[i][1];
        arr[win][lose] = 1;
        arr[lose][win] = -1;
    }
}

// 승패를 알 수 있는 선수의 수를 리턴
int CNT(int n) {
    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        int flag = 0;

        for(int j = 1; j <= n; j++) {
            if( arr[i][j] == 0 ) {
                if( flag == 0 ) flag = 1;
                else if ( flag == 1 ) {
                    flag = 0;
                    break;
                }
            }
        }
        if( flag == 1 ) cnt++;
    }

    printf("cnt : %d\n", cnt);
    return cnt;
}

void sol(int n) {
    // (2,5)의 경우에, 2번의 1,3,4번 선수와의 승부를 5와 연관시켜주는 코드
    for(int row = 1; row <= n; row++) { //row
        for(int col = 1; col <= n; col++) { //col
            if( arr[row][col] == 1 ) {
                for(int k = 1; k <= n; k++) {
                    if( arr[col][k] == 1 ) {
                        arr[row][k] = 1;
                        arr[k][row] = -1;
                    }
                }
            } else if ( arr[row][col] == -1 ) {
                for(int k = 1; k <= n; k++) {
                    if( arr[col][k] == -1 ) {
                        arr[row][k] = -1;
                        arr[k][row] = 1;
                    }
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    init(results);
    sol(n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    answer = CNT(n);
    return answer;
}