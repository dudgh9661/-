#include <string>
#include <map>
#include <iostream>
#include <unordered_map>
#include <algorithm>

#define finalVal 65536

using namespace std;

unordered_map<string, int> mp1;
unordered_map<string, int> mp2;

//1. 각 문자열을 쪼개서 맵에 저장(영문자로 된 글자만 저장할 것) 
void mapInit(string str, unordered_map<string, int>& mp) {
    // 1. 모두 소문자로 변환
    for (char& ch : str) {
        ch = tolower(ch);
    }
    // 2. 문자열 쪼개기
    for (int i = 0; i < str.size()-1; i++) {
        string subStr = str.substr(i, 2);
        bool notAlpha = false;
        
        for (char ch : subStr) {
            // 영문자로 된 글자 쌍만 유효하다. "ab+" -> ab, b+(이건 버림)
            if (!isalpha(ch)) {
                notAlpha = true;
                break;
            }
        }
        // 모두 알파벳이면 추가
        if (notAlpha == false) mp[subStr]++;
    }
}

int getHap() {
    unordered_map<string, int> mp = mp2;
    
    for (auto p : mp1) {
        if (mp2.find(p.first) != mp2.end()) {
            mp[p.first] = max(p.second, mp2[p.first]);
        } else {
            mp[p.first] = p.second;
        }
    }
    
    int cnt = 0;
    
    for (auto p : mp) {
        cnt += p.second;
    }
    
    return cnt;
}

int getGyo() {
    int cnt = 0;
    
    for (auto p : mp1) {
        if (mp2.find(p.first) != mp2.end()) {            
            cnt += min(p.second, mp2[p.first]);
        }
    }
    return cnt;
}

int solution(string str1, string str2) {
    int answer = 0;
        
    mapInit(str1,mp1);
    mapInit(str2,mp2);
    // 단, 집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의
    if (mp1.empty() && mp2.empty()) return finalVal;
    double gyo = getGyo();
    double hap = getHap();
    answer = (gyo/hap) * finalVal;
    // J(A, B)는 두 집합의 교집합 크기를 두 집합의 합집합 크기로 나눈 값으로 정의
    
    return answer;
}
