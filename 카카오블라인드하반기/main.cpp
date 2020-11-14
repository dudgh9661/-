#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string toLOWER(string input) {
    for(int i = 0; i < input.size(); i++) {
        input[i] = tolower(input[i]);
    }
    return input;
}

string toDELETE( string input ) {
    for(int i = 0; i < input.size(); i++) {
        if( input[i] != '-' && input[i] != '_' && input[i] != '.' && !isdigit(input[i]) && !isalpha(input[i]) ){
            input[i] = ' ';
        }
    }
    return input;
}

string twoComma( string input ) {
    int cnt = 0;
    int idx = 0;

    vector<int> comma;

    for(int i = 0; i < input.size(); i++) {
        if( input[i] == '.' ) {
            if( i + 1 <= input.size() - 1) {
                if( input[i+1] == '.' ) {
                    comma.push_back(i);
                    comma.push_back(i+1);
                    break;
                }
            }
        }

    }

    for(int i = 1; i < comma.size(); i++) {
        input[comma[i]] = ' ';
    }

    return input;
}

string fourtDelete(string input) {
    if( input[0] == '.' ) {
        input[0] = ' ';
    }
    if( input[ input.size() - 1 ] == '.') {
        input[ input.size() - 1 ] = ' ';
    }
    return input;

}

string isNull(string input) {
    if( input.length() == 0 ) {
        input = "a";
    }

    return input;
}

string CUT(string input) {
    if( input.size() >= 16 ) {
        input = input.substr(0, 15);
        if( input[ input.size() - 1 ] == '.')
            input[ input.size() - 1 ] = ' ';
    }

    return input;
}

string addString(string input) {
    if( input.size() <= 2 ) {
        int length = input.size();
        string last = input.substr(length-1, 1);
        while( length < 3 ) {
            input = input + last;
            length = input.size();
        }
    }

    return input;
}

string split (string input) {
    vector<string> sp;
    int start = 0;
    int pos = input.find(" ");
    string sub = input.substr(start, pos - start);
    sp.push_back(sub);
    while( pos != string::npos) {
        start = pos + 1;
        pos = input.find(" ", start);
        sub = input.substr(start, pos - start);
        sp.push_back(sub);
    }

    string ans = "";
    for(int i = 0; i < sp.size(); i++) {
        ans += sp[i];
    }

    return ans;
}

int COUNT( string input ) {
    for(int i = 0; i < input.size(); i++) {
        if( input[i] == '.' ) {
            if( input[i+1] == '.' ) {
                return 1;
            }
        }
    }
    return 0;
}
string solution(string new_id) {
    string res = toLOWER(new_id);
    res = toDELETE(res);
    res = split(res);

    while( COUNT(res) == 1 ) {
        res = twoComma(res);
        res = split(res);
    }
    res = fourtDelete(res);
    res = split(res);
    res = isNull(res);
    res = split(res);
    res = CUT(res);
    res = split(res);
    res = addString(res);
    res = split(res);
    res = split(res);
    string answer = "";
    answer = res;
    return answer;
}

int main() {
//   string answer = twoComma("z-..");
    string answer = solution("abcdefghijklmn.p");
    cout << answer << endl;
    return 0;
}