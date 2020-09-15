#include <string>
#include <vector>
#include <iostream>

using namespace std;
int CNT = 0;

void Print( vector< vector<int> > boxes ) {
    for(int i = 0; i < boxes.size(); i++) {
            cout << boxes[i][0]<< " " << boxes[i][1] << endl;
    }
}

void FIND(vector< vector<int> > &boxes) {
    int cntOfFind = 0;
    for (int box = 0; box < boxes.size() - 1; box++) {

        cntOfFind = 0;
        int flag = 1;


        //다음 물건과 비교
            int first = boxes[box][0];
            int second = boxes[box][1];
//            if( first == second ) break;
//            else {
                for( int nextBox = box + 1; nextBox < boxes.size(); nextBox++) {
                    if( first == second ) break;
                    //다음 박스의 상품들과 비교한다.
                    for(int i = 0; i < 2; i++) {
                        if( first == boxes[nextBox][i]) {
                            int tmp = second;
                            boxes[box][1] = boxes[nextBox][i];
                            boxes[nextBox][i] = tmp;
                            flag = 1;
                            cntOfFind++;
                            break;
                        } else if ( second == boxes[nextBox][i]) {
                            int tmp = first;
                            boxes[box][0] = boxes[nextBox][i];
                            boxes[nextBox][i] = tmp;
                            flag = 1;
                            break;
                        }
                        else flag = 0;
                    }
                    if( flag == 1 ) break; // 하나 찾으면 다음 박스로 넘어간다.

                }
            }
        }

//    }

void count(vector< vector<int> > boxes) {
    for(int i = 0; i < boxes.size(); i++) {
        if( boxes[i][0] != boxes[i][1]) CNT++;
    }
}
int solution(vector< vector<int> > boxes) {
    FIND(boxes);
//    Print(boxes);
    count(boxes);

//    cout << CNT << endl;
    int answer = CNT;
    return answer;
}

int main() {
    //{{1,2}, {2, 1}, {3, 3}, {4, 5}, {5, 6}, {7, 8}}
    //{{1, 2}, {2, 3}, {3, 1}}
    //{{1, 2}, {3, 4}, {5, 6}}
    vector< vector<int> > tmp{{1, 2}, {3, 4}, {1, 2}};
    solution(tmp);
    return 0;
}