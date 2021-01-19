#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int MIN = 1e9;

int map[21][21] = { 0 };
bool visited[21] = { false };

vector<int> S;

void init() {
    cin >> N;

    int input;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> input;
            map[i][j] = input;
        }
    }
}
void Print(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    cout << endl;
}
int teamS() {
    int score = 0;
//    cout << "< 팀 S > ";
//    Print(S);
    for(int i = 0; i < S.size(); i++) {
        int r = S[i];
        for(int j = i+1; j < S.size(); j++) {
            int c = S[j];
            score +=  map[r][c] + map[c][r];
        }
    }
    return score;
}

int teamL() {
    vector<int> L;
//    cout << "< 팀 L > ";
    for(int i = 1; i <= N; i++) {
        if( !visited[i] ) L.push_back(i);
    }
//    Print(L);
    int score = 0;
    for(int i = 0; i < L.size(); i++) {
        int r = L[i];
        for(int j = i+1; j < L.size(); j++) {
            int c = L[j];
            score += map[r][c] + map[c][r];
        }
    }
    return score;
}

void DFS(int cnt, int start) {
    if( cnt == N / 2) {
        //최소값 계산 후, 갱신
        int res = abs(teamS() - teamL());
        MIN = min(MIN, res);
        return;
    }

    for(int i = start; i <= N; i++) {
        if( visited[i] ) continue;
        S.push_back(i);
        visited[i] = true;

        DFS(cnt+1, i+1);

        S.pop_back();
        visited[i] = false;
    }

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    DFS(0,1);
    cout << MIN << "\n";
    return 0;
}
