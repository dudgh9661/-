#include <iostream>
#include <vector>

using namespace std;

int N,M;

vector<int> vec;

void DFS(int cnt) {
    if( cnt == M ) {
        for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++) {
        vec.push_back(i);

        DFS(cnt + 1);

        vec.pop_back();
    }

}
int main() {
    cin >> N >> M;
    DFS(0);
    return 0;
}
