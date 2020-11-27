#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int N;
int assignVal = 9;
long long ans = 0;

vector<string> vecStr;
vector<long long> toInt;

vector<int> alpha(26);
int alphabet[26] = {0};
int alphaIdx[26] = {0}; //앞에서부터 오름차순으로 알파벳의 아스키코드값 저


void init() {
    cin >> N;
    string input;

    fill(alphabet, alphabet+26, -1);
    fill(alphaIdx, alphaIdx+26, -1);

    for(int i = 0; i < N; i++) {
        cin >> input;
        reverse(input.begin(), input.end());
        vecStr.push_back(input);
    }

}

void sol() {
    for(int i = 0; i < vecStr.size(); i++) {
        for(int j = 0; j < vecStr[i].length(); j++) {
            int ten = pow(10, j);
            alpha[vecStr[i][j] % 65] += ten;
        }
    }

    for(int i = 0; i < 26; i++) {
        int maxVal = *max_element(alpha.begin(), alpha.end());
        if( maxVal != 0 ) {
            int maxIdx = max_element(alpha.begin(), alpha.end()) - alpha.begin(); //최대값을 가진 idx 저장
            alpha[maxIdx] = -100;
            alphaIdx[i] = maxIdx;
        } else break;

    }
}

void matching() {
    for(int i = 0; i < 26; i++) {
        if( alphaIdx[i] != -1 ) {
            alphabet[ alphaIdx[i] ] = assignVal--;
        }
    }

    for(int i = 0; i < vecStr.size(); i++) {
        string str;
        for(int j = 0; j < vecStr[i].length(); j++) {
            str += to_string(alphabet[vecStr[i][j] % 65]);

        }
        reverse(str.begin(), str.end());
        toInt.push_back(stoi(str));
    }

    for(int i = 0; i < toInt.size(); i++) {
        ans += toInt[i];
    }
}

int main() {
    init();
    sol();
    matching();

    cout << ans << endl;
    return 0;
}
