#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc;
int N;

vector<int> vec;
vector<int> ans;
bool visited[200] = { false };

void init() {
    fill(visited, visited + 200, false);
    vec.clear();
    vec.resize(0);
    ans.clear();
    ans.resize(0);

    cin >> N;

    int a;
    for(int i = 0; i < N * 2; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

bool isFour(int num) {
    if ( num % 4 == 0 ) return true;
    else return false;
}

int isExist(int num) {
    for(int i = 0; i < vec.size(); i++) {
        if ( vec[i] == num && !visited[i]) return i;
    }
    return -1;
}

void sol() {
    for(int i = 0; i < vec.size(); i++) {
        if (visited[i]) continue;
        int num = vec[i];
        if (isFour(num)) {
            int res = num * 0.75;
            int returnIdx = isExist(res);
            if ( returnIdx > -1 ) { // 할인된 금액과 부합한 가격이 있다면,
                ans.push_back(res);
                visited[returnIdx] = true;
                visited[i] = true;
            }
        }
    }
}

int main() {
    cin >> tc;
    for(int i = 0; i < tc; i++) {
        init();
        sol();
        sort(ans.begin(), ans.end(), less<>());
        cout << "Case #" << i+1 << ": ";
        for (int num : ans) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}
