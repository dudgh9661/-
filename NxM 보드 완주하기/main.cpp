#include <iostream>
#include <vector>

#define INF 100000;
using namespace std;

int N,M;

int map[31][31] = {0};
bool visited[31][31] = {false};

int ud[4] = {0,-1,0,1};
int lr[4] = {-1,0,1,0};

int MIN = (int)1e9;
int cntEle = 0;

vector< pair<int,int> > zero;

bool inRange(int r, int c) { //여기서 방향 바꾸는 조건 만듦
    return r >= 0 && c >= 0 && r < N && c < M && map[r][c] == 0 && !visited[r][c];
}
void initVis() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = false;
            map[i][j] = 0;
        }
    }
}


void DFS(int row, int col, int pos, int dist, int cnt) {
    if( dist == cntEle) {
        MIN = min(MIN, cnt);
//        cout << "Here" << endl;
        return;
    }
    int nr = row + ud[pos];
    int nc = col + lr[pos];
//    cout << "cur : " << row << "," << col << endl;

    if( !inRange(nr,nc)) { //더이상 같은 방향으로 진행 불가할때,
        for(int i = 0; i < 4; i++) {

            nr = row + ud[i];
            nc = col + lr[i];
            if( inRange(nr,nc) ) { //방향을 바꿨을 때 나아갈 수 있다면,
                visited[nr][nc] = true;
                DFS(nr, nc, i, dist + 1, cnt + 1);
                visited[nr][nc] = false;
            }
        } //if( map[nr][nc] == 0 && visited[nr][nc] == 0 )
    }
    else  {
        visited[nr][nc] = true;
        DFS(nr,nc, pos, dist+1, cnt);
        visited[nr][nc] = false;
    }

}

int main() {
    int tc = 1;
    while( cin >> N >> M ) {
        MIN = 1e9;
        initVis();
        cntEle = 0;

        char input;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> input;
                if (input == '*') map[i][j] = 1;
                else {
                    map[i][j] = 0;
                    zero.push_back({i, j});
                    cntEle++;
                }
            }
        }

        if (cntEle == 1) {
            cout << "Case " << tc << ": " << 0 << endl;
            tc++;
            continue;
        }
        for (int i = 0; i < zero.size(); i++) {
            int r = zero[i].first;
            int c=  zero[i].second;
            for(int j = 0; j < 4; j++) {
                visited[r][c] = true;
                DFS(r, c, j, 1, 1);
                visited[r][c] = false;
            }
        }
        if (MIN == (int)1e9) MIN = -1;
        cout << "Case " << tc << ": " << MIN << '\n';

//
//        for (int i = 0; i < zero.size(); i++) {
//            int r = zero[i].first;
//            int c = zero[i].second;
//            if( !inRange(r+ud[i], c+lr[i])) continue;
//            for (int j = 0; j < 4; j++) {
//                visited[r][c] = true;
//                DFS(r, c, j, 1, 1);
//                visited[r][c] = false;
//            }
//        }
//        if (MIN != (int)1e9) {
//            cout << "hi Case " << tc << ": " << MIN << endl;
//        }
//        else cout << "Case " << tc << ": "<< -1 << endl;
        tc++;
        zero.clear();
        zero.resize(0);
    }
    return 0;
}

