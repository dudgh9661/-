#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;

char map[101][101];
int visited[101][101] = { 0 };
int UD[4] = {-1, 0, 1, 0};
int LR[4] = {0, 1, 0, -1};
int number = 1;

void init() {
    cin >> N;
    char input;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> input;
            map[i][j] = input;
        }
    }
}

bool inRange(int row, int col, char ch ) {
    return row >= 0 && col >= 0 && row < N && col < N && visited[row][col] == 0 && map[row][col] == ch;
}

void BFS(int row, int col) {
    queue< pair<int, int> > que;
    que.push({row, col});
    visited[row][col] = number;
    char ch = map[row][col];

    while( !que.empty() ) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];

            if( inRange(nr, nc, ch) ) {
                visited[nr][nc] = number;
                que.push({nr, nc});
            }
        }
    }
}

void solution() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if( visited[i][j] == 0 ) {
                BFS(i, j);
                number++;
            }
        }
    }
    cout << number-1 << " ";
    number = 1;
}
int main() {
    init();
    solution();

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if( map[i][j] == 'G' ) map[i][j] = 'R';
        }
    }

    solution();

    return 0;
}
