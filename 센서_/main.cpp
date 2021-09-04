#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int ans = 0;

vector<int> vec;
vector<int> num;

void init() {
    cin >> N;
    cin >> K;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end(), less<>());
}

void getNum() {
    for(int i = 0; i < vec.size() - 1; i++) {
        int res = vec[i+1] - vec[i];
        num.push_back(res);
    }
    sort(num.begin(), num.end(), greater<>());
}

void sol() {
    if ( N == 1 ) {
        return;
    }
    getNum();
    for(int i = 0; i < K-1; i++) {
        if (i > num.size()-1) break;
        num[i] = -1;
    }
    for (int n : num) {
      if (n != -1) {
          ans += n;
      }
    }
}
int main() {
    init();
    sol();
    cout << ans;
    return 0;
}
