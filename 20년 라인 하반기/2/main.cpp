#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

deque<int> dq;
vector<int> tmp;
vector<int> answer;
bool visit[300000] = { false };
void init(vector<int> ball) {
    for(int i = 0; i < ball.size(); i++) {
        dq.push_back(ball[i]);
    }
}

bool isPop(int pop) {
    int frontDq = dq.front();
    int backDq = dq.back();

    if( pop == frontDq ) {
        answer.push_back(pop);
        dq.pop_front();
        return true;
    } else if ( pop == backDq ) {
        answer.push_back(pop);
        dq.pop_back();
        return true;
    } else {
        return false;
    }
}
void popBall(vector<int> order) {
    int idx = 0;

    while ( answer.size() != order.size() ) {
        int flag = 0;
        if( tmp.size() != 0 ) {

            for(auto itr = tmp.begin(); itr != tmp.end(); itr++) {

                if( isPop(*itr) ) {
                    tmp.erase(itr);
                    cout << " *itr : " << *itr << endl;
//                    flag = 1;
//                    break;
                }
            }
//            if( flag == 1) continue;
        }
                    cout << "hi" << endl;
        int num = order[idx++];
        cout << " num : " << num << endl;
        if ( !isPop(num) ) {
//            cout << "not in : " << num << endl;
            tmp.push_back(num);
        }
    }
}


void Print() {
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " " << endl;
    }
}
vector<int> solution(vector<int> ball, vector<int> order) {
    init(ball);
    popBall(order);
    Print();

    return answer;
}

int main() {
    vector<int> b{11, 2, 9, 13, 24};
    vector<int> o{9, 2, 13, 24, 11};
    //{1, 2, 3, 4, 5, 6}
    //{6, 2, 5, 1, 4, 3}

    //{11, 2, 9, 13, 24}
    //{9, 2, 13, 24, 11}
    solution(b,o);
    return 0;
}