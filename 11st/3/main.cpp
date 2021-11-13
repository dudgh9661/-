#include <iostream>
#include <vector>
#include <map>
#define MAXSize 100000

using namespace std;

map<int, int> mp;

// 배열 안의 숫자인 x가, 정확히 x번 나타나도록 제거하거나 삽입해라.
// 필요한 경우, 모든 요소를 다 삭제해도 된다.

void init(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        mp[A[i]]++;
    }
}
int solution(vector<int> &A) {
    if (A.size() == 1) {
        if (A[0] == 1) return 0;
        else {
            return 1;
        }
    }

    init(A);
    int ans = 0;
    int totalLen = A.size();
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        int x = itr->first;
        int cnt = itr->second;
        int resCnt = 0;
//        int resCnt = min(cnt, abs(x-cnt));
        // test
        int allRemove = cnt;
        int otherRemove = x-cnt;

        // 추가하는 경우
        if (otherRemove > 0) {
            // 추가했을 때 최대 사이즈가 넘어가면, 삭제하는 경우를 택한다.
            if (totalLen + otherRemove > MAXSize) {
                resCnt = allRemove;
                totalLen -= resCnt;
            } else {
                if (allRemove <= otherRemove) {
                    resCnt = allRemove;
                    totalLen -= resCnt;
                } else {
                    resCnt = otherRemove;
                    totalLen += resCnt;
                }
            }
        }
        // 삭제하는 경우
        else {
            resCnt = min(allRemove, abs(otherRemove));
            totalLen -= resCnt;
        }

        ans += resCnt;
    }

    return ans;
}

int main() {
    vector<int> tmp = {};
    for (int i = 0; i < 100000; i++) {
        tmp.push_back(99999);
    }
    cout << "ans : " << solution(tmp);
    return 0;
}
