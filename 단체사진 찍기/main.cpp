#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int ans = 0;

char friends1[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
vector<char> vec;
bool visited[8] = { false };

struct INFO {
    char x, y;
    char oper;
    int dist;
};

vector<INFO> infoVec;

vector<INFO> split(vector<string> data) {
    vector<INFO> tmp;
    for (int i = 0; i < data.size(); i++) {
        INFO info = {data[i][0], data[i][2], data[i][3], data[i][4]-'0'};
        tmp.push_back(info);
    }
    
    return tmp;
}


bool check(INFO info, vector<char>::iterator itr) {
    if (itr == vec.end()) return true;
    int xIdx = vec.size() - 1;
    int yIdx = itr - vec.begin();
    char oper = info.oper;
    int dist = abs(xIdx - yIdx);
    
    if (oper == '=') {
        if (dist == info.dist) return true;
    } else if (oper == '<') {
        if (dist < info.dist) return true;
    } else if (oper == '>') {
        if (dist > info.dist) return true;
    }
    
    return false;    
}
bool isCan(char a) {
    INFO info;
    vector<char>::iterator itr;
    bool flag = false;
    // N~F=0
    for (auto v : infoVec) {
        if (v.x == a) { // base N
            info = v;
            itr = find(vec.begin(), vec.end(), info.y);
            flag = check(info, itr);
            if (!flag) return false;
        } else if (v.y == a) { // base F
            info = v;
            itr = find(vec.begin(), vec.end(), info.x);
            flag = check(info, itr);
            if (!flag) return false;
        }
    }
    
    return flag;
}

bool inCondition(char ch) {
    for (auto v : infoVec) {
        if (ch == v.x || ch == v.y) return true;
    }
    return false;
}

void DFS() {
    if (vec.size() == 8) {
        ans++;
        return;
    }
    
    for (int i = 0; i < 8; i++) {
        if (visited[i]) continue;
        if (inCondition(friends1[i])) {
            if (!isCan(friends1[i])) {
                continue;
            }
        }
        visited[i] = true;
        vec.push_back(friends1[i]);
        
        DFS();
        
        visited[i] = false;
        vec.pop_back();
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    ans = 0;
    infoVec = split(data); // condition vector
    // for (auto v : infoVec) {
    //     cout << v.x << v.y << v.oper << v.dist << endl;
    // }
    DFS();
    // cout << "ans : " << ans << endl;
    answer = ans;
    return answer;
}
