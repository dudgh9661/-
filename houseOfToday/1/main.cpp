#include <iostream>
#include <string>
#include <vector>

using namespace std;

char direction[4] = {'N', 'E', 'S', 'W'};

int getDirectionIdx(char direct) {
    for (int i = 0; i < 4; i++) {
        if (direction[i] == direct) return i;
    }
}

string getDirection(char cur, char next) {
    int curIdx = getDirectionIdx(cur);
    int nextIdx = getDirectionIdx(next);

    if (curIdx == 3 && nextIdx == 0) return "right";
    else if (curIdx == 0 && nextIdx == 3) return "left";

    if (nextIdx - curIdx > 0) return "right";
    else return "left";
}

string getMsg(int curIdx, int dist, string direct) {
    string result = "Time " + to_string(curIdx) + ": Go straight " + to_string(dist*100) + "m and turn " + direct;
    return result;
}

int isChange(string path, int curIdx) {
    for (int i = 1; i <= 5; i++) {
        int nextIdx = curIdx + i;
        if (nextIdx >= path.length()) return -1;
        if (path[curIdx] != path[nextIdx]) {
            return nextIdx;
        }
    }
    return -1;
}

vector<string> solution(string path) {
    vector<string> answer;

    bool printMsg = false;
    char curDirect = 'x';
    for (int i = 0; i < path.length(); i++) {
        if (curDirect != path[i]) printMsg = false;
        curDirect = path[i];

        int nextIdx = isChange(path, i);
        if (nextIdx == -1) continue;
        if (printMsg) continue;

        string direct = getDirection(path[i], path[nextIdx]);
        string msg = getMsg(i, nextIdx - i, direct);
        answer.push_back(msg);
        printMsg = true;
    }

    for (auto s : answer) {
        cout << s << endl;
    }
    return answer;
}

int main()
{
    solution("ENWWWS");
    return 0;
}
