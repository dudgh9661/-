#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N,M;
int ans = 0;

vector<int> apple;

typedef struct basket{
    int s, e;
}BASKET;

BASKET bas;

void init() {
 cin >> N >> M;

 bas.s = 0;
 bas.e = M-1;

 int cnt;
 cin >> cnt;
 int input;
    for(int i = 0; i < cnt; i++) {
        cin >> input;
        apple.push_back(input-1);
    }
}
bool inRange(int num) {
    if( num >= bas.s && num <= bas.e ) return true;
    else return false;
}
void sol() {
    for(int i = 0; i < apple.size(); i++) {
        //범위 안에 있으면
        if( inRange(apple[i])) {
            continue;
        }
        //범위 안에 없으면
        else if ( !inRange(apple[i]) ) {
            if( apple[i] < bas.s ) {
                int dis = abs(bas.s - apple[i]);
                ans += dis;
                bas.s -= dis;
                bas.e -= dis;
            } else if ( apple[i] > bas.e ) {
                int dis = abs(bas.e - apple[i]);
                ans += dis;
                bas.s += dis;
                bas.e += dis;
            }
        }
    }
}
int main() {
    init();
    sol();
    cout << ans;
    return 0;
}
