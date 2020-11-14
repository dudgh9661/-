#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

bool visit[10000] = {false };

void init() {
    for(int i = 0; i < 10000; i++)
        visit[i] = false;
}

string TOLOWER(string input) {
    for(int i = 0; i < input.size(); i++) {
        input[i] = tolower(input[i]);
    }

    return input;
}

string DROP(string input) {
    for(int i = 0; i < input.size(); i++) {
        if( !isalpha(input[i]) ) {
            input[i] = ' ';
        }
    }
    return input;
}

string split(string input, char ch) {
    string res;
    int start = 0;
    int pos = input.find(ch);
    string sub = input.substr(start, pos - start);
    res += sub;
    while(pos != string::npos) {
        start = pos + 1;
        pos = input.find(ch, start);
        sub = input.substr(start, pos - start);
        res += sub;
    }
    return res;
}

vector<string> tmp;
vector<string> tmp2;

void two(string str, vector<string> &res) {
    int idx = 0;
    while( idx < str.size() - 1) {
        string sub = str.substr(idx, 2);
        res.push_back(sub);
        idx++;
    }
}

int InterCnt(vector<string> str1,vector<string> str2) {
    int count = 0;
    for(int i = 0; i < str1.size(); i++) {
        if( str1[i] == str2[i] ) count++;
    }

    return count;
}

vector<string> sum;

void SumCnt(vector<string> str1,vector<string> str2) {
    //str1에 같은 원소의 개수가 몇개인지 파악
    int str1Cnt = 0;
    int str2Cnt = 0;
    int res = 0;
    for(int i = 0; i < str1.size(); i++) {
        string element = str1[i];
        for(int j = 0; j < str1.size(); j++) {
            if( element == str1[j] && str1[j] != "check") {
                str1Cnt++;
                str1[j] = "check";
            }
            if( element == str2[j] && str2[j] != "check") {
                str2Cnt++;
                str2[j] = "check";
            }
        }
        if ( str1Cnt > str2Cnt ) {
            res = str1Cnt;
        }
        else {
            res = str2Cnt;
        }

        for( int itr = 0; itr < res; itr++) {
            sum.push_back(element);
        }
        str1Cnt = 0;
        str2Cnt = 0;

    }
    //str2에 그 원소의 개수가 몇개인지 파악
    //더 큰 놈의 개수 만큼 넣음

}
double solution(string str1, string str2) {
    double answer = 0;
    //1. 알파벳 외 문자 제거
    str1 = DROP(str1);
    str2 = DROP(str2);
    //2. 공백 제거
    str1 = split(str1, ' ');
    str2 = split(str2, ' ');
    //2. 모두 소문자로 변경
    str1 = TOLOWER(str1);
    str2 = TOLOWER(str2);
    //3. 2개로 짜르고 벡터에 푸시
    two(str1, tmp);
    two(str2, tmp2);

    SumCnt(tmp, tmp2);
    double sumSize = (double)sum.size();
    double inter = (double)InterCnt(tmp, tmp2);
    cout << "sum : " << sumSize << " " << "inter : " << inter << endl;
    answer = inter / sumSize;
    printf("%lf", answer);
    cout << "answer : " << answer << endl;
    return answer;

}

int main() {
    cout << solution("FRENCH", "FRANCE");
    return 0;
}
