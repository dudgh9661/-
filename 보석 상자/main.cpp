#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int ans = 1e9;

vector<int> vec;

void init() {
    cin >> N >> M;

    int a;
    for(int i = 0; i < M; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

int getNum(int mid) {
    int sum = 0;

    for(int i = 0; i < vec.size(); i++) {
        int mok = vec[i] / mid;
        int remain = vec[i] % mid;

        if ( remain > 0 ) mok++;

        sum += mok;
    }

    return sum;
}

void sol() {
    int start = 1;
    int end = *max_element(vec.begin(), vec.end());

    while ( start <= end ) {
        int mid = (start + end ) / 2;
        int res = getNum(mid);
        if ( res > N ) {
            start = mid + 1;
        }
        else if ( res <= N ) {
            ans = min(ans, mid);
            end = mid - 1;
        }
    }
}
int main() {
    init();
    sol();
    cout << ans;
    return 0;
}
