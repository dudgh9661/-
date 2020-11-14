#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

bool visit[100001] = { false };


class cmp{
public:
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if ( p1.first == p2.first ) return p1.second > p2.second;
        else return p1.first > p2.first;
    }
};


int BFS(int pos, int target) {

    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > que;
    que.push({0, pos});
    visit[pos] = true;

    while( !que.empty() ) {
        int time = que.top().first;
        int currentPos = que.top().second;
        que.pop();

        if ( target == currentPos ) {
//            cout << " return : " << currentPos << endl;
            return time;
        }

        if( currentPos * 2 < 100001 && !visit[currentPos * 2]  ) {
            que.push({time, currentPos * 2});
            visit[currentPos * 2] = true;
        }
        if ( currentPos + 1 < 100001  && !visit[currentPos + 1] ) {
            que.push({time + 1, currentPos + 1});
            visit[currentPos + 1] = true;
        }
        if ( currentPos - 1 >= 0 && !visit[currentPos - 1]) {
            que.push({time + 1, currentPos - 1});
            visit[currentPos - 1] = true;
        }

    }
}
int main() {
    int pos, target;
    cin >> pos >> target;
    int answer = BFS(pos, target);
    cout << answer << endl;

    return 0;
}
