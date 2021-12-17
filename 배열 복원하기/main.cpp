#include <iostream>

using namespace std;

int H, W, X, Y;
int B[601][601] = { 0 };
int A[301][301] = { 0 };

void init() {
    cin >> H >> W >> X >> Y;

    for (int i = 1; i <= H+X; i++) {
        for (int j = 1; j <= W+Y; j++) {
            cin >> B[i][j];
        }
    }
}

bool inRange(int r, int c) {
    if ( r < 1 || r > H || c < 1 || c > W) return false;
    return true;
}

void sol() {
    for (int i = 1; i <= H ; ++i) {
        for (int j = 1; j <= W; ++j) {
            int r = i-X, c = j-Y;
            if (inRange(r,c)) {
                A[i][j] = B[i][j] - A[r][c];
            } else {
                A[i][j] = B[i][j];
            }
        }
    }
}

int main() {
    init();
    sol();
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
