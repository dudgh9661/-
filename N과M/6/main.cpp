#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> input;
vector<int> vec;
bool visited[10001] = { false };

void DFS(int cnt, int limit, int start) {
    if( limit == cnt ) {
        for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
        cout << "\n";
        return;
    }
    else {
        for(int i = start; i < input.size(); i++) {
            int in = input[i];
            if( !visited[in] ) {
                vec.push_back(in);
                visited[in] = true;

                DFS(++cnt, limit, i);

                --cnt;
                vec.pop_back();
                visited[in] = false;
            }
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
    DFS(0, M, 0);
    return 0;
}

