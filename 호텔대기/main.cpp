#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// queue<int> que;
vector<int> vec; //대기자 명단
bool reserv[500005] = { false };

vector<int> solution(vector<vector<int>> customer, int K) {
    vector<int> answer;
    vector<int> test{1,3};

    for(int i = 0; i < customer.size(); i++) {
        int cus = customer[i][0];
        int order = customer[i][1];

        if( order == 1 ) { //예약한 경우,
            if( K > 0 ) {
                reserv[cus] = true;
                K--;
            } else if ( K <= 0 ) {
                vec.push_back(cus);
            }
        }

        else if ( order == 0 ) {
            if( reserv[cus] ) {
                reserv[cus] = false;
                K++;
                if( !vec.empty() ) {
                    reserv[vec[0]] = true;
                    cout << " pre : " << vec[0] << endl;
                    vec.erase(vec.begin());
                    cout << " post : " << vec[0];
                    K--;
                }
            } else if ( !reserv[cus] ) {
                for(int itr = 0; itr < vec.size(); itr++)  {
                    if( cus == vec[itr] ) vec.erase(vec.begin()+itr);
                }
            }
        }
    }



    for(int i = 1; i <= 50000; i++) {
        if( reserv[i] ) {
             cout << i << " ";
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end(), less<>());
    return answer;
}

int main() {
    vector<int> test{1,2,3};
    for(auto itr = test.begin(); itr < test.end(); itr++) {
        cout << *itr << " ";
//        if( *itr == 3 ) {
//            test.erase(itr);
//        }
    }
    //[[1,1],[2,1],[3,1],[2,0],[2,1]]
    //{4, 1},{3, 1}, {2, 1}, {4, 0}, {1, 1}, {1,0}, {4,1},{4,0}}

//    solution({{1,1},{2,1},{3,1},{3,0}}, 1);
}