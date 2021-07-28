#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int arr[1000][1000] = { 0 };
int UD[4] = { 1, 0, -1, 0};
int LR[4] = { 0, 1, 0, -1};

int N;
int target;
pair<int, int> pos;
int num;

bool inRange(int r, int c) {
    if ( r > N || r < 1 || c > N || c < 1 ) return false;
    return true;
}

void init() {
    cin >> N;
    cin >> target;
    num = pow(N, 2);
}

void sol() {
    int arrow = 0;
    int r = 1, c = 1;
    arr[r][c] = num--;
    pos = {1, 1};
    while ( num != 0 ) {
        while( true ) {
            int nr = r + UD[arrow];
            int nc = c + LR[arrow];
            if (!inRange(nr, nc) || arr[nr][nc] != 0 ) {
                arrow = (arrow + 1) % 4;
                break;
            }

            r = nr;
            c = nc;
//            cout << r << " , " << c << " : " << num << "\n";
//            if ( r == 4 && c == 1) break;
            arr[r][c] = num--;
            if (arr[r][c] == target) {
                pos = {r, c};
            }
        }
    }
}

void print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << pos.first << " " << pos.second;
}
int main() {
    init();
    sol();
    print();
    return 0;
}
