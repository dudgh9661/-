#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
 * 말버릇 패턴 : 문자 데이터에서 가장 많이 등장하는 길이 1이상의 패턴
 *
 * 제약 사항
 *  1. 패턴은 '대소문자를 구분하지 않는다'. 즉, 'abc' == 'aBc'
 *  2. 가장 많이 등장한 패턴이 '여러개' 일 경우, 그러한 패턴을 '모두 삭제'한다.
 */

unordered_map<string, int> mp;
unordered_set<string> st;

void initSet(string call) {
    for (int i = 0; i < call.length(); i++) {
        char ch = call[i];
        string result;
        result = ch;
        for (int j = i+1; j < call.length(); j++) {
            st.insert(result);
            result.push_back(call[j]);
        }
    }
}

bool cmp(pair<string, int> p, pair<string,int> p2) {
    if (p.second == p2.second) {
        return p.first.length() > p2.first.length();
    }

    return p.second > p2.second;
}

int getCnt(string call, string pattern) {
    int cnt = 0;
    int start = 0;
    int pos = call.find(pattern, start);
    if (pos == string::npos) return 0;
    cnt++;

    while (true) {
        start = pos + pattern.length();
        pos = call.find(pattern, start);
        if (pos == string::npos) break;
        cnt++;
    }
    return cnt;
}

void initMap(string call) {
    for (auto pattern : st) {
        mp[pattern] = getCnt(call, pattern);
    }
}

string getDeletePattern(string call, vector<string> pattern) {
    string tmpCall = call;
    transform(tmpCall.begin(), tmpCall.end(), tmpCall.begin(), ::tolower);

    for (auto p : pattern) {
        while (true) {
            int pos = tmpCall.find(p);
            if (pos == string::npos) break;
            call.erase(pos, p.length());
            tmpCall.erase(pos, p.length());
//            cout << "origin call : " << call << endl;
//            cout << "tmpCall : " << tmpCall << endl;
        }
    }

    return call;
}

string solution(string call) {
    string answer = "";
    string callToLower = call; // 원본 복사
    transform(callToLower.begin(), callToLower.end(), callToLower.begin(), ::tolower); // 소문자로 변환
    initSet(callToLower);
    initMap(callToLower);

    vector<pair<string, int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), cmp);

    int maxCnt = vec[0].second;
    int maxLen = vec[0].first.length();

    vector<string> pattern;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].second < maxCnt || vec[i].first.length() < maxLen) break;
//        cout << "pattern : " << vec[i].first << endl;
        pattern.push_back(vec[i].first);
    }

    answer = getDeletePattern(call, pattern);
    return answer;
}

int main() {
//    vector<string> tmp;
//    tmp.push_back("abc");
//    getDeletePattern("abcabcdefabc", tmp);
//    cout << getCnt("abcabcdefabc", "abc");
    cout << solution("ABCabcA");

    return 0;
}
