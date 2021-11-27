#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
 * 1. 각 좌석에서 가장 가까운 관람객까지의 거리를 모두 구한다.
 * 2. 그 중 가장 큰 거리 좌석의 정보를 구한다(같은 값들은 조건에 따라 필터링)
 * 3. 해당 좌석에 배치한다.
 */

int arr[50][50] = {0};
int visited[50][50] = { -1 };
vector<pair<int,int>> seatInfo;
int UD[4] = {-1,0,1,0};
int LR[4] = {0,1,0,-1};

int curVisitor = 1;

void initData(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) { // 좌석에 사람이 앉은 경우
                visited[i][j] = 0;
            } else visited[i][j] = -1;
        }
    }
}

bool inRange(int r, int c, int n) {
    if (r < 0 || r > n-1 || c < 0 || c > n-1) return false;
    return true;
}
// 좌석 간 거리구하는 함수
int BFS(int n) {
    int MAX = -1;
    initData(n);
    queue<pair<int,int>> que;
    for (auto p : seatInfo) {
        que.push(p);
    }

    while (!que.empty()) {
        int r = que.front().first;
        int c = que.front().second;
        MAX = max(MAX, visited[r][c]);
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + UD[i];
            int nc = c + LR[i];
            if (!inRange(nr,nc,n)) continue;
            else if (visited[nr][nc] != -1) continue; // 이미 좌석이 있는 경우 또는 방문한 경우
            visited[nr][nc] = visited[r][c] + 1;
            que.push({nr,nc});
        }
    }
    return MAX;
}

vector<pair<int,int>> getMaxDist(int n, int MAX) {
//    cout << "MAX : " << MAX << endl;
    vector<pair<int,int>> tmp;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (MAX == visited[i][j]) tmp.push_back({i,j});
        }
    }
    return tmp;
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

pair<int,int> getAns(int n, int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == k) return {i,j};
        }
    }
}
vector<int> solution(int n, int k) {
    vector<int> answer;
    seatInfo.push_back({0,0});
    arr[0][0] = curVisitor++;
    int CNT = n*n -1;

    while (CNT != 0) {
        int MAX = BFS(n);
        vector<pair<int, int>> dist = getMaxDist(n, MAX);
        sort(dist.begin(), dist.end(), cmp);
        auto seat = dist[0];
//        cout << seat.first << " , " << seat.second << endl;
        seatInfo.push_back(seat);
        arr[seat.first][seat.second] = curVisitor++;
        CNT--;
//        break;
    }
    // 정답은 행+1, 열+1로 리턴할 것.
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//           cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }

    auto ans = getAns(n,k);
    answer.push_back(ans.first+1);
    answer.push_back(ans.second+1);

    cout << "answer : " << answer[0] << " , " << answer[1] << endl;
    return answer;
}

int main() {
    solution(50,1);
}