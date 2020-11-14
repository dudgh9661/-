#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
vector<string> menu[100];
vector<string> answer;
bool visit[10001] = { false };
map<string, int> mp;

void Print2() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < menu[i].size(); j++) {
            cout << "menu : "<< menu[i][j] << endl;
        }
    }
}
void init( ) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < menu[i].size(); j++)
            menu[i].clear();
    }

    for(int init = 0; init < 10001; init++) {
        visit[init] = false;
    }




}

//input은 손님 1명이 시킨 메뉴, ans는 만들어진 조합, limit은 count, cnt는 코스 종류, itr은 손님 순
void DFS(string input, string ans, int limit, int cnt, int itr) {

    if( cnt == limit ) {
        for(int i = 0; i < ans.size() - 1; i++) {
            if( ans[i] > ans[i+1] ) return;
        }
//        cout << ans << endl;
        menu[itr].push_back(ans);
        return;
    }
    for(int i = 0; i < input.size(); i++) {
        if( visit[i] == false ) {
            string sub = input.substr(i,1);
            ans += sub;
            visit[i] = true;
            DFS(input, ans, limit, cnt+1, itr);
            visit[i] = false;
            ans.pop_back();
        }
    }
}

// 이 함수가 실행되면 menu 2차원 벡터에 각각의 조합이 저장된다.
void setting(vector<string> orders ) {
    for(int i = 0; i < orders.size(); i++) {
        for(int j = 0; j < menu[i].size(); j++) {
//            cout << i << " is size : " << menu[i].size() << endl;
            string setMenu = menu[i][j];
            mp[setMenu] = 0;
//            cout << setMenu << endl;
        }
    }
}

void counting(int MAX, int size, map<string, int> &mp) {
    map<string, int>::iterator itr;
//    printf("isisisisi\n");
    for(itr = mp.begin(); itr != mp.end(); itr++) {
        string setMenu = itr->first;

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < menu[i].size(); j++) {
                if( menu[i][j] == setMenu) mp[setMenu]++;
//                cout << "is...? : " << menu[i][j] << endl;
            }
        }
    }

    for(itr = mp.begin(); itr != mp.end(); itr++) {
        if( MAX < itr->second && itr->second < 30) {
            MAX = itr->second;
        }
//        cout << itr->first << " : adfdasf" << itr->second << endl;
    }

    for(itr = mp.begin(); itr != mp.end(); itr++) {
        if ( MAX >= 2 ) {
            if (MAX == itr->second) {
                answer.push_back(itr->first);
//                cout << "MAX : " << MAX << " and 들어갈 조합은 : " << itr->first << endl;
            }
        }
    }
}

void Print(map<string, int> mp) {
    int cnt = 0;
    for(auto i = mp.begin(); i != mp.end(); i++) {
        cout << cnt <<" Map " << i->first << " : " << i->second << " and size : " << mp.size() << endl;
        cnt++;
    }
}

//vector<string> solution(vector<string> orders, int course) {
vector<string> solution(vector<string> orders, vector<int> course) {
for(int k = 0; k < course.size(); k++) {
    init();
        // menu 2차원 벡터에 조합으로 발생될 수 있는 세트 메뉴들을 저장한다.
        //i부터 모든 손님에 대한 조합이 완성될 떄까지
        for (int i = 0; i < orders.size(); i++) {
            if( orders[i].length() < course[k] ) continue;
            else
                DFS(orders[i], "", course[k], 0, i);
        }
        cout << " 절취선  " << endl;
        // mp을 통해 메뉴에 대한 카운팅 값을 저장하기 위해 세팅한다.
        setting(orders);
        // mp에 각 메뉴에 대한 카운팅을 기록하고, 최대값을 뽑아 answer 벡터에 저장한다.
        cout << " 절취선 22 " << endl;
        counting(-100, orders.size(), mp);
        Print2();
        Print(mp);

//        for (int i = 0; i < answer.size(); i++) {
////            cout << "hi??" << endl;
//            cout << "wtf? " << answer[i] << endl;
//        }

        mp.clear();
        mp.erase(mp.begin(), mp.end());
    }

    return answer;
}


int main() {

    //{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}
    vector<string> ans{"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<int> count{2,3,5};
    solution(ans, count);

    return 0;
}