#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;

priority_queue<int, vector<int>, greater<int> > pq;

vector<int> vec;

void init() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;
        pq.push(input);
    }
}

void sol() {
    int sum = 0;
    int ans = 0;

    while( pq.size() > 1 ) {
        for(int i = 0; i < 2; i++) {
            sum += pq.top();
            pq.pop();
        }
        ans += sum;
        pq.push(sum);
        sum = 0;
    }

    cout << ans << endl;
}

int main() {
    init();
    sol();
    return 0;
}
