#include <iostream>
#include <algorithm>

using namespace std;

long long startNum, target;
long long MIN = 1e9;

void init() {
    cin >> startNum >> target;
}

long long addOne(long long num) {
    string str = to_string(num);
    str = str.append("1");
    long long res = stol(str);

    return res;
}

void DFS(long long num, long long cnt) {
    if( num == target ) {
        if( cnt < MIN ) {
            MIN = cnt;
//            cout << "number is " << num << "and Min is " << MIN << "\n";
            return;
        }
    } else if ( num > target ) return;

    DFS(num*2, cnt+1);
    DFS(addOne(num), cnt+1);
}
int main() {
    init();
    DFS(startNum, 0);
    if( MIN == 1e9 ) cout << -1;
    else cout << MIN + 1;
    return 0;
}
