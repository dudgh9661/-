#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[501][501] = { 0 };
int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};
int dp[501][501] = { 0 };

typedef struct info{
    int r = -1;
    int c = -1;
}INFO;


//INFO search(int row, int col) {
//    INFO info;
//    int minR = -1, minC = -1, minValue = 1000001;
//
//    //네방향 중 가장 작은 곳을 찾는다.
//    for(int i = 0; i < 4; i++) {
//        int nextR = UD[i] + row;
//        int nextC = LR[i] + col;
//
//        if( nextR < 0 || nextR >= n || nextC < 0 || nextC >= n ) continue;
//
//        else if ( arr[nextR][nextC] > arr[row][col]) {
//            if ( arr[nextR][nextC] < minValue ) {
//                minR = nextR;
//                minC = nextC;
//                minValue = arr[nextR][nextC];
//            }
//        }
//    }
//        info.r = minR;
//        info.c = minC;
//        return info;
//
//}

int DFS(int row, int col) {
    if( dp[row][col] != 0 ) return dp[row][col];
    dp[row][col] = 1;
    for(int i = 0; i < 4; i++) {
        int nextR = row + UD[i];
        int nextC = col + LR[i];

        if( nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;
        else if ( arr[row][col] < arr[nextR][nextC] ) {
            dp[row][col] = max( dp[row][col], DFS(nextR, nextC) + 1);
        }
    }

    return dp[row][col];

}

void init() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int input = 0;
            cin >> input;
            arr[i][j] = input;
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int ans = 0;
//    cout << DFS(2,2,1);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = DFS(i,j);
//            cout << val << endl;
            if ( ans < val ) ans = val;
        }
    }
    cout << ans << "\n";

    return 0;
}
