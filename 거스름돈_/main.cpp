#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ans = 1e9;
void sol() {
    int fiveMok = n / 5;
    if ( n % 5 == 0 ) {
        ans = fiveMok;
        return;
    }

    for(int i = fiveMok; i >= 0; i--) {
        int rem = n - ( 5 * i);
        int twoMok = rem / 2;
        if ( rem % 2 != 0 ) continue; //거슬러 줄 수 없는 경우
        ans = min(ans, i + twoMok);
    }
}

int main() {
    cin >> n;
    sol();
    if ( ans == 1e9 ) cout << -1;
    else cout << ans;
    return 0;
}
