#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

string input;

vector<string> vec;
vector<string> tmp;

void init() {
    getline(cin, input);
}

//태그 찾는 함수
int findTag(int start) {
    int end = input.find('>', start);
    string str = input.substr(start, end+1 - start);
    vec.push_back(str);
    return end + 1;
}

void splitNull(string input) {
    string str;
    int start = 0;
    int pos = input.find(" ",start);
    str = input.substr(start, pos - start);
    tmp.push_back(str);

    while( pos != string::npos) {
        start = pos + 1;
        pos = input.find(" ", start);
        str = input.substr(start, pos - start);
        tmp.push_back(str);
    }

    return;
}
//문자열 찾는 함수
int findStr(int start) {
    if ( string::npos != input.find('<', start)) {
        int end = input.find('<', start);
        string str = input.substr(start, end - start); //hg fe
        splitNull(str); //공백으로 쪼갠다
        for(int i = 0; i < tmp.size(); i++) {
            string tmpStr = tmp[i];
            reverse(tmpStr.begin(), tmpStr.end());
            vec.push_back(tmpStr);
            if( i+1 < tmp.size() ) vec.push_back(" ");
        }
        tmp.clear();
        tmp.resize(0);
        return end;
    } else if( string::npos != input.find(' ', start) ) {
        int end = input.find(' ', start);
        string str = input.substr(start, end - start);
        reverse(str.begin(), str.end());

        vec.push_back(str);
        vec.push_back(" ");
        return end + 1;
    }

    //return 되지 않았다는 것은 ' ', '<'를 찾지 못했다는 것이므로, 문자열의 끝에 이르렀다고 볼 수 있다.
    string str = input.substr(start, -1);
    reverse(str.begin(), str.end());
    vec.push_back(str);
    return input.size() + 1;
}

//bool isInTag(string str) {
//    if (str[0] == '<') return
//}

int main() {
    init();

    int start = 0;
    string answer;

    for(int i = 0; i < input.size();) {
        if( input[i] == '<') {
            i = findTag(i);
//            cout << " tag i : " << i << endl;
            continue;
        }
        else i = findStr(i);
    }


    for(int i = 0; i < vec.size(); i++) {
//        cout << vec[i] << endl;
        answer += vec[i];
    }

    cout << answer;
    return 0;
}
