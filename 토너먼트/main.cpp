#include <iostream>

using namespace std;

int N, kim, im;
int cnt = 0;

void sol() {
    while(1) {
        cnt++;
        kim = kim / 2 + kim % 2;
        im = im / 2 + im % 2;
        if ( kim == im ) break;
    }
}
int main() {
    cin >> N >> kim >> im;
    sol();
    cout << cnt;
    return 0;
}