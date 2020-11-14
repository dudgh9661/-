#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> input;
vector<int> vec;
bool visited[10001] = { false };

void DFS(int cnt, int limit) {
    if( limit == cnt ) {
        for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
        cout << "\n";
        return;
    }
    else {
        for(int i = 0; i < input.size(); i++) {
            int in = input[i];
            vec.push_back(in);

            DFS(++cnt, limit);

            --cnt;
            vec.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end(), less<int>());
//    for(int i = 0; i < input.size(); i++) {
//        cout << input[i] << " ";
//    }
    DFS(0, M);
    return 0;
}

