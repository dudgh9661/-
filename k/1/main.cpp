#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

map<string,int> reportedCnt;
vector<string> stopUser;
map<string,int> mail;

pair<string, string> split(string input) {
    int s = 0;
    int p = input.find(' ');
    string from = input.substr(s, p - s);
    string to = input.substr(p+1, -1);

    return {from, to};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> answer;

    for(string str : id_list) {
        mail[str] = 0;
    }

    // 중복 제거
    sort(report.begin(), report.end(), less<>());
    report.erase(unique(report.begin(), report.end()), report.end());
    for(string str : report) {
        pair<string, string> info = split(str);
        string from = info.first;
        string to = info.second;
        reportedCnt[to]++; //신고당한 횟수를 저장한다.
    }

    for (auto info : reportedCnt) {
        string user = info.first;
        int cnt = info.second;
        if ( cnt >= k ) {
            stopUser.push_back(user);
        }
    }

    //정지된 유저를 신고한 사람을 찾고, 이메일을 보내준다.
    for(string str : report) {
        pair<string, string> info = split(str);
        string from = info.first;
        string to = info.second;

        for (string stop : stopUser) {
            if ( to == stop ) {
                mail[from]++;
            }
        }
    }

    for( string id : id_list) {
        answer.push_back(mail[id]);
    }

//    for(auto info : mail) {
//        cout << info.first << " : " << info.second << endl;
//    }
//
//    for (int n : answer) {
//        cout << n << endl;
//    }

    return answer;
}

int main() {
    // {"muzi", "frodo", "apeach", "neo"},
    // {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}
    // 2
    solution({"muzi", "frodo", "apeach", "neo"},{"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"}, 2);
}
