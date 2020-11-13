#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K, W, H;
int CNT = 0;

int horR[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horC[8] = {-2, -1,  1,  2, 2, 1, -1, -2};

int monR[4] = {-1, 0, 1, 0};
int monC[4] = { 0, 1, 0,-1};

int map[200][200] = { 0 };
int visited[201][201][31] = { 0 };

typedef struct node{
    int R,C, Chance;
    node(int r, int c, int chance) : R(r), C(c), Chance(chance) {};
} NODE;

void init() {
    cin >> K;
    cin >> W >> H; //W가 col, H가 row
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int input = 0;
            cin >> input;
            map[i][j] = input;
        }
    }

}

void BFS(int row, int col) {
    queue<NODE> que;
    que.push(NODE(row,col, 0));
    visited[row][col][0] = 0;

    int flag = K;

    while( !que.empty() ) {
        int r = que.front().R;
        int c = que.front().C;
        int chance = que.front().Chance;
        que.pop();

        if( r == H-1 && c == W-1 ) {
            cout << visited[r][c][chance] << endl;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + monR[i];
            int nc = c + monC[i];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;

            if (visited[nr][nc][chance] == 0 && map[nr][nc] == 0) {
                que.push(NODE(nr,nc,chance));
                visited[nr][nc][chance] = visited[r][c][chance] + 1;
            }
        }
        if( chance < K ) { //말이 될 수 있는 횟수만
            for (int i = 0; i < 8; i++) {
                int nr = r + horR[i];
                int nc = c + horC[i];

                if (nr < 0 || nr >= H || nc < 0 || nc >= W ) continue;

                if (visited[nr][nc][chance+1] == 0 && map[nr][nc] != 1) {
                    que.push(NODE(nr, nc, chance+1));
                    visited[nr][nc][chance+1] = visited[r][c][chance] + 1;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    init();
    BFS(0,0);

//    for(int i = 0; i < H; i++) {
//        for(int j = 0; j < W; j++) {
//            cout << visited[i][j][0] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
