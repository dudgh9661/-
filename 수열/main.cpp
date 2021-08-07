#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100000];
int dp2[100000];

vector<int> vec;

int n;
int ans = 0;

void init() {
    cin >> n;
    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

void sol() {
    dp[0] = 1;
    for(int i = 0; i < n-1; i++) {
        if ( vec[i] <= vec[i+1] ) {
            dp[i+1] = dp[i] + 1;
        } else {
            dp[i+1] = 1;
        }
    }

    dp2[n-1] = 1;
    for(int i = n-1; i > 0; i--) {
        if ( vec[i-1] >= vec[i] ) {
            dp2[i-1] = dp2[i] + 1;
        } else {
            dp2[i-1] = 1;
        }
    }
    int a = *max_element(dp, dp+n);
    int b = *max_element(dp2, dp2+n);
    ans = max(a,b);
}
int main() {
    init();
    sol();
    cout << ans;
    return 0;
}
