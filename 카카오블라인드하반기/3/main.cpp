#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

vector<string> apply[50000];
vector<string> team[100000];

void Print() {
    for(int i = 0; i < 1; i++ ) {
        for(int j = 0; j < team[i].size(); j++) {
            cout << team[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<string> split(string input, string ch) {
    vector<string> tmp;
    int start = 0;
    int pos = 0;
    pos = input.find(ch);
    string sub = input.substr(start, pos - start);
    tmp.push_back(sub);

    while( pos != string::npos) {
        start = pos + ch.length();
        pos = input.find(ch, start);
        sub = input.substr(start, pos - start);
        tmp.push_back(sub);
    }

    return tmp;
}

string strSplit(string input, string ch) {
    int start = 0;
    int pos = 0;
    pos = input.find(ch);
    string sub = input.substr(start, pos - start);
    string res = "";
    res += sub;

    while( pos != string::npos) {
        start = pos + 1;
        pos = input.find(ch, start);
        sub = input.substr(start, pos - start);
        res += sub;
    }

    return res;
}
void infoParsing(vector<string> info) {
    vector<string> tmp;
    for(int i = 0; i < info.size(); i++) {
        string information = info[i];
        tmp = split(information, " ");
        apply[i] = tmp;
        tmp.clear();
        tmp.resize(0);
    }
}

void queryParsing(vector<string> query) {
    vector<string> tmp;
    for(int i = 0; i < query.size(); i++) {
        string Query = query[i];
        string res = strSplit(Query, " ");
        string sub = " " + res.substr(res.length() - 3, 3);
        res.replace(res.length() - 3, 3, sub);
//        cout << "res : " << res << endl;
//        cout << "sub : " << sub << endl;
        tmp = split(res, "and");
//        cout << tmp << endl;
        team[i] = tmp;
    }
}

int CNT() {
    int cnt = 0;
    for(int header = 0; header < 100000; header++) {
        for (int newid = 0; newid < 50000; newid++) {

            for(int row = 0; row < apply[newid].size(); row++) {
                for(int col = 0; col < 4; col++) {
                    if( team[row][col] == "-") {
                        cnt++;
                    }
                    else if( apply[row][col] == team[row][col] ) {
                        cnt++;
                    }
                }
                int scoreTeam = stoi(team[row][4]);
                cout << "cc" << scoreTeam << endl;
                int scoreApply = stoi(apply[row][4]);
                if( scoreApply == scoreTeam) {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
vector<int> solution(vector<string> info, vector<string> query) {
    infoParsing(info);
    queryParsing(query);

    Print();

    int cnt = CNT();
    if( cnt == 5 ) {
        cout << "ccc" << endl;
    }
    vector<int> answer;
    return answer;
}

int main() {

    solution({"java backend junior pizza 150"}, {"java and backend and junior and pizza 100"});

    return 0;
}