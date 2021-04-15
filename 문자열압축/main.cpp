#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector< pair<string,int> > vec;

void sol(string s, int cnt) {
    string pre = s.substr(0, cnt);
    string post;
    int idx = 0;
    vec.push_back({pre, 0});
    
    for(int i = 0; i < s.length();) {
        post = s.substr(i, cnt);
        i += cnt;
        if( pre == post ) {
            vec[idx].second++;
            pre = post;
        } else {
            idx++;
            vec.push_back({post, 1});
            pre = post;
        }
    }
}

int CNT() {
    int res = 0;
    for(int i = 0; i < vec.size(); i++) {
        string str = vec[i].first;
        int strLen = vec[i].second;
        if( strLen >= 2 ) res += str.length() + to_string(strLen).length();
        else res += str.length();
    }
    
    return res;
}

void Print() {
   for(int i = 0; i < vec.size(); i++) {
       cout << vec[i].first << " : " << vec[i].second << endl;
   }
}
int solution(string s) {
    int answer = 0;
    int MIN = 1e9;
    for(int cut = 1; cut <= s.size(); cut++) {
        sol(s, cut);
        MIN = min(MIN, CNT());
        vec.clear();
        vec.resize(0);
    }
    answer = MIN;
    cout << MIN << endl;
    // sol("abcabcdede", 3);
    // Print();
    // cout << CNT() << endl;
    return answer;
}
