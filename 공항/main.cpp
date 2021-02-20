#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gate, P;
int answer = 0;

vector<int> info;
int docking[100001] = { -1 };

void init() {
    cin >> gate;
    cin >> P;
    int a;
    for(int i = 0; i < P; i++) {
        cin >> a;
        info.push_back(a);
    }
}

int Find(int gi) {
    if( docking[gi] == -1 ) return gi;
    return docking[gi] = Find(docking[gi]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    docking[u] = v;
}

void sol() {
    for(int i = 0; i < info.size(); i++) {
        int result = Find(info[i]);
        if( result == 0 ) return;
        else {
            Union( result, result-1);
            answer++;
        }
    }
}

void Print() {
    for(int i = 1; i <= gate; i++) {
        cout << docking[i] << " ";
    }
}
int main() {
    init();
    fill(docking, docking+100001, -1);
    sol();
    cout << answer << endl;
//    Print();
    return 0;
}
