#include <iostream>
#define MAX 100000000

using namespace std;

int city[101][101] = { 0 };

void floid(int n ) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
//                if( city[i][k]+city[k][j] < city[i][j] ) city[i][j] = city[i][k]+city[k][j];
                if( city[j][i]+city[i][k] < city[j][k] ) city[j][k] = city[j][i]+city[i][k];
            }
        }
    }
}
void init(int n) {
    int m = 0;
    cin >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j ++) {
            city[i][j] = MAX;
        }
    }

    for(int i = 1; i <= n; i++) {
        city[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int from, to, c;
        cin >> from >> to >> c;
        if( city[from][to] > c ) city[from][to] = c;
    }
}

void filter(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if( city[i][j] == MAX ) city[i][j] = 0;
        }
    }
}
void Print(int n ) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
//            if( city[i][j] == MAX ) city[i][j] = 0;
            cout << city[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 0;
    cin >> n;
    init(n);
    floid(n);
    filter(n);
    Print(n);
    return 0;
}
