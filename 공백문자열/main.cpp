#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> vec;

void split(string input ) {
    int start = 0;
    int pos = input.find(" ");
    string res;
    string sub = input.substr(start, pos - start);
    vec.push_back(sub);

    while( pos != string::npos) {
        start = pos + 1;
        pos = input.find(" ", start);
        sub = input.substr(start, pos - start);
        vec.push_back(sub);
    }

    return;
}

vector<int> ans;

void MAX() {
    int m = -10000;
    for(int i = 0; i < vec.size(); i++) {
        int num = stoi(vec[i]);
        if( m < num ) m = num;
    }
    ans.push_back(m);

    m = 10000;
    for(int i = 0; i < vec.size(); i++) {
        int num = stoi(vec[i]);
        if( m > num ) m = num;
    }
    ans.push_back(m);
}
string solution(string s) {
    split(s);
    MAX();
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    string answer = "";
    answer = to_string(ans[1]) + " " + to_string(ans[0]);
    return answer;
}

int main() {
    cout << solution("-1 -2 -3 -4") << endl;
    return 0;
}