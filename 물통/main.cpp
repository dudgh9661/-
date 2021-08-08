#include <iostream>
#include <vector>

using namespace std;

bool visited[201][201] = { false };
bool ans[201] = { false };

int A, B, C;

void init() {
    cin >> A >> B >> C;
}

void DFS(int a, int b, int c) {
    if ( visited[a][b] == true ) return;
    visited[a][b] = true;
    if ( a == 0 ) ans[c] = true;

    // a->b
    if ( a + b > B ) {
        DFS( (a+b)-B, B, c);
    } else {
        DFS(0, a+b, c);
    }
    // a->c
    if ( a+c > C ) {
        DFS( (a+c)-C, b, C);
    } else {
        DFS(0, b, a+c);
    }
    // b->c
    if ( b+c > C ) {
        DFS( a, (b+c)-C, C);
    } else {
        DFS(a, 0, b+c);
    }
    // b->a
    if ( b+a > A ) {
        DFS( A, (b+a)-A, c);
    } else {
        DFS(b+a, 0, c);
    }
    // c->a
    if ( c+a > A ) {
        DFS( A, b, (c+a)-A );
    } else {
        DFS(c+a, b, 0);
    }
    // c->b
    if ( c+b > B ) {
        DFS( a, B, (c+b)-B);
    } else {
        DFS(a, c+b, 0);
    }
}

int main() {
    init();
    DFS(0,0, C);
    for(int i = 0; i <= C; i++) {
        if (ans[i] == true) cout << i << " ";
    }
    return 0;
}
