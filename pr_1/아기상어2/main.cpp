#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N = 0 , M = 0;

int UD[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int LR[8] = {0, -1, 0, 1, -1, 1, -1, 1};

typedef struct shark{
    int row = 0;
    int col = 0;
}Shark;

vector<Shark> shark;
vector< vector<int > > vec;
vector< vector<int> > visit;
vector<int> dist;

void PrintVec() {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
        }
        cout << endl;
    }
}
void PrintVisit() {
    for(int i = 0; i < visit.size(); i++) {
        for(int j = 0; j < visit[i].size(); j++) {
            cout << visit[i][j];
        }
        cout << endl;
    }
}
void init() {
    vector<int> tmp;
    vector<int> vTmp(M, 0);

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int input;
            cin >> input;
            if( input == 1 ) {
                Shark sh;
                sh.row = i;
                sh.col = j;
                shark.push_back(sh);
            }
            tmp.push_back(input);
        }
        vec.push_back(tmp);
        visit.push_back(vTmp);
        tmp.clear();
    }
}
void allInit() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visit[i][j] = 0;
        }
    }
}

void BFS(int R, int C) {
    queue< pair<int, int> > que;
    visit[R][C] = 0;
    que.push({R, C});

    while( !que.empty() ) {
        int row = que.front().first;
        int col = que.front().second;
        que.pop();

        for (int i = 0; i < 8; i++) {
            int nextR = row + UD[i];
            int nextC = col + LR[i];

            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M || (nextR == R && nextC == C) ) {
//                cout << " 걸러진 것들 : " << nextR << " , " << nextC << endl;
                continue;
            }
            if (vec[nextR][nextC] == 0 && visit[nextR][nextC] == 0) {
                que.push({nextR, nextC});
                visit[nextR][nextC] = visit[row][col] + 1;
            } else if (vec[nextR][nextC] == 1 && visit[nextR][nextC] == 0 ) {
//                cout << " in : " << nextR << " , " << nextC << endl;
                visit[nextR][nextC] = visit[row][col] + 1;
                dist.push_back(visit[nextR][nextC]);
//                cout << "dist : " << visit[nextR][nextC] << endl;
                return;
//                que.push({nextR, nextC}); //다시 넣어줘야할까?
            }
        }
    }
}
int main() {
    cin >> N >> M;
    init();
    for(int i = 0; i < N; i++) {
       for(int j = 0; j < M; j++) {
           if( vec[i][j] != 1 ) {
               BFS(i, j);
//               PrintVec();
//               cout << endl;
//               PrintVisit();
//               cout << endl << "-------" << endl;
               allInit();
           }
       }
    }
//
//    if( dist.empty() ) cout << "안전거리 측정 불가" << endl;
//    for(int i = 0; i < dist.size(); i++) {
//        cout << dist[i] << " ";
//    }
    sort(dist.begin(), dist.end(), greater<int>());
    cout << dist[0] << endl;


    return 0;
}
