#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> vecStr;

bool cmp(string a, string b) {
    string str = a + b;
    string str2 = b + a;

    if( str == str2 ) return false;
    return str > str2;
}
string solution(vector<int> numbers) {
    string answer = "";
    int cnt = 0;

    for(int i = 0; i < numbers.size(); i++) {
        vecStr.push_back(to_string(numbers[i]));
    }

    sort(vecStr.begin(), vecStr.end(), cmp);

    for(int i = 0; i < vecStr.size(); i++) {
        answer += vecStr[i];
    }

    for(int i = 0; i < vecStr.size(); i++) {
        if( vecStr[i] == "0" ) cnt++;
    }

    if( cnt == vecStr.size() ) return "0";
    return answer;
}