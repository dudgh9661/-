#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> vec;
map<string, int> mp;
set<string> st;
set<string> stVec;

int countMenu(string menu, vector<string> orders) {
    int courseCnt = 0;
    for(string order : orders) {
        int cnt = 0;
        for(int i = 0; i < order.length(); i++) {
            for(int j = 0; j < menu.length(); j++) {
                if (menu[j] == order[i]) {
                    cnt++;
                    if (cnt == menu.length()) {
                        courseCnt++;
                        break;
                    }
                }
            }
        }
    }
    return courseCnt;
}

void check(vector<string> orders) {
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        int checkCnt = countMenu(*itr, orders);
        if (checkCnt > 0) {
            mp[*itr] = checkCnt;
        }
    }
}

void DFS(string order, string menu, int start, int cnt, int num) {
    if (cnt == num) {
        st.insert(menu);
        return;
    }

    for(int i = start; i < order.length(); i++) {
        menu += order[i];
        DFS(order, menu, i+1, cnt+1, num);
        menu.pop_back();
    }
}

void getCourse(int MAX, int num) {
    for( auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second == MAX && itr->first.length() == num) {
            vec.push_back(itr->first);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int num : course) {
        for(string order : orders) {
            DFS(order, "", 0, 0, num);
        }
    }

    check(orders);

    for(int num : course) {
        int MAX = 0;
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            if (itr->first.length() == num) {
                MAX = max(MAX, itr->second);
            }
        }
        if ( MAX < 2 ) continue;
        getCourse(MAX, num);
    }

    for(string& str : vec) {
        sort(str.begin(), str.end(), less<>());
    }

    sort(vec.begin(), vec.end(), less<>());

    for(string str : vec) {
        stVec.insert(str);
    }

    for(auto itr = stVec.begin(); itr != stVec.end(); itr++) {
        answer.push_back(*itr);
    }

    for(string str : answer) {
        cout << str << endl;
    }
    return answer;
}

int main() {
    solution({"XYZ", "XWY", "WXA"}, {2,3,4});
//    ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
//  {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}
//    {"XYZ", "XWY", "WXA"}

    return 0;
}