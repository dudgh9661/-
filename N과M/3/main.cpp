#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> vec;
bool visited[8] = { false };
void DFS(int cnt, int limit) {
    if( cnt == limit ) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        for(int i = 1; i <= N; i++) {
            vec.push_back(i);

            DFS(++cnt, limit);

            --cnt;
            vec.pop_back();
        }
    }


}

int main() {
    cin >> N >> M;
    DFS(0, M);
    return 0;
}
