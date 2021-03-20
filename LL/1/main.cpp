#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> vec; //각 직군의 점수
vector<vector<string> > Table;
vector<string> ans;

vector<string> split(string str) {
    vector<string> vec;
    stack<string> st;

    int start = 0;
    int pos = str.find(' ');
    string res = str.substr(start, pos - start);
    st.push(res);

    while( pos != string::npos ) {
        start = pos + 1;
        pos = str.find(' ', start);
        res = str.substr(start, pos - start);
        st.push(res);
    }

    while( !st.empty() ) {
        string tp = st.top();
        vec.push_back(tp);
        st.pop();
    }
    return vec;
}

int returnScore(vector<string> languages, vector<int> preference) {
    int sum = 0;

    for(int i = 0; i < Table.size(); i++) {
        cout << "직군 : " << Table[i][0] << endl;
        for(int j = 0; j < languages.size(); j++) {
            string lan = languages[j];
            for(int k = 0; k < Table[i].size(); k++) {
                if( lan == Table[i][k] ) {
                    cout << lan << " == " << Table[i][k] << endl;
                    sum += preference[j] * (k+1);
                    cout << preference[j] << " * " << k << " = " << sum << endl;
                    break;
                }
            }
        }
        vec.push_back(sum);
        cout << " 점수 : " << sum << endl;
        sum = 0;
    }
    return 0;
}
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    for(int i = 0; i < table.size(); i++) { //쪼개서 하나씩 넣음
        Table.push_back(split(table[i]));
    }

    returnScore(languages, preference);
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    int MAX = *max_element(vec.begin(), vec.end());
    cout << " MAX : " << MAX << endl;
    for(int i = 0; i < vec.size(); i++) {
        if( MAX == vec[i] ) {
            cout << "최대값 : " << Table[i][Table.size()] << endl;
            ans.push_back(Table[i][Table.size()]);
        }
    }
    sort(ans.begin(), ans.end(), less<>());
    cout << "ans : " << ans[0] << endl;

    return answer;
}

int main() {
    //{"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};
    //{"PYTHON", "C++", "SQL"};
    //{7,5,5};
    vector<string> TB = {"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};
    vector<string> LA = {"JAVA", "JAVASCRIPT"};
    vector<int> PF = {7,5};
    solution(TB, LA, PF);

    return 0;
}