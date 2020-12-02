#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
/*
1.현재 가장 앞에 있는 것이 우선순위가 가장 높은 것인가?
    1-1.맞으면 뺀다.
        1-1-1.( 뺀 것에는 인덱스에 표시를 해준다)
    1-2.아니라면 다시 넣는다.
*/
queue< pair<int,int> > que;

void init(vector<int> priorities) {
    for(int i = 0; i < priorities.size(); i++) {
        que.push({priorities[i], i});
    }

}

void Print() {
    for(int i = 0; i < que.size(); i++) {
        cout << que.front().first << "," << que.front().second << endl;
        que.pop();
    }
}
int sol(vector<int> priorities, int target, int location) {

    int CNT = 1;
    // cout << que.size() << endl;
    while( !que.empty() ) {
        int MAX = *max_element(priorities.begin(), priorities.end());
        int maxIdx = max_element(priorities.begin(), priorities.end()) - priorities.begin();

        int front = que.front().first;
        int pos = que.front().second;
        // cout << "cur : " << front << "," << pos << endl;
        que.pop();

        if(front == MAX ) {
            if( pos == location) {
                // cout << " Find target " << target << "," << pos <<endl;
                break;
            } else {
                // cout << " 우선순위가 높지만, 타겟이 아님 : " << front << endl;
                priorities[maxIdx] = -100;
                CNT++;
            }

        } else {
            // cout << " Find target but not pop : " << target << "," << pos << endl;
            que.push({front, pos});
        }
    }

    // cout << "cnt : " << CNT << endl;
    return CNT;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    init(priorities);
    // Print();
    answer = sol(priorities, priorities[location], location);
    return answer;
}