#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[30000] = { 0 };
bool order[3001] = {false };

int N, d, k, c;
int MAX = -1;

vector<int> vec;

void init() {
    cin >> N >> d >> k >> c;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void orderInit() {
    for(int i = 0; i <= d; i++) {
        if ( i == c ) continue;
        order[i] = false;
    }
}

int getCnt() {
    int cnt = 0;
    for(int i = 1; i <= d; i++) {
        if ( order[i] ) cnt++;
    }
    return cnt;
}

void sol() {
    order[c] = true; // coupon

    for (int i = 0; i < N; i++) {
        for(int j = i; j < i + k; j++) { // move k
            int menu = arr[j%N];
            if( order[menu] ) continue;
            order[menu] = true;
        }
        MAX = max(getCnt(), MAX);
        orderInit();
    }
}

int main() {
    init();
    sol();
    cout << MAX;
    return 0;
}
