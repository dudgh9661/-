#include <iostream>
#include <vector>

using namespace std;

int N,M;

vector<int> vec;

void DFS(int cnt, int start) {
    if( cnt == M ) {
        for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i <= N; i++) {
        vec.push_back(i);

        DFS(cnt + 1, i);

        vec.pop_back();
    }

}
int main() {
    cin >> N >> M;
    DFS(0,1);
    return 0;
}
