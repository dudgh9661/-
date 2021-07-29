#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int row, col;

int arr[1001][1001] = { 0 };
int visited[1001][1001][2] = { 0 };

int UD[4] = { -1, 0, 1, 0};
int LR[4] = { 0, -1, 0, 1};

typedef struct node{
    int r, c, use; // 0 : 미사용, 1 : 사용
    node(int _r, int _c, int _use) : r(_r), c(_c), use(_use) {};
}NODE;

void Print() {
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void init() {
    cin >> row >> col;

    string input;
    for(int i = 1; i <= row; i++) {
        cin >> input;
        for (int j = 1; j <= input.length(); j++) {
            arr[i][j] = input[j-1] -'0';
        }
    }
}

bool inRange( int r, int c) {
    if ( r > row || r < 1 || c > col || c < 1) return false;
    return true;
}

void BFS() {
    queue< NODE > que;
    que.push({1,1,0});
    visited[1][1][0] = 1;

    while ( !que.empty() ) {
        int r = que.front().r;
        int c = que.front().c;
        int use = que.front().use;
        que.pop();

        if ( r == row && c == col ) {
            cout << visited[r][c][use];
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];
            if ( !inRange(nr,nc) ) continue;
            if ( visited[nr][nc][use] > 0 ) continue;

            if ( arr[nr][nc] == 1 && use == 0 ) {
                visited[nr][nc][1] = visited[r][c][use] + 1;
                que.push({nr,nc,1});
            } else if ( arr[nr][nc] == 0 ){
                visited[nr][nc][use] = visited[r][c][use] + 1;
                que.push({nr,nc,use});
            }
        }
    }

    cout << -1;
    return;
}

int main() {
    init();
//    Print();
    BFS();
    return 0;
}
