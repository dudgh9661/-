#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> lionInfo(11,0);
vector< vector<int> > answerInfo;
vector< vector<int> > lastAns;

int arrowInfo[10000][11] = { 0 };

int apScore = 0;
int MAX = 0;
int getLionScore(vector<int> info, vector<int> _lionInfo) {
    int score = 0;
    for(int i = 0; i < 11; i++) {
        int appeach = info[i];
        int lion = _lionInfo[i];
        if (appeach < lion) {
            score += ( 10 - i );
        }
    }
    return score;
}

int getAppeachScore(vector<int> info, vector<int> _lionInfo) {
    int score = 0;
    for(int i = 0; i < 11; i++) {
        int appeach = info[i];
        int lion = _lionInfo[i];
        if (appeach != 0 && appeach >= lion) {
            score += ( 10 - i );
        }
    }
    return score;
}
void DFS(int shoot, int n, vector<int> info, vector<int> _lionInfo) {
    if (shoot == n) {
        //점수 합산
        int apScore = getAppeachScore(info, _lionInfo);
        int lionScore = getLionScore(info, _lionInfo);
        //어피치랑 비교
        //높으면, 최대값 갱신
        if (apScore < lionScore) {
            MAX = max(lionScore - apScore, MAX);
            answerInfo.push_back(lionInfo);
        }
        return;
    }

    for(int i = 0 ; i < n; i++) {
        lionInfo[i]++;

        DFS(shoot+1, n, info, _lionInfo);

        lionInfo[i]--;
    }
}

void getLastAns(vector<int> info) {
    cout << "MAX : " << MAX << endl;
    for(auto v : answerInfo) {
        int sum = getLionScore(info, v) - getAppeachScore(info, v);
        cout << sum << endl;
        if ( sum == MAX ) {
            cout << "HI";
            lastAns.push_back(v);
        }
    }
}

int getAns() {
    int idx = -1;
    for(int c = 10; c >= 0; c--) {
        int MIN = 1e9;
        int flag = 1;
        for(int r = 0; r < lastAns.size(); r++) {
            if ( MIN > lastAns[r][c] ) {
                MIN = lastAns[r][c];
                idx = r;
            } else if ( MIN == lastAns[r][c]) {
                flag = 0;
                break;
            }
        }
        if ( flag == 1) {
            return idx;
        }
    }
    return idx;
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    DFS(0, n, info, {});
    answerInfo.erase(unique(answerInfo.begin(), answerInfo.end()), answerInfo.end());
    if (answerInfo.empty()) {
        answer.push_back(-1);
        return answer;
    }
    getLastAns(info);
    int idx = getAns();
    answer = answerInfo[idx];
//    for(auto v : answerInfo) {
//        for(int i = 0; i < v.size(); i++) {
//            cout << v[i] << " ";
//        }
//        cout << endl;
//    }
    return answer;
}

int main() {
    //{2,1,1,1,0,0,0,0,0,0,0}
    solution(5, {{2,1,1,1,0,0,0,0,0,0,0}});
    return 0;
}