#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 마지막 문자열을 기점으로 하나씩 추가해보고 검사한다.
 */
bool isPal(string str, string str2) {
    if( str == str2 ) {
//        cout << str << "," << str2 << endl;
        return true;
    }
   return false;
}

string rev(string plain) { //abcde -> abcd -> dcba
    string str = plain.substr(0, plain.length()-1);
    reverse(str.begin(), str.end());
    return str;
}

bool allSame(string plain) {
    int cnt = plain.length();
    int tmpCnt = 0;
    char ch = plain[0];
    for(int i = 0; i < plain.length(); i++) {
        if( plain[i] == ch ) {
            tmpCnt++;
        }
    }
    if( cnt == tmpCnt ) return true;
    else return false;
}

bool isComplete(string plain) {
    cout << "in?" << endl;
    if( plain.length() % 2 != 0 ) {
        int idx = plain.length() / 2 + 1;
        string str = plain.substr(0, idx-1);
        string str2 = plain.substr(idx);
        reverse(str2.begin(), str2.end());
        cout << "is complete : " << str << "," << str2 << endl;
        if( str == str2 ) return true;
        else return false;
    }
    int idx = plain.length() / 2;

    string str = plain.substr(0, idx);
    string str2 = plain.substr(idx);

    reverse(str2.begin(), str2.end());
    cout << "is complete : " << str << "," << str2 << endl;
    if( str == str2 ) return true;
    return false;
}
int solution(string plain)
{
//    if( plain.length() == 1 ) return 1;
    if( allSame(plain) ) return plain.length();
    else if( isComplete(plain) )  {
        cout << plain.length();
        return plain.length();
    }
    string origin = plain;
    int answer = 0;
    string revStr = rev(plain);
    cout << "revStr :" << revStr << endl;
    string biggo = plain;

    for(int i = 0; i < revStr.length(); i++ ) {
        biggo += revStr[i]; //abcde + d
        origin += revStr[i];
        reverse(biggo.begin(), biggo.end()); // d + edcba
        if( isPal( origin, biggo) ) { // 똑같다면
            cout << "팰린드롬 문자열 => " << " biggo : " << biggo << " origin : " << origin << " 길이 : " << biggo.length() << endl;
            answer = biggo.length();
            return answer;
        } else {
            cout << "팰린드롬이 아닌 문자열 => " << "biggo : " << biggo << " origin : " << origin << endl;
            reverse(biggo.begin(), biggo.end());
        }
    }

}

int main() {
   solution("abbaa");
}