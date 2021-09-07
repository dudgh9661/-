#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;

map<string, int> mp;
vector<pair<string,int>> vec;

bool cmp(const pair<string,int> &a, const pair<string,int> &b) {
    if ( a.second == b.second ) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    cin >> N;
    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        mp[str]++;
    }

    for(auto p : mp) {
        vec.push_back(p);
    }

    sort(vec.begin(),vec.end(), cmp);
    cout << vec[0].first;
    return 0;
}
