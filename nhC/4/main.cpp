#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int answer = 0;

unordered_map<string, int> mp; // 고객 ID, 지급받은 쿠폰 수
// 하루에 물품을 여러번 구매한 고객 -> 하루에 최대 1장만 할인 쿠폰을 받을 수 있다.

set<string> split(string list) {
    set<string> resSet;
    vector<string> tmp;

    int start = 0;
    int pos = list.find(" ");
    string res = list.substr(start, pos - start);
    tmp.push_back(res);

    while (pos != string::npos) {
        start = pos + 1;
        pos = list.find(" ", start);
        res = list.substr(start, pos - start);
        if (res.empty()) break;
        tmp.push_back(res);
    }

    for (auto str : tmp) resSet.insert(str);
    return resSet;
}

void giveCoupon(set<string> st, int k) {
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        if (mp[*itr] < k) {
            mp[*itr]++;
            answer++;
        }
    }
}
int solution(vector<string> id_list, int k) {
    for (int i = 0; i < id_list.size(); i++) {
        set<string> st = split(id_list[i]);
        giveCoupon(st, k);

    }

    for (auto p : mp) {
        cout << p.first << " : " << p.second << endl;
    }

    cout << "ansewr : " << answer << endl;
    return answer;
}

int main() {

    solution({"A B C D", "A D", "A B D", "B D"}, 2);
    return 0;
}