#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int END = 0;

queue<int> que;
vector<int> ans;

void Print() {
    queue<int> cq = que;
    while( !cq.empty() ) {
        cout << cq.front()+1 << " ";
        cq.pop();
    }
    cout << endl;
}

void sol(int N, vector<int> &coffee_times) {
    int time = 0;
    while( !que.empty() ) {
        vector<int> tmp;
        int size = que.size();
        for(int i = 0; i < size; i++) {
            int coffeeNum = que.front();
            que.pop();

            coffee_times[coffeeNum]--;
            if( coffee_times[coffeeNum] > 0 ) {
//                if( coffeeNum == 4 )
//                    cout << " 이 시간 : " << coffee_times[coffeeNum] << " , 현재 Time : " << time << " ";
                que.push(coffeeNum);
            }
            else if ( coffee_times[coffeeNum] <= 0 ) {
                tmp.push_back(coffeeNum); //분출
                END++; //다음 커피 인덱싱
                if( END > coffee_times.size() - 1 ) continue; //모든 커피 제조 완료
                else {
                    que.push(END); //다음 커피 삽입
                }
            }
            cout << "que size : " << que.size() << endl;
        }

         cout << " time : " << ++time;
         cout << " / ";
         Print();

        sort(tmp.begin(), tmp.end(), less<>());
        for(int i = 0; i < tmp.size(); i++) {
            ans.push_back(tmp[i]+1);
        }
    }
}

vector<int> solution(int N, vector<int> coffee_times) {
    vector<int> answer;
    END = N - 1;
    for(int i = 0; i < N; i++) {
        que.push(i);
    }

    sol(N, coffee_times);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    answer = ans;
    return answer;
}

int main() {
    solution(3, {4,2,2,5,3});
//    solution(5,{1,1,1,1,1});
//    solution(2, {10,1,2,2,5});
}
