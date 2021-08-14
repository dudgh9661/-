#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long answer = 0;

long long dp[71] = { 0 };
//vector<int> vec;

void DFS(int cur, int N) {
    if ( cur > N ) return;
    else if ( cur == N ) {
        answer++;
//        for(int i : vec) {
//            cout << i << " ";
//        }
//        cout << endl;
        return;
    }

    for(int i = 1; i <= 3; i++) {
//        vec.push_back(i);
        DFS(cur + i, N);
//        vec.pop_back();
    }
}

void init() {
    DFS(0, 1);
    dp[1] = answer;
    answer = 0;

    DFS(0, 2);
    dp[2] = answer;
    answer = 0;

    DFS(0, 3);
    dp[3] = answer;
    answer = 0;
}
long long sol(int numOfStairs) {
    if ( dp[numOfStairs] > 0 ) return dp[numOfStairs];
    if (dp[numOfStairs] == 0) {
        dp[numOfStairs] = sol(numOfStairs-3) + sol(numOfStairs-2) + sol(numOfStairs-1);
    }
    return dp[numOfStairs];
}
long long solution(int numOfStairs) {
    init();
    answer = sol(numOfStairs);
    return answer;
}

int main() {
    int input = 70;
    cout << solution(input);
    return 0;
}