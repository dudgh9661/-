#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> vec;
bool visited[9] = { false };
void DFS(int cnt, int limit) {
    if( limit == cnt ) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
        return;
    } else {
        for(int i = 1; i <= N; i++) {
            if( !visited[i] ) {
                vec.push_back(i);
                visited[i] = true;

                DFS(++cnt, limit);

                cnt--;
                vec.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    DFS(0, M);
    return 0;
}
