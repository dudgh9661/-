#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int MIN = 1e9;

int arr[11] = { 0 };
int visited[11] = { 0 };

vector<int> vec[11];
vector<int> red;

void init() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++) {
        int n, to;
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> to;
            vec[i].push_back(to);
            vec[to].push_back(i);
        }
    }
}

int getBlueIdx() {
    int cur = -1;
    for(int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            cur = i;
            break;
        }
    }
//    cout << "blueIdx : " << cur << endl;
    return cur;
}

void redConnected(int node) { // 1 : red, -1 : blue
    for(int i = 0; i < vec[node].size(); i++) {
        int next = vec[node][i];
        for(int to : red) {
            if ( to == next ) {
                if (visited[next] != 0) continue;
                visited[next] = 1;
                redConnected(next);
            }
        }
    }
}

void blueConnected(int node) { // 1 : red, -1 : blue
    for(int i = 0; i < vec[node].size(); i++) {
        int next = vec[node][i];
        if (visited[next] != 0 ) continue;
//        cout << node << "->" << next << endl;
         visited[next] = -1;
         blueConnected(next);
    }
}

int getDiff() {
    int one = 0, two = 0;
    for(int i = 1; i <= N; i++) {
        if ( visited[i] == 1 ) one += arr[i];
        else if (visited[i] == -1) two += arr[i];
    }

    return abs(one-two);
}

bool isConnected() {
    fill(visited, visited+11, 0);
    if (red.empty()) return false;

    visited[red[0]] = 1;
    redConnected(red[0]);

    int blueIdx = getBlueIdx();
    if (blueIdx == -1) return false;

    visited[blueIdx] = -1;
    blueConnected(blueIdx);


//    for(int i = 1; i <= N; i++) {
//        cout << visited[i] << " ";
//    }
//    cout << endl;
    if ( N - count(visited+1, visited+N+1, 0) == N ) {
        return true;
    }
    return false;
}

void DFS(int node) {
//    cout << endl << "red : ";
//    for(int n : red) {
//        cout << n << " ";
//    }
//    cout << endl;

    if (isConnected()) {
        MIN = min(MIN, getDiff());
//        cout << "MIN : " << MIN << "\n";
    }

    for(int i = node; i <= N; i++) {
        red.push_back(i);

        DFS(i+1);

        red.pop_back();
    }
}
int main() {
    init();

    DFS(1);
    if (MIN == 1e9) cout << -1 << "\n";
    else cout << MIN << "\n";
    return 0;
}

