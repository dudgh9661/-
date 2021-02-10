#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int limit = -1;


int dp[1000] = { -1 }; //0 is dummy
vector<int> vec;
vector<vector<int>> answer;
vector<int> input;
void init() { //this is test.
    cin >> T;
    int a;
    for(int i = 0; i < T; i++) {
        cin >> a;
        input.push_back(a);
    }
    fill(dp, dp+1000, -1);
    dp[0] = 0; dp[1] = 1;
}

int Fibo(int n) {
    if( dp[n] != -1 ) //저장된 값이 있다면,
        return dp[n];
    else { //저장된 값이 없다면,
        dp[n] = Fibo(n-1)  + Fibo(n-2);
        return dp[n];
    }
}

void findLimit(int testCase) {
//    int MAX = *max_element(input.begin(), input.end());
    int idx = 0;
    while(1) {
        Fibo(idx);
        if( testCase <  dp[idx]) {
            idx--;
            break;
        } else if ( testCase == dp[idx] ) {
            break;
        } else idx++;
    }
    limit = idx;
}
void greedy(int testCase) {
    //제일 큰거에서부터 뺀다
    int cur = testCase;
    int idx = limit;
    while(true) {
        if( cur >= dp[idx] ) {
            cur -= dp[idx];
            vec.push_back(dp[idx]);
            idx--;
        } else idx--;

        if( cur == 0 ) break;
    }
    answer.push_back(vec);
    vec.clear();
    vec.resize(0);
}

void answerPrint() {
    for(int i = 0; i < answer.size(); i++) {
        for(int j = answer[i].size()-1; j >= 0; j--) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    init();
//    findLimit(input[0]);
//    greedy(input[0]);
//    answerPrint();
    for(int i = 0; i < T; i++) {
        findLimit(input[i]);
        greedy(input[i]);
    }
    answerPrint();

    return 0;
}
