#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int map[31][31] = { 0 };
bool visited[31][31] = { false };

int UD[4] = {-1, 0, 1, 0};
int LR[4] = {0, -1, 0, 1};

int zeroCnt = 0;
int MIN = 1e9;

void init() {
    char input;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> input;
            if(input == '*') map[i][j] = 1;
            else {
                map[i][j] = 0;
                zeroCnt++;
            }
        }
    }
}

bool inRange(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < M && !visited[row][col] && map[row][col] == 0;
}

void DFS(int row, int col, int pos, int cnt, int dist) {
    if ( dist == zeroCnt ) {
        MIN = min(cnt, MIN);
        return;
    }
        int nr = row + UD[pos];
        int nc = col + LR[pos];

        // 갈 수 있는 방향
        if ( inRange(nr, nc) ) {
            visited[nr][nc] = true;
            DFS(nr, nc, pos, cnt, dist + 1);
            visited[nr][nc] = false;
        }
        // 갈 수 없는 방향
        if( !inRange(nr, nc)) {
            for(int nextPos = 0; nextPos < 4; nextPos++) {
                if( nextPos == pos ) continue;

                nr = row + UD[nextPos];
                nc = col + LR[nextPos];
                if( inRange(nr,nc) ) {
                    visited[nr][nc] = true;
                    DFS(nr, nc, nextPos, cnt + 1, dist + 1);
                    visited[nr][nc] = false;
                }
            }
        }

}
int main() {

    int tc = 1;
    while ( cin >> N >> M ) {
        fill(&visited[0][0], &visited[30][31], false);
        fill(&map[0][0], &map[30][31], 0);
        zeroCnt = 0;
        MIN = 1e9;
        init();


        if (zeroCnt == 1) {
            cout << "Case " << tc << ": " << 0 << endl;
            tc++;
            continue;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) {
                    for (int d = 0; d < 4; d++) {
                        visited[i][j] = true;
                        DFS(i, j, d, 1, 1);
                        visited[i][j] = false;
                    }
                }
            }
        }

        if (MIN == 1e9) MIN = -1;
        cout << "Case " << tc << ": " << MIN << endl;
        tc++;

    }
    return 0;
}



//갈 수 없을 때까지 같은 방향으로 계속해서 이동한다.
//갈 수 없는 방향이 나오면 방향을 바꾼다. ( 범위를 벗어나거나, 이미 방문했던 곳을 방문하거나(?), 장애물인 경우 )
