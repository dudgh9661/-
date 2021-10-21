#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string A = "{}";
string B = "[]";
string C = "()";
vector<string> vec= {"{}","[]","()"};
// s를 회전시키는 함수
string moveLeft(string s) {
    char ch = s[0];
    for (int i = 0; i < s.length()-1; i++) {
        s[i] = s[i+1];
    }
    s[s.length()-1] = ch;
    return s;
}
// 괄호를 알파벳으로 변경
string toAlpha(string s) {
    for (int i = 0; i < vec.size(); i++) {
        if (s.find(vec[i]) == string::npos) {
            // cout << "break!!" << endl;
            continue;
        }
        // cout << "find string : " << vec[i] << endl;
        s.replace(s.find(vec[i]), vec[i].length(), "X");
        // break;
    }
    // cout << "변환 후 문자열 : " << s << endl;
    return s;
}

string deleteX(string s) {
    s.erase(remove(s.begin(), s.end(), 'X'), s.end());
    // cout << "지우고 남은 문자열 : " << s << endl;
    return s;
}


bool sol(string s) {
    // 삭제 전 == 삭제 후 이면 false
    string result = deleteX(toAlpha(s));
    
    while(true) {
        // cout << endl << "while문 집입" << endl;
        string res2 = deleteX(toAlpha(result));
        if (result == res2) {
            break;
        } else result = res2;
    }
    if (result.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    string mvS = s;
    for(int i = 0; i < s.length(); i++) {
        // cout << "체크할 문자 : " << mvS << endl;        
        if (sol(mvS)) {
            answer++;
        }
        mvS = moveLeft(mvS);
        cout << endl;
        
    }
    return answer;
}
