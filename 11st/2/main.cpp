#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vec;
int MAX = -1;

// 문자는 블락의 시작 또는 끝에만 추가되어질 수 있다.

// 리턴값 : 모든 블락이 동일한 문자길이를 가질 수 있는데 필요한, 추가 문자의 최솟값을 리턴해라.

void split(string &S) {
    int s = 0;
    string str;
    for (int i = 0; i < S.length(); i++) {
        if (S[s] != S[i]) {
            str = S.substr(s, i - s);
            vec.push_back(str);
            MAX = max(MAX, (int)str.length());
//            cout << "str : " << str << endl;
            s = i;
        }
    }
    str = S.substr(s, S.length() - s);
    vec.push_back(str);
    MAX = max(MAX, (int)str.length());
//    cout << "str : " << str << endl;
}

int solution(string &S) {
    split(S);
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += MAX - vec[i].length();
    }

//    cout << " sum : " << sum << endl;
    return sum;
}

int main() {
    string tmp = "";
    for (int i = 0; i < 39999; i++) {
        tmp.push_back('a');
    }
    int ans = solution(tmp);
    cout << "ans : " << ans << endl;
    return 0;

}
