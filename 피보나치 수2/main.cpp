#include <iostream>
#include <vector>

using namespace std;

vector<long long> vec(90, -1);

long long num;

void input() {
    vec[0] = 0;
    vec[1] = 1;
    cin >> num;
}

long long fibo(long long n) {
    if( vec[n] != - 1) return vec[n];
    else {
        vec[n] = fibo(n-1) + fibo(n-2);
        return vec[n];
    }
}
void sol(int n) {
    long long ans = fibo(n);
    cout << ans;
}
int main() {
    input();
    sol(num);
    return 0;
}
