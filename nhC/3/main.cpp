#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

map<int, map<int, int>> mp; // 1번 수험생, 문제번호, 최대점수
vector<int> ans;
void init(vector<string> logs) {
    for (int i = 0; i < logs.size(); i++) {
        string log = logs[i];
        int person, num, score;

        int start = 0;
        int pos = log.find(' ');
        person = stoi(log.substr(start, pos - start));

        start = pos + 1;
        pos = log.find(' ', start);
        num = stoi(log.substr(start, pos - start));

        start = pos + 1;
        score = stoi(log.substr(start, -1));

        if (mp.find(person)->second.find(num) != mp.find(person)->second.end()) {
            int originNum = mp.find(person)->second[num];
            mp.find(person)->second[num] = max(originNum, score);
        } else {
            mp.insert({person, {num,score}});
//            mp[person].insert({num, score});
        }
    }

//    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
//        cout << itr->first << " ";
//        auto tmp = itr->second;
//        for (auto itr2 = tmp.begin(); itr2 != tmp.end(); itr2++) {
//            cout << itr2->first << " " << itr2->second << endl;
//        }
//        cout << endl;
//    }
}

bool isDuplicate(pair<int, map<int,int>> p1, pair<int, map<int,int>> p2) {
    map<int,int> tmp = p1.second;
    map<int,int> tmp2 = p2.second;
    for (auto itr = tmp.begin(); itr != tmp.end(); itr++) {
        if (tmp2[itr->first] != itr->second) return false;
    }
    return true;
}

void sol() {
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        vector<int> tmpAns;
        if (mp[itr->first].size() < 5) continue;
        int size = mp[itr->first].size();
        tmpAns.push_back(itr->first);

        cout << itr->first << " : " << mp[itr->first].size() << endl;
        for (auto itr2 = mp.begin(); itr2 != mp.end(); itr2++) {
            if (size == mp[itr2->first].size()) {
                pair<int, map<int,int>> p = *itr2;
                if (isDuplicate(*itr, *itr2)) {
                    tmpAns.push_back(itr2->first);
                }
            }
        }
        if (tmpAns.size() > 1) {
            for (auto n : tmpAns) ans.push_back(n);
        }
    }
}
vector<string> solution(vector<string> logs) {
    vector<string> answer;
    init(logs);
    sol();
    ans.erase(ans.begin(), unique(ans.begin(), ans.end()));
    for (auto n : ans) {
        string res = "000" + to_string(n);
        if (res.length() > 4) {
            res = res.substr(0, 4);
        }
        answer.push_back(res);
    }

    if (ans.size() == 0) answer.push_back("None");
    for (auto s : answer) {
        cout << s << endl;
    }
    return answer;
}

int main() {
    solution({"1901 10 50", "1909 10 50"});
    // {"0001 3 95", "0001 5 90", "0001 5 100", "0002 3 95", "0001 7 80", "0001 8 80", "0001 10 90", "0002 10 90", "0002 7 80", "0002 8 80", "0002 5 100", "0003 99 90"}
//    solution({"0001 3 95", "0001 5 90", "0001 5 100", "0002 3 95", "0001 7 80", "0001 8 80", "0001 10 90", "0002 10 90", "0002 7 80", "0002 8 80", "0002 5 100", "0003 99 90"});
    return 0;
}
