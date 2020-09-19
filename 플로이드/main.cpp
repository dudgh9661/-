#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define INF 100000000

int map[101][101] = { 0 };

void Print(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void init(int n, int m) {

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            map[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++) {
        map[i][i] = 0;
    }


    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if ( map[a][b] > c )
            map[a][b] = c;
    }


}

void floydwarshall(int n) {
    // i는 거쳐가는 지점
    for(int i = 1; i <= n; i++) {
        //j는 출발 지점
        for(int j = 1; j <= n; j++) {
            //k는 도착 지점
            for(int k = 1; k <= n; k++) {
                if( map[j][i] + map[i][k] < map[j][k]) {
                    map[j][k] = map[j][i] + map[i][k];
                }
            }
        }
    }
}

void filter(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if( map[i][j] == INF ) map[i][j] = 0;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    init(n, m);
    floidwarshall(n);
    filter(n);
    Print(n);

    return 0;
}
