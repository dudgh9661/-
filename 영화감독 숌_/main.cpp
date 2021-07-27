#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int cnt;
int ans;

bool flag (int number) { // 6이 연속해서 3개 이상 있는지 확인한다.
    string num = to_string(number);
    for(int i = 0; i < num.length() - 2; i++) {
        if ( num[i] == '6' && num[i+1] == '6' && num[i+2] == '6') return true;
    }
    return false;
}

void DFS(int number) {
    if( flag(number) ) {
        cnt++;
        if ( cnt == N ) {
            ans = number;
            return;
        }
    }

    DFS(number + 1);
}

int main() {
    cin >> N;
    DFS(666);
    cout << ans << endl;
    return 0;
}
