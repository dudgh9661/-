#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> mp;
string result;

void init() {
    mp.insert({"zero", 0});
    mp.insert({"one", 1});
    mp.insert({"two", 2});
    mp.insert({"three", 3});
    mp.insert({"four", 4});
    mp.insert({"five", 5});
    mp.insert({"six", 6});
    mp.insert({"seven", 7});
    mp.insert({"eight", 8});
    mp.insert({"nine", 9});
}
void split(string input) {
    int start = 0;
    string str;
    for(int i = 0; i < input.size(); i++) {
        //1. 인덱스를 하나씩 증가시키면서 문자열을 만들어 나간다.
        //1-1. 만약, 숫자면 건너뛴다.
        if( isdigit(input[i]) ) {
            result += input[i];
            continue;
        }
        str += input[i];
//        cout << i << "index에서 만들어진 문자열은 : " << str << endl;
        //2. 만들어진 문자열이 mp에 있는지 확인 후, 있으면 매핑 시켜준다.
        for(auto itr = mp.begin(); itr != mp.end(); itr++) {
            if( str == itr->first ) {
//                cout << "mapping " << str << " == " << itr->first << endl;
                result += to_string(itr->second);
                str = "";
            }
        }
        //2-1. 없으면 1번을 반복한다.
    }
//    cout << "result : " << result << endl;
}
int solution(string s) {
    int answer = 0;
    init();
    split(s);
    answer = stoi(result);
    return answer;
}
int main() {
    string test = "one4seveneight";
//    int idx = test.find("seven", 0);
//    cout << "idx :" << idx << endl;
//    cout << test.substr(idx, 5);
    cout << solution("one4seveneight") << endl;
}
