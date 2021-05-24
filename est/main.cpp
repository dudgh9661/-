#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool pVisited[10000] = { false };

void pVisitedInit() {
    for(int i = 0; i < 10000; i++) pVisited[i] = false;
}

bool isAllTrueForPElement(string p) {
    for(int i = 0; i < p.size(); i++) {
        if( !pVisited[i] ) return false;
    }
    return true;
}

int getTrueNumberForPElement(string p) {
    int cnt = 0;
    for(int i = 0; i < p.size(); i++) {
        if( pVisited[i] ) cnt++;
    }
    return cnt;
}

bool canMakeP(string ans, int size, string p) {
    vector<string> vec;
    string sub = "";

    for(int i = 0; i < ans.size();) {
        if( i + size > ans.size() ) {
            vec.push_back(ans.substr(i,-1));
            break;
        }
        sub = ans.substr(i, size);
        i += size;
        vec.push_back(sub);
    }

    for(int i = 0; i < vec.size(); i++) {
        if( vec[i] != p ) return false;
    }
    return true;
}

int solution(string p, string s) {
    int answer = 0;
    string ans = "";
    int pIdx = 0;

    for(int i = 0; i < s.size(); i++) {
        //다음으로 나와야할 숫자라면,
        if( s[i] == p[pIdx] ) {
            ans += s[i];
            pVisited[pIdx++] = true;
            if( pIdx >= p.size() ) {
                pVisitedInit();
                pIdx = 0;
            }
        }
        //다음으로 나와야 할 숫자가 아니라면,
        else {
            answer++;
        }
    }
    if( !isAllTrueForPElement(p) ) {
        answer += getTrueNumberForPElement(p);
        for(int i = 0; i < p.size(); i++) {
            if( pVisited[i] ) ans.pop_back();
        }
    }

    if( ans.empty() ) return -1;
    if( !canMakeP(ans, p.size(), p) ) return -1;
    return answer;
}

int main() {
    cout << solution("00","1111111");
    return 0;
}