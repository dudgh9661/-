#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MIN = 1e9;

int dp[1000001] = { 0 };
int parent[1000001] = { 0 };

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < 1000001; i++) dp[i] = 1e9;

    dp[1] = 0;
    parent[1] = 0;
    
    dp[2] = 1;
    parent[2] = 1;
    
    dp[3] = 1;
    parent[3] = 1;
    
    for(int i = 4; i <= N; i++) {
        if ( i % 2 == 0 ) {
            if ( dp[i/2] + 1 < dp[i] ) {
                dp[i] = dp[i/2] + 1;
                parent[i] = i / 2;
            }
        }
        if ( i % 3 == 0 ) {
            if ( dp[i/3] + 1 < dp[i] ) {
                dp[i] = dp[i/3] + 1;
                parent[i] = i / 3;
            }
        }
        if ( dp[i] > dp[i-1]+1) {
            dp[i] = dp[i-1] + 1;
            parent[i] = i - 1;
        }
    }

    cout << dp[N] << "\n";
    while ( N != 0 ) {
        cout << N << " ";
        N = parent[N];
    }
    return 0;
}
