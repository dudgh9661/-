#include <iostream>
#include <vector>

using namespace std;

int arr[1001][1001] = { 0 };
int sum[1001][1001] = { 0 };
struct INFO {
    pair<int,int> from;
    pair<int,int> to;
};

vector<INFO> vec;

int r, c;

void init() {
    int q;
    cin >> r >> c >> q;

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> arr[i][j];
        }
    }

    int r1, c1, r2, c2;
    for(int i = 0; i < q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        vec.push_back({ {r1,c1}, {r2,c2} }); // from, to
    }
}
void getSum() {
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if ( j == 1 ) sum[i][j] = arr[i][j];
            else {
                sum[i][j] = sum[i][j-1] + arr[i][j];
            }
        }
    }
}
int getAns(INFO p) {
    int ans = 0;
    int r1 = p.from.first;
    int c1 = p.from.second;
    int r2 = p.to.first;
    int c2 = p.to.second;
    int mok = (r2 - r1 + 1) * (c2-c1+1);

    for(int i = r1; i <= r2; i++) {
        if ( c1 - 1 < 1 ) {
            ans += sum[i][c2];
        } else {
            ans += sum[i][c2] - sum[i][c1 - 1];
        }
    }

    return ans / mok;
}

int main() {
    init();
    getSum();
    for(auto p : vec) {
        cout << getAns(p) << "\n";
    }
    return 0;
}
