#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> userA;
vector<int> AofBC;
vector<int> userB;
vector<int> BofBC;

vector<int> chargeOfA;
vector<int> chargeOfB;

int LR[5] = {0, 0, 1, 0, -1};
int UD[5] = {0, -1, 0, 1, 0};

void PrintB() {
    cout << "\n" << "sizeB : " << chargeOfB.size() << "\n";
    for(int i = 0; i < chargeOfB.size(); i++) {
        cout << chargeOfB[i] << " ";
    }
}

void PrintA() {
    cout << "\n" << "sizeA : " << chargeOfA.size() << "\n";
    for(int i = 0; i < chargeOfA.size(); i++) {
        cout << chargeOfA[i] << " ";
    }
}
//범위 내에 BC가 있는지 확인
bool inRange(int uX, int uY, int A, vector<int> BC[], vector<int> &ofBC) {
    int flag = 0;
    for(int i = 0; i < A; i++) {
        int BCnum = i; //실제 BC의 숫자는 i+1이다.
        int bX = BC[i][0];
        int bY = BC[i][1];
        int C = BC[i][2];


        int distance = abs(bX - uX) + abs(bY - uY);
        if( distance <= C ) {
            ofBC.push_back(BCnum);
            flag = 1;
        }
        else continue;

    }
    if( flag == 0) return false;
    else if ( flag == 1 ) return true;
}

//비교할 필요 없이 둘 중 하나만 충전 지역에 있을 경우, 가능한 충전 지역 중 최댓값을 찾는다.
void justInput(vector<int> &inputUser, vector<int> ofBC, vector<int> BC[]) {
    int MAX = 0;

    for(int i = 0; i < ofBC.size(); i++) {
        int idx = ofBC[i];
        int power = BC[idx][3];
        MAX = max(power, MAX);
    }
    inputUser.push_back(MAX);
}
//파워값 배열에 삽입하는 함수
pair<int, int> Charger(vector<int> AofBC, vector<int> BofBC, vector<int> BC[] ) {
    int MAX = 0;
    pair<int, int> ab;

        for (int Aitr = 0; Aitr < AofBC.size(); Aitr++) {
            int a = AofBC[Aitr];
            int aPower = BC[a][3];

            for (int Bitr = 0; Bitr < BofBC.size(); Bitr++) {
                int b = BofBC[Bitr];
                int bPower = BC[b][3];

                if (a == b) { //same BC
                    int sum = bPower;
                    if( MAX < sum ) {
                        MAX = sum;
                        ab.first = bPower / 2;
                        ab.second = bPower / 2;
                    }
                }
                else if ( a != b ){ //not same BC
                    int sum = aPower + bPower;
                    if( MAX < sum ) {
                        MAX = sum;
                        ab.first = aPower;
                        ab.second = bPower;
                    }
                }
            }
        }
//    }

    return ab;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TC = 0; cin >> TC;
    for(int tc = 1; tc <= TC; tc++) {
        int M = 0, A = 0;
        cin >> M >> A;

        vector<int> BC[A]; //각 BC의 정보

        for (int i = 0; i < M; i++) {
            int input;
            cin >> input;
            userA.push_back(input);
        }
        for (int i = 0; i < M; i++) {
            int input;
            cin >> input;
            userB.push_back(input);
        }

        for (int i = 0; i < A; i++) {
            int x, y, c, p;
            cin >> x >> y >> c >> p;

            BC[i].push_back(x);
            BC[i].push_back(y);
            BC[i].push_back(c);
            BC[i].push_back(p);
        }

        //move
        pair<int, int> mvA = make_pair(1, 1);
        pair<int, int> mvB = make_pair(10, 10);

        if (inRange(mvA.first, mvA.second, A, BC, AofBC) && inRange(mvB.first, mvB.second, A, BC, BofBC)) {
            pair<int, int> ab = Charger(AofBC, BofBC, BC);
            chargeOfA.push_back(ab.first);
            chargeOfB.push_back(ab.second);
            AofBC.clear();
            BofBC.clear();
        } else if (!inRange(mvA.first, mvA.second, A, BC, AofBC) && inRange(mvB.first, mvB.second, A, BC, BofBC)) {
            chargeOfA.push_back(0);
            justInput(chargeOfB, BofBC, BC);
            AofBC.clear();
            BofBC.clear();

        } else if (!inRange(mvB.first, mvB.second, A, BC, BofBC) && inRange(mvA.first, mvA.second, A, BC, AofBC)) {
            chargeOfB.push_back(0);

            justInput(chargeOfA, AofBC, BC);
            AofBC.clear();
            BofBC.clear();
        } else if (!inRange(mvA.first, mvA.second, A, BC, AofBC) && !inRange(mvB.first, mvB.second, A, BC, BofBC)) {
            chargeOfA.push_back(0);
            chargeOfB.push_back(0);
            AofBC.clear();
            BofBC.clear();
        }

        for (int i = 0; i < userA.size(); i++) {
            int mvAidx = userA[i];
            int mvBidx = userB[i];
            mvA.first = mvA.first + LR[mvAidx];
            mvA.second = mvA.second + UD[mvAidx];


            mvB.first = mvB.first + LR[mvBidx];
            mvB.second = mvB.second + UD[mvBidx];

            //만약에 둘다 BC 범위 내에 속한다면
            if (inRange(mvA.first, mvA.second, A, BC, AofBC) && inRange(mvB.first, mvB.second, A, BC, BofBC)) {
                pair<int, int> ab = Charger(AofBC, BofBC, BC);
//            cout << "i issss : " << i << "\n";
                chargeOfA.push_back(ab.first);
                chargeOfB.push_back(ab.second);
                AofBC.clear();
                BofBC.clear();
            } else if (!inRange(mvA.first, mvA.second, A, BC, AofBC) && inRange(mvB.first, mvB.second, A, BC, BofBC)) {
                chargeOfA.push_back(0);
                justInput(chargeOfB, BofBC, BC);
                AofBC.clear();
                BofBC.clear();

            } else if (!inRange(mvB.first, mvB.second, A, BC, BofBC) && inRange(mvA.first, mvA.second, A, BC, AofBC)) {
                chargeOfB.push_back(0);

                justInput(chargeOfA, AofBC, BC);
//            cout << "i issss : " << i << "\n";
                AofBC.clear();
                BofBC.clear();
            } else if (!inRange(mvA.first, mvA.second, A, BC, AofBC) && !inRange(mvB.first, mvB.second, A, BC, BofBC)) {
                chargeOfA.push_back(0);
                chargeOfB.push_back(0);

                AofBC.clear();
                BofBC.clear();
            }

        }


        int answer = 0;
        for (int i = 0; i < M + 1; i++) {
            answer += chargeOfA[i] + chargeOfB[i];
        }

        cout << "#"<< tc << " " << answer << "\n";

        userA.clear();
        AofBC.clear();
        userB.clear();
        BofBC.clear();

        chargeOfA.clear();
        chargeOfB.clear();
    }
    return 0;
}