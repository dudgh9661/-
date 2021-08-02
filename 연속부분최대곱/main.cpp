#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
double MAX;

double dp[100000] = { 0 };
vector<double> vec;

void init() {
    cin >> N;
    double a;

    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
        dp[i] = a;
    }

    MAX = *max_element(vec.begin(), vec.end());
}

void sol() {
    for(int i = 1; i < N; i++) {
        dp[i] = max(dp[i], dp[i] * dp[i-1]);
        MAX = max(MAX, dp[i]);
    }
}
int main() {
    init();
    sol();
    cout << fixed;
    cout.precision(3);
    cout << MAX;
    return 0;
}

