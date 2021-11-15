#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<int>> bus; // 버스도착시간, 탑승 가능 인원
vector<int> crews; // 크루 도착 시간
bool visited[2000] = { false };

pair<int, int> split(string str) {
    int pos = str.find(':');
    int t = stoi(str.substr(0, pos));
    int m = stoi(str.substr(pos+1,-1));
    return {t,m};
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

void init(int n, int t, int m, vector<string> timetable) {
    int tm = 540;
    // set bus stop time
    for (int i = 0; i < n; i++) {
        bus.insert({tm,{}});
        tm += t;
    }

    // set arrive time of crew
    for (auto s : timetable) {
        auto p = split(s);
        tm = p.first * 60 + p.second;
        crews.push_back(tm);
    }
    sort(crews.begin(), crews.end(), less<>());

    for (auto itr = bus.begin(); itr != bus.end(); itr++) {
        int size = m;
        for (int i = 0; i < crews.size(); i++) {
            if (visited[i]) continue;
            if (itr->first >= crews[i]) {
                itr->second.push_back(crews[i]);
                size--;
                visited[i] = true;
                if (size <= 0) break;
            }
        }
    }
}

void Print() {
    for (auto itr = bus.begin(); itr != bus.end(); itr++) {
        cout << itr->first << " => ";
        for (int i = 0; i < itr->second.size(); i++) {
            cout << itr->second[i] << " ";
        }
        cout << endl;
    }
}
string sol(int m) {
    Print();
    int ans = -1;
    auto itr = bus.end();
    itr--;
    if (itr->second.size() < m) ans = itr->first;
    else {
        ans = *max_element(itr->second.begin(), itr->second.end());
        ans--;
    }

    string answer = "";
    if (ans == 0) answer = "00:00";
    else {
        string tm, mi;
        int t = ans / 60;
        int m = ans % 60;
        if (t < 10) tm = "0" + to_string(t);
        else tm = to_string(t);
        if (m < 10) mi = "0" + to_string(m);
        else mi = to_string(m);

        answer = tm + ":" + mi;
    }
    cout << "answer : " << answer << endl;
    return answer;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    init(n,t,m, timetable);
    answer = sol(m);
    return answer;
}

int main() {
//    solution(1,1,4,{"09:00", "09:00", "09:00", "08:58"});
//    solution(1,1,5,{"00:01", "00:01", "00:01", "00:01", "00:01"});
//    solution(2,10,2,{"09:10", "09:09", "08:00"});
//    solution(2,1,2, {"09:00", "09:00", "09:00", "09:00"});
    solution(1,1,5,{"08:00", "08:01", "08:02", "08:03"});
    return 0;
}
