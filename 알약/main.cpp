#include <iostream>

using namespace std;

int N = -1;
long long dp[31][31];

int main() {
    for (int i = 0; i < 31; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i < 31; i++) {
        for(int j = 0; j < 31; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][1];
            } else {
                dp[i][j] = dp[i-1][j+1] + dp[i][j-1];
            }
        }
    }
    while(true) {
        cin >> N;
        if ( N == 0 ) break;
        cout << dp[N-1][1]<< "\n";
    }
    return 0;
}