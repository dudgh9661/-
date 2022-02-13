// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <map>

using namespace std;
string ans = "";
bool pruning(string s) {
    bool allUpper = true;
    bool allLower = true;
    for (auto ch : s) {
        if (islower(ch)) allUpper = false;
        else if (isupper(ch)) allLower = false;
    }

    if (allUpper || allLower || s.size() == 1) return true;
    return false;
}
bool isBalanced(string s) {
    cout << "test String is " << s << endl;
    if (pruning(s)) {
        cout << "prune : " << s << endl;
        return false;
    }

    map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]] = 1;
    }

    for (auto p : mp) {
        char target = p.first;
        if (isupper(target)) {
            if (mp.find((char)tolower(target)) == mp.end()) return false;
        }
        else if (islower(target)) {
            cout << target << " -> " << (char)toupper(target) << endl;
            if (mp.find((char)toupper(target)) == mp.end()) return false;
        }
    }

    return true;
}

int solution(string &S) {
    // 가장 짧은 balanced fragment를 반환해라
    // 만약 없으면, return -1
    int MIN = 1e9;

    for (int i = 0; i < S.size(); i++) {
        string str = "";
        for (int j = i; j < S.size(); j++) {
            str.push_back(S[j]);
            if (isBalanced(str)) {
                cout << "balanced str : " << str << endl;
                MIN = min(MIN, (int)str.size());
                ans = str;
//                return str.size();
            }
        }
    }

    if (MIN == 1e9) return -1;
    else  {
        cout << "ans : " << ans << endl;
        return MIN;
    }
}

int main() {
    string s = "ABaabbb";
    cout << "sol : " << solution(s);
}
