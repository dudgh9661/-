#include <string>
#include <vector>
#include <iostream>

using namespace std;

string ans = "";
int cnt = 0;

void split(int n, int x) {
    string input = to_string(n);
    if( input.length() == 1 ) {
        ans = input;
        return;
    }

    if ( x >= input.length() ) {
        x--;
        split(n, x);
    }

    string sub = input.substr(0, x);
    if( input[0+x+1] == '0') {
            x++;
            split(n, x);
    }
    else {
        string sub2 = input.substr(0 + x);
        int intSub = stoi(sub);
        int intSub2 = stoi(sub2);
        int tmp = intSub + intSub2;
        cnt++;
        cout << intSub << " + " << intSub2 << endl;
        split(tmp, x);
        return;
    }
//    string sum = to_string(tmp);
//    cout << tmp << endl;
//    return input;

}
vector<int> solution(int n) {
    split(n, 4);
    cout << ans << endl;
    cout << " and cnt : " << cnt << endl;
    vector<int> answer;
    return answer;
}

int main() {
    solution(10007);
    return 0;
}