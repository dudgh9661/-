#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isPrime(long long num) {
    int cnt = 0;
    if (num == 1) return false;
    for(long long i = 2; i <= sqrt(num); i++) {
        if ( num % i == 0 ) return false;
    }
    return true;
}
bool isP(string str) {
    if (str.find('0') == string::npos ) return true;
    return false;
}

string makeNum(int n, int k) {
    stack<int> st;

    while ( true ) {
        int mok = n / k;
        int rem = n % k;
        st.push(rem);
        n = mok;
        if ( n == 0 ) break;
    }

    string sosu;
    while (!st.empty()) {
        sosu.append(to_string(st.top()));
        st.pop();
    }

    return sosu;
}

int solution(int n, int k) {
    int answer = 0;
    string sosu = makeNum(n,k);
    for(int i = 0; i < sosu.length(); i++) {
        string str = "";

        for(int j = i; j < sosu.length(); j++) {
            if (sosu[j] == '0') {
                i = j;
                break;
            }
            str.append(to_string(sosu[j]-'0'));
//            cout << str << endl;
            if (isPrime(stol(str))) { // if num is Prime
                if (isP(str)) { // 각 자릿수에 0이 없으면,
                    // 0P0
                    if ( i-1 >= 0 && j+1 < sosu.length() && sosu[i-1] == '0' && sosu[j+1] == '0' ) {
                        cout << "in case 0P0 : " << str << endl;
                        answer++;
                    }
                    // P0
                    else if ( j+1 < sosu.length() && i == 0 && sosu[j+1] == '0' ) {
                        cout << "in case P0 : " << str << endl;
                        answer++;
                    }
                    // 0P
                    else if ( i-1 >= 0 && sosu[i-1] == '0' && j+1 == sosu.length()) {
                        cout << "in case 0P : " << str << endl;
                        answer++;
                    }
                    // P
                    else if ( str.length() == sosu.length() ) {
                        cout << "in case P : " << str << endl;
                        answer++;
                    }
                }
            }
        }
    }

//    cout << "ans : " << answer << endl;
    return answer;
}

int main() {
    solution(437674,3);
}