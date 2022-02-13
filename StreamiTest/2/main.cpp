#include <iostream>

using namespace std;

long long toDecimal2(string s) {
    long long dec = 0;
    int base = 0;
    for (int i = s.size()-1; i >= 0; i--) {
        int num = s[i]-'0';
        if (num == 0) {
            base++;
            continue;
        }
        long long res = num * pow(2,base);
        base++;
        dec += res;
    }

    return dec;
}

long long toDecimal(string s) {
    long long num = stol(s);
    long long decVal = 0;
    long long base = 1;
    long long tmp = num;

    while (tmp) {
        long long last = tmp % 10;
        tmp /= 10;

        decVal += last * base;
        base *= 2;
    }

    return decVal;
}

int solution(string &S) {
    long long dec = toDecimal2(S);
    if (dec == 0) return 0;
    int cnt = 0;

    while (dec != 0) {

        if (dec % 2 != 0) { // odd
            dec -= 1;
        } else { // even
            dec /= 2;
        }
        cnt++;
    }

    return cnt;
}

int main() {
    string s = "011100";
//    cout << toDecimal2("011100");
    cout << "cnt : " << solution(s);
    return 0;
}
