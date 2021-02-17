#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> vec;
bool visited[9] = { false };

void init() {
    cin >> N >> M;
}

void DFS(int cnt) {
    if( cnt == M ) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++) {
        if( visited[i] ) continue;

        visited[i] = true;
        vec.push_back(i);

        DFS(cnt + 1);

        visited[i] = false;
        vec.pop_back();
    }
}

int main() {
    init();
    DFS(0);
    return 0;
}
