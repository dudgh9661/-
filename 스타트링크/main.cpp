#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int F,S,G,U,D;
int answer = -1;

bool visited[1000001] = { false };

void init() {
    cin >> F >> S >> G >> U >> D;
}

struct cmp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};
void sol() {
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> que; //현재층, 버튼 횟수
    que.push({S, 0});
    visited[S] = true;

    while( !que.empty() ) {
        int curFloor = que.top().first;
        int curCnt = que.top().second;
//        printf("현재층 : %d, 버튼 횟수 : %d\n", curFloor, curCnt);
        que.pop();

        if (curFloor == G) { //해당 층에 도달하면,
            answer = curCnt;
            break;
        } else {
            if (U > 0) {
                if (!visited[curFloor + U] && curFloor + U <= F) {
                    que.push({curFloor + U, curCnt + 1});
                    visited[curFloor + U] = true;
                }
            }
            if (D > 0) {
                if (!visited[curFloor - D] && curFloor - D >= 1) {
                    que.push({curFloor - D, curCnt + 1});
                    visited[curFloor - D] = true;
                }
            }
        }
    }

    if( answer == -1 ) {
        cout << "use the stairs";
    } else {
        cout << answer;
    }
}
int main() {
    init();
    sol();
    return 0;
}
