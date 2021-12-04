#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> recipe; // menu명, 조리시간
vector<string> order;
bool over = false;
int tick = 0;

void setRicipe(vector<string>& recipes) {
    for (auto s : recipes) {
        int pos = s.find(' ');
        string menu = s.substr(0,pos);
        int t = stoi(s.substr(pos+1));
        recipe[menu] = t;
    }
}

void setFireState(vector<pair<int,int>>& fire, int finalIdx) {
    for (auto& p : fire) {
        if (p.first == -1) continue; // empty fire continue
        p.second--;
        if (p.second == 0) { // 조리가 끝난 경우
            if (p.first == finalIdx) { // 마지막 요리 조리가 끝난 경우
                over = true; // over set true, then get time for answer
                return;
            }
            p.first = -1; // set empty fire
        }
    }
}

pair<string, int> getOrder(string order) {
    int pos = order.find(' ');
    string menu = order.substr(0,pos);
    int t = stoi(order.substr(pos+1));
    return {menu, t};
}

int solution(int n, vector<string> recipes, vector<string> orders) {
    int answer = 0;
    order = orders;
    int curIdx = 0;

    vector<pair<int,int>> fire(n, {-1,0}); // n개의 화구를 -1, 0으로 셋팅, {menuIdx, time}

    setRicipe(recipes);
    tick = getOrder(order[0]).second;
    while (true) {
//        cout << "tick : " << tick << endl;
        setFireState(fire, orders.size()-1);
        if (over) {
            answer = tick;
            break;
        }
        // 메뉴 넣기
        if (curIdx >= orders.size()) { // 이미 화구에 다 들어간 경우 continue;
            tick++;
            continue;
        }
        for(auto& p : fire) {
            if (p.first == -1) {
                auto order = getOrder(orders[curIdx]);
                string menu = order.first; // 메뉴명
                int inputTime = order.second;
                if (inputTime > tick) continue;
                int cookTime = recipe[menu]; // 조리시간
                p.first = curIdx;
                p.second = cookTime;
                curIdx++;
            }
        }
        tick++;
    }

    cout << "ans : " << answer << endl;
    return answer;
}

int main() {
    solution(1, 	{"COOKIE 10000"}, {"COOKIE 300000"});
    return 0;
}