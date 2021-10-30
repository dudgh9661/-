#include <string>
#include <vector>
#include <cmath>

using namespace std;

int arr[26][26] = { 0 };
int UD[4] = {0,1,0,-1}; // right, dw, left, up
int LR[4] = {1,0,-1,0};
bool visited[626] = { false }; // 1~25
int arrow = 0;
// 이미 채워진 칸은 count 하지 않는다.

bool inRange(int r, int c,int n) {
    if ( r < 1 || r > n || c < 1 || c > n) return false;
    return true;
}
pair<int, int> getAns(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == pow(n,2)) {
                return {i,j};
            }
        }
    }
}
vector<int> solution(int n, int jump) {
    vector<int> answer; // 마지막 수의 행과 열

    int r = 1, c = 1;
    int number = 1;
    arr[r][c] = number;
    // n^2가 작거나 작으면 계속 반복.
    while (number <= pow(n,2)) {
        int cntJump = jump;
        while (cntJump > 0){
            // 현위치가 격자 중앙 부분이라, 더이상 갈 곳이 없다면, (1,1)로 이동시킨다.
            if (r == && c == ) {

            }
            int nr = r + UD[arrow];
            int nc = c + LR[arrow];
            if (!inRange(nr,nc,n)) {
                arrow = (arrow + 1) % 4;
                nr = r + UD[arrow];
                nc = c + LR[arrow];
            }
            r = nr;
            c = nc;

            // 다음 칸에 숫자가 있는 경우
            if (arr[nr][nc] != 0) continue;
            // 다음 칸이 빈칸인 경우
            else if (arr[nr][nc] == 0) cntJump--;
        }
        arr[r][c] = ++number;
    }
//    answer = getAns(n);
    return answer;
}