#include <iostream>
#include <vector>

using namespace std;

int n;
long long dp[36] = { 0 };
long long sol(int cur) {
    if (dp[cur] != 0) return dp[cur];
    else {
        for (int i = 0; i < cur; i++) {
            dp[cur] += sol(i) * sol(cur-(i+1));
        }
        return dp[cur];
    }
}

int main() {
    cin >> n;
//    memset(dp, -1, 36*sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    sol(n);
    cout << dp[n];
    return 0;
}
