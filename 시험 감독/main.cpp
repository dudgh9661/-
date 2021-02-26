#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N,B,C;
long long MAIN = 0, SUB = 0;

vector<int> vec;

int Sub(int idx) {
    if( vec[idx] % C != 0 ) {
        return (vec[idx] / C ) + 1;
    } else return vec[idx] / C;
}

void init() {
    cin >> N;

    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
    }

    cin >> B >> C;
}

void sol() {
    for(int i = 0; i < vec.size(); i++) {
        vec[i] -= B;
        MAIN++;
        if( vec[i] > 0 ) {
            SUB += Sub(i);
        }
    }
}
int main() {
    init();
    sol();
    cout << MAIN + SUB << endl;
    return 0;
}
