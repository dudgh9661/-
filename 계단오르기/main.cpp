#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 300
using namespace std;

vector<int> stair;
int DP[MAX] = { 0, };

void solution() {
    for(int i = 3; i < stair.size(); i++) {
        DP[i] = max( DP[i-2] + stair[i], DP[i-3] + stair[i-1] + stair[i]);
//        cout << " i : " << i << " dp : " << DP[i] << endl;
    }
}

void Print() {
    for(int i = 0; i < stair.size(); i++) {
        cout << stair[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        stair.push_back(input);
    };

//    Print();

    DP[0] = stair[0];
    DP[1] = stair[1] + stair[0];
    DP[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    solution();
    cout << DP[stair.size()-1] << endl;



    return 0;
}
