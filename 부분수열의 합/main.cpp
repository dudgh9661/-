#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S = 0, ans = 0;
bool isFirst = true;

vector<int> vec;

void init() {
    cin >> N >> S;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

void DFS(int sum, int idx) {
    //종료조

    //이미 정렬된 상태이므로, 더 나아가봐야 수가 더 커지기 때문에 pruning 해준다.
    if( sum > S  ) {
        return;
    }

    if( sum == S && !isFirst) {
        ans++;
    }
    //진입 조건
    isFirst = false;
    if( idx == N ) return;
    for(int i = idx; i < vec.size(); i++) {
        DFS(sum + vec[i], i + 1); //선택
    }
}

int main() {
    init();
    sort(vec.begin(), vec.end(), less<>());
    DFS(0,0);
    cout << ans << endl;
    return 0;
}
