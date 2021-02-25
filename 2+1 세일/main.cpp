#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

void init() {
    cin >> N;

    int a = 0;
    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end(), greater<>());
}

int findMin(int idx) {
    int MIN = 1e9;
    int minIdx = -1;

    if( idx + 2 > vec.size() - 1 ) {
        return -1;
    }
    else {
        for (int i = idx; i < idx + 3; i++) {
            if( MIN > vec[i] ) {
                MIN = vec[i];
                minIdx = i;
            }
        }
        return minIdx;
    }
}

void sol() {
    int sum = 0;
    int cnt = 0;
    int curIdx = 0;

    while(true) {
        int res = findMin(curIdx);
        if( res == -1 ) {
            for(int i = curIdx; i < vec.size(); i++) {
                sum += vec[i];
            }
            break;
        } else {
            for(int i = curIdx; i < curIdx + 3; i++) {
                if( i == res ) {
                    continue;
                }
                sum += vec[i];
            }
            curIdx += 3;
        }
    }

    cout << sum;
}
int main() {
    init();
    sol();
    return 0;
}
