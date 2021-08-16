#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string str;

void rever(int s, int e) {
    for(int i = s; i <= e; i++) {
        if ( str[i] == '0' ) str[i] = '1';
        else str[i] = '0';
    }
}

int split(char ch, char ch2) { // 기준, 자를거
    // 0
    int s = 0, cnt = 0;
    for(int i = 0; i < str.length(); i++) {
        if ( i+1 == str.length() && str[str.length()-1] == ch)  {
            cnt++;
            break;
        }
        if ( str[i] == ch2) {
            if ( i - s > 0 ) {
                cnt++;
            }
            s = i+1;
        }
    }
    return cnt;
}
int main() {
    cin >> str;
    int ans = min(split('0','1'), split('1','0'));
    cout << ans;
    return 0;
}
