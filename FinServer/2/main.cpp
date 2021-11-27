#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 0 ~ i 까지는 오름차순, i ~ arr.size() - 1 까지는 내림차순인 경우
 */
vector<int> vec;
long long ans = 0;
bool check() {
    int maxIdx = max_element(vec.begin(), vec.end()) - vec.begin();
    if (maxIdx == vec.size()-1 || maxIdx == 0) return false;
    for (int i = 0; i < vec.size(); i++) {
        if (i < maxIdx) {
            if (vec[i] < vec[i+1] == false) return false;
        } else if ( i == maxIdx || i == vec.size()-1) continue;
        else { // i > maxIdx
            if (vec[i] > vec[i+1] == false ) return false;
        }
    }
    return true;
}
void DFS(int limit, int cnt, int idx, vector<int> arr) {
    if (limit == cnt) {
        if (check()) {
//            cout << "조건 만족 배열 => ";
//            for (auto e : vec) cout << e << " ";
//            cout << endl;
            ans++;
        }
        return;
    }

    vec.push_back(arr[idx]);
    DFS(limit, cnt + 1, idx + 1, arr);
    vec.pop_back();

}
int solution(vector<int> arr) {
    int answer = 0;
    int maxIdx = max_element(arr.begin(), arr.end()) - arr.begin();
    if (maxIdx == 0 || maxIdx == arr.size()-1) return 0;
    for (int size = 1; size <= arr.size(); size++) {
        for (int start = 0; start < arr.size(); start++) {
            if (arr.size() - start < size) break;
            DFS(size, 0, start, arr);
        }
    }
    // 답은 반드시 10^9 + 7로 나눈 나머지를 리턴
    answer = ans % ((int)pow(10,9) + 7);
    return answer;
}

int main() {
    vector<int> test;
    for(int i = 1; i <= 1000; i++) {
        test.push_back(i);
    }
    cout << solution({5,4,3,2,1});
    return 0;
}