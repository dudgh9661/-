#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* 특정 단어로 검색 -> 검색된 상품 개수가 1개 == 고유 검색어
 * 고유 검색어 중 '가장 짧은 고유 검색어 목록'을 구해라.
 * 정렬 조건 : 사전 순서대로 빠른 순, 중복되지 않는다.
 * 제약 조건
 * 1. 공백으로 고유 검색어를 구분한다.
 * 2. 만약 고유 검색어가 없다 => 'None'을 목록에 담아 반환한다.
*/

/*
 *  1. 1개의 상품에서 부분문자열 subStr을 만든다.
 *  2. subStr이 고유한지 검사한다.
 *  3. 고유하다면 고유검색어 목록(map)에 추가한다. (공백 한칸으로 구분)
 *  3-1. 고유검색어가 이미 나왔을 경우, 기존 고유 검색어와 길이를 비교한다.
 *     3-1-1. 만약, 길이가 더 길다면 탐색 종료
 *     3-1-2. 만약, 길이가 같으면 목록에 추가
 *  4. 고유하지 않다면 다음 순서로 넘어간다.
 *  5. 위 과정을, 부분문자열의 길이가 good.lenth()가 될 때까지 반복한다.
*/
set<string> st;

bool isUnique(vector<string>& goods, string good, string keyword) {
    // 1. 해당 키워드로 검색되는 상품이 있는지 확인
    for (int i = 0; i < goods.size(); i++) {
        if (good == goods[i]) continue;
        if (goods[i].find(keyword) != string::npos) {
            return false;
        }
    }
    return true;
}

string findUnique(vector<string>& goods, string good) {
    string res = "";
    set<string> stTmp;
    int MIN = 1e9;
    bool flag = false;
    for (int j = 1; j <= good.size(); j++) {
        for (int i = 0; i < good.size(); i++) {
            string subStr = good.substr(i, j);
//            cout << "keyword : " << subStr << endl;
            if (MIN != 1e9) { // 이미 키워드를 발견했다면,
                if (MIN < subStr.length()) { // 해당 키워드의 길이보다 크면 종료.
                    flag = true;
                    break;
                }
            }
            if (isUnique(goods, good, subStr)) {
                stTmp.insert(subStr);
                MIN = min((int)subStr.length(), MIN);
//                cout << "unique keyword : " + subStr << endl;
            }
        }
        if (flag) break;
    }

    for (auto str : stTmp) {
        res.append(str + " ");
    }
    if (!res.empty()) res.pop_back(); // 마지막 공백 제거
//    cout << "result : " + res << endl;
    return res;
}

vector<string> solution(vector<string> goods) {
    vector<string> answer;
//    cout << findUnique(goods, goods[1]);
    for (int i = 0; i < goods.size(); i++) {
        string good = goods[i];
        string res = findUnique(goods, good);
        if (res.empty()) {
            answer.push_back("None");
        } else {
            cout << res << endl;
//            answer.push_back(res);
        }
    }
//    for (auto s : answer) {
//        cout << s << endl;
//    }
    return answer;
}

int main() {
    solution({"abcdeabcd","cdabe","abce","bcdeab"});
    return 0;
}
