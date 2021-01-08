#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> vec;
bool visited[9] = { false };

void dfs(int cnt) {
    if( cnt == M ) {
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++) {
        if( visited[i] ) continue;
        vec.push_back(i);
        visited[i] = true;

        dfs(cnt + 1);

        vec.pop_back();
        visited[i] = false;
    }
}

int main() {

    cin >> N >> M;
    dfs(0);
    return 0;
}
