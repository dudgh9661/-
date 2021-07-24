#include <iostream>
#include <vector>

using namespace std;

int n;
long long dp[1000001] = { 0 };

void sol() {

    for(int i = 4; i <= n; i++) {
        dp[i] = ( dp[i-1] + dp[i-2] + dp[i-3] ) % 1000000009;
    }
}

int main() {
    //init
    int tc = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    cin >> tc;

    for(int i = 0; i < tc; i++) {
        cin >> n;
        if ( dp[n] == 0 ) sol();
        long long ans = dp[n];
        cout << ans << "\n";
    }
    return 0;
}
