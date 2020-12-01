#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int timer = 0;
int cnt = 0;
/*
    무게 조건이 맞을때, 큐에 넣는다.
    시간이 되면 큐에서 뺀다.
*/

queue< pair<int, int> > que;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int curW = 0;
    int pos = 0;

    while(1) {
        timer++;

        //다리에 올라갈 수 없으면,
        //다리를 다 지난 트럭들은 다리에서 내려준다.
        if( que.front().second + bridge_length == timer ) {
            // cout << "pop is " << que.front().first << " time is " << timer << endl;
            curW -= que.front().first; //다리의 무게를 갱신한다.
            que.pop();                  //다리에서 트럭을 내린다.
        }

        if( weight >= curW + truck_weights[pos] ) { //다리에 올라갈 수 있으면,
            if ( pos == truck_weights.size()-1 ) {
                timer += bridge_length;
                cout << "HI" << endl;
                break;
            }

            curW += truck_weights[pos]; //다리의 무게를 갱신하고,
            que.push({truck_weights[pos++], timer}); //다리(큐)에 올린다.ㅋ
        }


    }

    answer = timer;
    return answer;
}