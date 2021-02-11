#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int T, n;
int ans;

vector<int> start;
vector<int> des;
struct INFO{
    int x,y,r;
};
vector<INFO> planet;

void init() {
    start.clear();
    start.resize(0);
    des.clear();
    des.resize(0);
    planet.clear();
    planet.resize(0);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    start.push_back(a);
    start.push_back(b);
    des.push_back(c);
    des.push_back(d);

    cin >> n;

    int x,y,r;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        INFO info{x,y,r};
        planet.push_back(info);
    }
}

double dist(INFO info, vector<int> vec) {
    return sqrt(pow((info.x - vec[0]),2) + pow(info.y - vec[1], 2));
}
bool isIN(INFO info, vector<int> vec) {
    if( dist(info, vec) > info.r ) return false;
    return true;
}

void sol() {
    for(int i = 0; i < planet.size(); i++) {
        if( isIN(planet[i], start) && isIN(planet[i], des) ) continue;
        else if( isIN(planet[i], start) || isIN(planet[i], des) ) ans++;
    }
}

bool cmp(INFO a, INFO b) {
        return a.r < b.r;
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        init();
        sort(planet.begin(), planet.end(), cmp);
        sol();
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
