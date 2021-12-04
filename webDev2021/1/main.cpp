#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int,int>> pos = {{1,0}, {0,1},{0,-1}}; // down, right, left

int solution(vector<string> drum) {
    int answer = 0;
    int colLen = drum[0].size();
    int rowLen = drum.size();

    for (int c = 0; c < colLen; c++) {
        int starCnt = 0; // * counting
        int curR = 0, curC = c;

        while (1) {
            char ch = drum[curR][curC];
//            cout << "cur ch : " << ch << endl;
            // case에 맞게 이동
            if (ch == '#') {
                curR = curR + pos[0].first;
                curC = curC + pos[0].second;
            } else if (ch == '>') {
                curR = curR + pos[1].first;
                curC = curC + pos[1].second;
            } else if (ch == '<') {
                curR = curR + pos[2].first;
                curC = curC + pos[2].second;
            } else if (ch == '*') {
                curR = curR + pos[0].first;
                curC = curC + pos[0].second;
                starCnt++;
                if (starCnt == 2) {
//                    cout << "*를 2번 만남 : " << c << endl;
                    break;
                }
            }
            // 이동 후
            if (curR == rowLen) {
//                cout << "바닥에 떨어진 col : " << c << endl;
                answer++;
                break;
            }
        }
    }

    cout << "ans : " << answer << endl;

    return answer;
}

int main() {
    solution({"######", ">#*###", "####*#", "#<#>>#", ">#*#*<", "######"});
    return 0;
}