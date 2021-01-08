#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;

bool visited[10001] = { false };

vector<int> vec;
vector<int> input;

void DFS(int cnt) {
    if( cnt == M ) {
        for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < input.size(); i++) {
        if( visited[input[i]] ) continue;

        vec.push_back(input[i]);
        visited[input[i]] = true;

        DFS(cnt+1);

        vec.pop_back();
        visited[input[i]] = false;
    }

}
int main() {
    cin >> N >> M;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        input.push_back(a);
    }
    sort(input.begin(), input.end(), less<>());
    DFS(0);
    return 0;
}
