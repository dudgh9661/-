#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
/*
 * 특이사항
 * 1. 아이디 길이 3 <= <= 15
 * 2. 알파벳 소문자, 숫자, 빼기, 밑줄_, 마침표 문자만 사용 가능
 * 3. 단, 마침표(.)는 처음과 끝에 사용할 수 없으며 또한 연속으로 사용할 수 없습니다.
 * 4. -_.~!@#$%^&*()=+[{]}:?,<>/
*/

string EXC = "-_.~!@#$%^&*()=+[{]}:?,<>/";

string first(string input) {
    string str = input;
    for(int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                str[i] = tolower(input[i]);
            }
        }
    }

    return str;
}

string two(string input) {
    vector<int> pos;
    string tmp = "-_.";
    string res;

    for(int i = 0; i < input.length(); i++) {
        if ( !isalpha(input[i]) && !isdigit(input[i]) ) {
            bool flag = false;
            for(int j = 0; j < tmp.length(); j++) {
                if (input[i] == tmp[j]) {
                    flag = true;
                    break;
                }
            }
            if ( flag == false ) {
                pos.push_back(i); // 삭제할 idx 저장
            }
        }
    }
    //remove
    for(int i = 0; i < input.length(); i++) {
        bool flag = false;
        for(int idx : pos) {
            if ( i == idx ) {
                flag = true;
                break;
            }
        }
        if ( flag == false ) res += input[i];
    }
    return res;
}

string three(string input) {
    string res;

    for(int i = 0; i < input.length(); i++) {
        if (input[i] == '.') {
            for (int j = i+1; j < input.length(); j++) {
                if (input[j] == '.' && j == input.length()-1 ) {
                    res += ".";
                    return res;
                }
                else if (input[j] != '.') {
                    res += ".";
                    i = j - 1;
                    break;
                }
            }
        } else if (input[i] != '.') {
            res += input[i];
        }
    }

    return res;
}

string four(string input) {
    while (input[0] == '.') {
        input = input.substr(1, input.length()-1);
    }
    while (input[input.length()-1] == '.') {
        input.pop_back();
    }
    return input;
}

string five(string input) {
    if ( input.empty() ) {
        input.append("a");
    }

    return input;
}

string six(string input) {
    while (input.length() >= 16 ) {
        input.pop_back();
    }

    while (input[input.length()-1] == '.') {
        input.pop_back();
    }

    return input;
}

string seven(string input) {
    if ( input.length() <= 2 ) {
        while ( input.length() <= 2 ) {
            string appe;
            appe = input[input.length()-1];
            input.append(appe);
        }
    }
    return input;
}

string solution(string new_id) {
    string answer = "";
    new_id = first(new_id);
//    cout << new_id << endl;

    new_id = two(new_id);
//    cout << new_id << endl;

    new_id = three(new_id);
//    cout << new_id << endl;

    new_id = four(new_id);
//    cout << new_id << endl;

    new_id = five(new_id);
//    cout << new_id << endl;

    new_id = six(new_id);
//    cout << new_id << endl;

    new_id = seven(new_id);
//    cout << new_id << endl;

    answer = new_id;
    return answer;
}
int main() {
    cout << solution("abcdefghijklmn.p");
    return 0;
}
