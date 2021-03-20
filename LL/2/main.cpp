#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//[1] 알파벳 대문자(A~Z)
bool One(string input) {
    bool res = false;

    for(int i = 0; i < input.size(); i++) {
        if( !isalpha(input[i]) ) continue;

        if( isupper(input[i]) ) {
            res = true;
            break;
        }
    }

    return res;
}
//[2] 알파벳 소문자(a~z)
bool Two(string input) {
    bool res = false;

    for(int i = 0; i < input.size(); i++) {
        if( !isalpha(input[i]) ) {
            continue;
        }
        if( islower(input[i]) ) {
            res = true;
            break;
        }
    }

    return res;
}
//[3] 숫자(0~9)
bool Three(string input) {
    bool res = false;

    for(int i = 0; i < input.size(); i++) {
        if( isdigit(input[i]) ) res = true;
    }

    return res;
}
//[4] 특수문자(~!@#$%^&*)
bool Four(string input) {
    vector<char> vecCh = {'~','!','@','#','$','%','^','&','*'};
    bool res = true;
    int flag;

    for(int i = 0; i < input.size(); i++) {
        flag = 0;
        for( int j = 0; j < vecCh.size(); j++) {
            if( islower(input[i]) || isupper(input[i]) || isdigit(input[i]) ) { //특수문자가 아니면, 패스
                flag = 1;
                continue;
            }
            if( input[i] == vecCh[j] ) {
                flag = 1;
                break;
            }
        }
        if( flag == 0 ) {
            res = false;
            return res;
        }
    }

    return res;
}

bool numTwo(string inp_str) {
    for(int i = 0; i < inp_str.length(); i++) {
        if (isalpha(inp_str[i]) ) {
        }
    }
}

bool numOne(string inp_str) {
    bool res = false;

    int len = inp_str.length();
    if( 8 <= len && len <= 15 ) res = true;

    return res;
}

//3. password는 (2.)에서 명시된 4 종류의 문자 그룹 중에서 3 종류 이상을 포함해야 합니다.
bool numThree(string inp_str) {
    int cnt = 0;
    if( One(inp_str) ) cnt++;
    if( Two(inp_str) ) cnt++;
    if( Three(inp_str) ) cnt++;
    if( Four(inp_str) ) cnt++;

    if( cnt >= 3 ) return true;
    else return false;
}
//4.password에 어떤 문자라도 같은 문자가 4개 이상 연속될 수 없습니다.
bool numFour(string inp_str) {
    for(int i = 0; i+4 < inp_str.length(); i++) {
        int cnt = 1;
        char ch = inp_str[i];

        for(int j = 1; j <= 3; j++) {
            if( ch == inp_str[i+j] ) cnt++;
        }
        if( cnt >= 4) return false;
    }
    return true;
}

//5. password에 어떤 문자라도 같은 문자가 5개 이상 포함될 수 없습니다.
bool numFive(string inp_str) {
    map<char, int> mp;
    for(int i = 0; i < inp_str.size(); i++) {
        mp[inp_str[i]]++;
        if( mp[inp_str[i]] >= 5) return false;
    }

    return true;

}
vector<int> solution(string inp_str) {
    vector<int> answer;
    if( !numOne(inp_str) ) answer.push_back(1);
    if( !numTwo(inp_str) ) answer.push_back(2);
    if( !numThree(inp_str) ) answer.push_back(3);
    if( !numFour(inp_str) ) answer.push_back(4);
    if( !numFive(inp_str) ) answer.push_back(5);

    sort(answer.begin(), answer.end(), less<>());
    if( answer.size() == 0 ) answer.push_back(0);

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
    return answer;
}

int main() {
    string str = "UUUUU";
    solution(str);
    return 0;
}