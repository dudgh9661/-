#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
long long ans = 0;
priority_queue<long long, vector<long long>, greater<long long>> pq;

void sol() {
    for (int i = 0; i < M; i++) {
        long long sum = 0;
        for(int p = 0; p < 2; p++) {
            sum += pq.top();
//            cout << i+1 << "번째 : " << pq.top() << "\n";
            pq.pop();
        }
        for(int p = 0; p < 2; p++) {
            pq.push(sum);
        }
    }

    while ( !pq.empty() ) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}

void init() {
    cin >> N >> M;

    int input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        pq.push(input);
    }
}
int main() {
    init();
    sol();
    return 0;
}
