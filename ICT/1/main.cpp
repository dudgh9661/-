#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 1. 각 동전의 1원 단위 생산 비용을 구한다.
// 2. 생산 비용이 낮은 순으로 정렬한다.
// 3. 맨 앞부터 최대한 쓸 수 있을 만큼 쓴다.

vector<pair<int,double>> unit;
unordered_map<int, int> mp;

bool cmp(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int solution(int money, vector<int> costs) {
    int answer = 0;

    unit.push_back({1, (double)costs[0]});
    mp.insert({1, costs[0]});

    unit.push_back({5, (double)costs[1] / 5});
    mp.insert({5, costs[1]});

    unit.push_back({10, (double)costs[2] / 10});
    mp.insert({10, costs[2]});

    unit.push_back({50, (double)costs[3] / 50});
    mp.insert({50, costs[3]});

    unit.push_back({100, (double)costs[4] / 100});
    mp.insert({100, costs[4]});

    unit.push_back({500, (double)costs[5] / 500});
    mp.insert({500, costs[5]});

    sort(unit.begin(), unit.end(), cmp);

    for (int i = 0; i < unit.size(); i++) {
        int produceUnit = unit[i].first;
        int produceCost = unit[i].second;

        int mok = money / produceUnit;
        answer += mok * mp[produceUnit];
        money = money % produceUnit;
    }

//    for (auto p : unit) {
//        cout << p.first << " : " << p.second << endl;
//    }
    return answer;
}

int main() {
    cout << solution(500, {1000,1000,1000,100, 100, 500});
    return 0;
}
