#include <iostream>
#include <vector>

using namespace std;
//max : max(i-locations[i],1)
//min : min(i+locations[i],n)

vector<pair<int,int>> range;
vector<int> fountainRange(100001, 0);

pair<int,int> getRange(vector<int> locations, int pos, int size) {
    int MAX = max(pos-locations[pos-1], 1);
    int MIN = min(pos+locations[pos-1], size);

    if (MAX > MIN ) return {MIN,MAX};
    else return {MAX, MIN};
}

// n 길이의 정원을 커버하기 위해 필요한 최소 분수의 수를 구해라.
int fountainActivation(vector<int> locations) {
    // 1 ~ locations.size()
    range.push_back({-1,-1}); //dummy
    for (int i = 0; i < locations.size(); i++) {
        range.push_back(getRange(locations, i+1, locations.size()));
    }

    for (int i = 1; i <= range.size(); i++) {
        fountainRange[i] = abs(range[i].first - range[i].second);
    }

    return 1;
}

int main() {
    int a = fountainActivation({1,2});
    return 0;
}
