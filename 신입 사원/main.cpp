#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int T,N;
vector<pair<int,int>> vec;

void init() {
    cin >> N;

    int a,b;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        vec.push_back({a,b});
    }
    sort(vec.begin(), vec.end(), less<>());
}

int sol(int ans) {
    int MIN = 1e9;
    for(int i = 0; i < vec.size(); i++) {
        bool pass = true;
        int b = vec[i].second; //면접 점수
        //최솟값 갱신
        if( b < MIN ) {
            MIN = b;
            ans++;
        }

    }
    return ans;
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        init();
        int ans = sol(0);
        cout << ans << "\n";
        vec.clear();
        vec.resize(0);
    }

    return 0;
}
