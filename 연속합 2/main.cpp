#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int MAX = -1e9;

int arr[100000] = { 0 };
int leftSum[100000] = { 0 };
int rightSum[100000] = { 0 };

void init() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}
void getLeftSum() {
    leftSum[0] = arr[0];
    for(int i = 1; i < N; i++) {
        leftSum[i] = max(leftSum[i-1] + arr[i], arr[i]);
    }
}
void getRightSum() {
    rightSum[N-1] = arr[N-1];
    for(int i = N - 2; i >= 0; i--) {
        rightSum[i] = max(rightSum[i+1] + arr[i], arr[i]);
    }
}
int main() {
    init();
    if ( N == 1 ) {
        cout << arr[0];
        return 0;
    }
    getLeftSum();
    // 아무것도 빼지 않았을 때 최댓값
    MAX = max(*max_element(leftSum, leftSum + N), MAX);
    getRightSum();

    for(int i = 0; i < N; i++) {
        int leftIdx = i - 1;
        int rightIdx = i + 1;

        if ( leftIdx < 0 ) {
            MAX = max(MAX, rightSum[rightIdx]);
            continue;
        } else if ( rightIdx >= N ) {
            MAX = max(MAX, leftSum[leftIdx]);
            continue;
        } else {
            MAX = max(MAX, leftSum[leftIdx] + rightSum[rightIdx]);
        }
    }

    cout << MAX;
    return 0;
}
