#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

set<string> st;

string cutting(string s, int start, int n) {
    string res;
    res = s.substr(start, n);
    return res;
}

bool isPossible(string str) {
    //1. 문자열 사이에 겹치는게 있는지
    for(int i = 0; i < str.size(); i++) {
        for(int j = i+1; j < str.size(); j++) {
            if( str[i] == str[j] ) return false;
        }
    }
    return true;
}

int solution(string s) {
    int answer = 0;

    for(int cut = 1; cut <= s.size(); cut++) {
        for(int start = 0; start < s.size(); start++) {
            if( start + cut > s.size() ) break;
            string res = cutting(s, start, cut);
//            cout << "cutting : " << res << endl;
            if( isPossible(res) ) st.insert(res);
        }
    }

//    for(auto i = st.begin(); i != st.end(); i++) {
//        cout << *i << " ";
//    }

    cout << "ans : " << st.size() << endl;
    return answer;
}

int main() {
    solution("abac");
}