#include <iostream>
#include <vector>

using namespace std;

int N,M;

bool visited[9] = { false };

vector<int> vec;

void DFS(int cnt, int start) {
    if( cnt == M ) {
        for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i <= N; i++) {
        if( visited[i] ) continue;
        vec.push_back(i);
        visited[i] = true;

        DFS(cnt + 1, i+1);

        vec.pop_back();
        visited[i] = false;
    }
}
int main() {
    cin >> N >> M;
    DFS(0,1);
    return 0;
}
