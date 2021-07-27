#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string N;

bool isZero() {
    for(long long i = 0; i < N.length(); i++) {
        if (N[i] - '0' == 0) return true;
    }
    return false;
}

bool isThree() {
    long long sum = 0;

    for(long long i = 0; i < N.length(); i++) {
        sum += N[i] - '0';
    }

//    cout << "sum : " << sum << endl;
    if ( sum % 3 == 0 ) return true;
    else return false;
}

string sol() {
    vector<char> vec;
    string ans = "";

    for(long long i = 0; i < N.length(); i++) {
        vec.push_back(N[i]);
    }

    sort(vec.begin(), vec.end(), greater<>());
    for(char ch : vec) {
        ans.push_back(ch);
    }
//    cout << "ans : " << ans;
    return ans;
}

int main() {
    cin >> N;
    if ( isZero() && isThree() ) {
        cout << sol();
    } else {
        cout << -1;
    }
    return 0;
}
