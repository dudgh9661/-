#include <iostream>
#include <vector>

using namespace std;

int N;
int ans = 0;
int arr[101][101] = { 0 };

void init() {
    cin >> N;

    int c, r;
    for(int i = 0; i < N; i++) {
        cin >> c >> r;
        for(int row = r; row < r + 10; row++) {
            for(int col = c; col < c + 10; col++) {
                arr[row][col]++;
                ans++;
                if( arr[row][col] >= 2 ) ans--;
            }
        }
    }
}
int main() {
    init();
    cout << ans;
    return 0;
}
