#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool first(string amountText) {
    for(int i = 0; i < amountText.size(); i++) {
        if ( !isdigit(amountText[i]) ) {
            if ( amountText[i] != ',') return false;
        }
    }
    return true;
}

bool second(string amountText) {
    if ( amountText.length() > 1) {
        if (amountText[0] == '0') return false;
    }
    return true;
}


bool third(string amountText) {
    int pos = amountText.find(',');
    if (pos == string::npos ) return true;
    int cnt = 0;
    for(int i = amountText.length() - 1; i >= 0; i--) {
        if (amountText[i] != ',') cnt++;
        if (cnt == 3) {
            if ( i == 0 ) continue;
            if (amountText[i-1] != ',') return false;
            cnt = 0;
        }
    }
    return true;
}

bool fourth(string amountText) {
    if (amountText[0] == ',') return false;
    if (amountText[amountText.length()-1] == ',') return false;
    return true;
}

bool solution(string amountText) {
    bool answer = true;
    if ( first(amountText) == false ) answer = false;
    if ( second(amountText) == false ) answer = false;
    if ( third(amountText) == false ) answer = false;
    if ( fourth(amountText) == false ) answer = false;

    cout << first(amountText) << endl;
    cout << second(amountText) << endl;;
    cout << third(amountText) << endl;;
    cout << fourth(amountText) << endl;;

    cout << "anssnsnsnsns : " << answer << endl;
    return answer;
}

int main() {
    cout << "ans : " << solution("25,000,00");

    return 0;
}