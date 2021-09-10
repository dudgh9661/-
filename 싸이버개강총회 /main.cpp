#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Time {
    int hour;
    int min;
};

Time split(string &str) {
    int start = 0;
    int pos = str.find(':');
    string hour = str.substr(start, pos - start);
    string min = str.substr(pos + 1, -1);

    Time t = {stoi(hour), stoi(min)};
    return t;
}

multimap<string, Time> mp;
vector<Time> vec; // start, end, stream
map<string,bool> visited;

void init() {
    string str;
    for(int i = 0; i < 3; i++) {
        cin >> str;
        vec.push_back(split(str));
    }

    string t, id;
    while (cin >> t >> id) {
        mp.insert({id,split(t)});
        visited[id] = false;
    }
}

bool inStartRange(Time t) {
    Time start = vec[0];
    int startTime = start.hour * 60 + start.min;
    int tTime = t.hour * 60 + t.min;

    if ( tTime <= startTime ) return true;
    else return false;
}

bool inEndRange(Time t) {
    Time end = vec[1];
    int endTime = end.hour * 60 + end.min;

    Time stream = vec[2];
    int streamTime = stream.hour * 60 + stream.min;

    int tTime = t.hour * 60 + t.min;

    if ( endTime <= tTime && tTime <= streamTime) return true;
    else return false;
}

bool isParticipate(string id) {
    bool check[2] = { false };

    for(auto itr = mp.lower_bound(id); itr != mp.upper_bound(id); itr++) {
        if (inStartRange(itr->second)) {
            check[0] = true;
        } else if (inEndRange(itr->second)) {
            check[1] = true;
        }

        if (check[0] && check[1]) return true;
    }

    return false;
}

int sol() {
    int cnt = 0;
    if (mp.empty() ) return cnt;
    for(auto p : mp) {
        if (visited[p.first]) continue;
        visited[p.first] = true;
        if (mp.count(p.first) < 2 ) continue;

        if (isParticipate(p.first)) {
            cnt++;
        }
    }

    return cnt;
}
int main() {
    init();
//    for(auto p : mp) {
//        cout << p.first << "  " << p.second.hour << " :  " << p.second.min << endl;
//    }
    cout << sol();
    return 0;
}