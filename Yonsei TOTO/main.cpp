#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int ans = 0;

vector<vector<int>> vec;
vector<int> mil;
int parti[100] = { 0 };

int leastNum(vector<int> sub, int limit) {
    sort(sub.begin(), sub.end(), greater<>());
    int least = sub[limit-1];
    return least;
}

void init() {
    cin >> N >> M;

    int P, L;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> P >> L;
        vector<int> input;
        for(int j = 0; j < P; j++) {
          cin >> a;
          input.push_back(a);
        }
        vec.push_back(input);
        parti[i] = L;
    }
}

void sol() {
    for(int i = 0; i < vec.size(); i++) {
        if( vec[i].size() < parti[i] ) {
            mil.push_back(1);
            continue;
        }
        int least = leastNum(vec[i], parti[i]);
//        printf("%d번째 과목 최소 마일리지값 : %d\n", i+1, least);
        mil.push_back(least);
    }

    sort(mil.begin(), mil.end(), less<>());

    for(int i = 0; i < mil.size(); i++) {
        if(mil[i] > 36 ) return;
        if( M < 1) return;

        if( M >= mil[i] ) {
            ans++;
//            printf("현재 마일리지 : %d 차감 마일리지 : %d, 신청 후 마일리지 %d\n", M, mil[i], M - mil[i]);
            M -= mil[i];
        }
        else return;
    }
}

int main() {
    init();
    sol();
    cout << ans << endl;
    return 0;
}
