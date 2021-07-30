#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int MIN = 1e9;
int bigJump;

vector< pair<int,int> > vec; // small jump, big jump;

void init() {
    cin >> N;
    int a, b;
    for(int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        vec.push_back({a,b});
    }

    cin >> bigJump;
}

void DFS(int energy, int pos, bool useBig) {
    //도착한 경우
    if ( pos == N - 1 ) {
        MIN = min(MIN, energy);
        return;
    } else if ( pos > N - 1 ) {
        return;
    }

    if(!useBig) {
        DFS(energy + bigJump, pos + 3, true);
    }
    //small jump
    DFS(energy + vec[pos].first, pos + 1, useBig);
    //Big jump
    DFS(energy + vec[pos].second, pos + 2, useBig);

}

int main() {
    init();
    DFS(0, 0, false);
    cout << MIN;
    return 0;
}
