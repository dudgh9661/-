#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//균형잡힌 문자열 idx 반환
int isBalance(string input) {
    int left = 0;
    int right = 0;
    int idx = 0;

    for(int i = 0; i < input.size(); i++) {
        if( input[i] == '(') right++;
        else if ( input[i] == ')') left++;

        if( right == left ) {
            idx = i;
            break;
        }
    }

    return idx;
}

//올바른 문자열 판단
bool isRight(string input) {
    stack<char> st;

    for(int i = 0; i < input.size(); i++) {
        if( st.empty() ) st.push(input[i]);
        else {
            if( st.size() == 1 && st.top() == ')' ) return false;
            char top = st.top();
            if( top == '(') {
                //짝이 맞는 경우
                if( input[i] == ')' ) st.pop();
                    //짝이 안맞는 경우
                else st.push(input[i]);
            } else if ( top == ')') {
                //짝이 맞는 경우
                if( input[i] == '(') st.pop();
                    //짝이 안맞는 경우
                else st.push(input[i]);
            }
        }
    }

    if( st.empty() ) return true;
    else return false;
}
string REVERSE(string str) {
    string tmp;
    cout << str.substr(1, str.size()-1);
    for(int i = 1; i < str.size()-1; i++) {
        if( str[i] == '(') tmp += ")";
        else if( str[i] == ')') tmp += "(";
    }
    cout << " -> " << tmp << endl;
    return tmp;
}

string sol(string p) {
    if( p.size() == 0 ) return "";
    if( isRight(p) ) return p;
    string u = p.substr(0, isBalance(p) + 1);
    string v = p.substr(isBalance(p)+1, string::npos);

    cout << " u : " << u << endl;
    cout << " v : " << v << endl;

    if( isRight(u) ) {
        u += sol(v);
        return u;
    } else {
        string tmp = "(";
        tmp += sol(v);
        tmp += ")";
        tmp += REVERSE(u);
        return tmp;
    }
}


string solution(string p) {
    string answer = "";
    answer = sol(p);
    cout << answer << endl;
    return answer;
}