#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int MAX = 0;
int arr[1000001] = { 0 };

void init() {
    cin >> N >> K;
    int g, x;
    for(int i = 0; i < N; i++) {
        cin >> g >> x;
        arr[x] = g;
    }
}

void sol() {
    int start = 0, end = 0;
    int sum = 0;
    while ( end < 1000001 ) {
        if ( end - start <= 2*K+1) {
            sum += arr[end++];
            MAX = max(sum, MAX);
        } else if ( end - start > 2*K+1 ) {
            sum -= arr[start++];
        }
    }
}
int main() {
    init();
    sol();
    cout << MAX << endl;
    return 0;
}
