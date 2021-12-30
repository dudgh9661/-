#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> stoneCnt;
string ans = "-1";
bool flag = false;

bool canSubtract(int idx) {
    for (int i = 0; i < stoneCnt.size(); ++i) {
        if (i == idx) continue;
        if (stoneCnt[i] - 1 < 0) return false;
    }
    return true;
}

bool isK(int k) {
    int size = stoneCnt.size();
    int zero = count(stoneCnt.begin(), stoneCnt.end(), 0);
    int kCnt = count(stoneCnt.begin(), stoneCnt.end(), k);
//    for (int i = 0; i < stoneCnt.size(); ++i) {
//        if (stoneCnt[i] == 0 ) zero++;
//        else if (stoneCnt[i] == k) {
//            kCnt++;
//            if (kCnt > 1) return false;
//        }
//    }
    if (kCnt == 1 && zero == size - 1) return true;
    return false;
}

void doSubstract(int idx) {
    for (int i = 0; i < stoneCnt.size(); i++) {
        if (i == idx) stoneCnt[i]++;
        else {
            stoneCnt[i]--;
        }
    }
}

void doReturn(int idx) {
    for (int i = 0; i < stoneCnt.size(); i++) {
        if (i == idx) stoneCnt[i]--;
        else {
            stoneCnt[i]++;
        }
    }
}
void DFS(int k, string strIdx) {
    if (isK(k)) {
        ans = strIdx;
        flag = true;
        return;
    }

    for (int i = stoneCnt.size()-1; i >= 0; i--) {
        if (!canSubtract(i)) continue;
        doSubstract(i);
        strIdx.append(to_string(i));

        DFS(k, strIdx);
        if (flag) return;
        strIdx.pop_back();
        doReturn(i);
    }
}
string solution(vector<int> stones, int k) {
    string answer = "";
    int MIN = *min_element(stones.begin(), stones.end());
    int MAX = *max_element(stones.begin(), stones.end());
    if (MAX + MIN < k ) return "-1";
    stoneCnt = stones;
    DFS(k, "");
    answer = ans;

    return answer;
}

int main() {
    cout << solution({1,3,2}, 3);
    return 0;
}
