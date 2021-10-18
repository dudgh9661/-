#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K;

vector<int> vec;
vector<int> ans[11];

void DFS(int start, int end, int depth) {
    if (start == end) {
        ans[depth].push_back(vec[start]);
        return;
    }

    int root = (start + end) / 2;
    // left
    DFS(start, root-1, depth+1);
    ans[depth].push_back(vec[root]);
    // right
    DFS(root+1, end, depth+1);
}

void init() {
    cin >> K;
    int a;
    for (int i = 0; i < pow(2,K)-1; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

int main() {
    init();
    DFS(0, vec.size()-1, 1);

    for(int i = 1; i <= 10; i++) {
        if (ans[i].empty()) break;
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
