#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int T = 1;
int RT = -1;

int arr[2] = { -1, 1};
int arrNum[2] = {6, 2};

vector<int> topni[4];
vector< pair<int, int> > input;
//회전 정보를 가지고 있는 벡
vector<int> info(4,0);
//출력
void Print() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%d", topni[i][j]);
        }
        printf("\n");
    }
}
//으론쪽 회전
void moveRight(int number){
    int size = topni[number].size();
    int end = topni[number][size-1];
    for(int i = size - 1; i > 0; i--) {
        topni[number][i] = topni[number][i-1];
    }
    topni[number][0] = end;
}

//왼쪽 회전
void moveLeft( int number) {
    int size = topni[number].size();
    int front = topni[number][0];
    for(int i = 0; i < size - 1; i++) {
        topni[number][i] = topni[number][i+1];
    }
    topni[number][size-1] = front;
}
//같은 극인지 확인
bool isSame(int number, int another, int teeth) {
    if( teeth == 2 ) {
        if ( topni[number][2] != topni[another][6] ) {
            return false;
        }
        else if ( topni[number][2] == topni[another][6] ) return true;
    } else if ( teeth == 6 ) {
        if ( topni[number][6] != topni[another][2] ) {
            return false;
        }
        else if ( topni[number][6] == topni[another][2] ) return true;
    }
}
//톱니바퀴 움직임 여부 등록
int regiInfo(int another, int arrowOfNumber) {
    if( arrowOfNumber == T ) {
        info[another] = RT;
        return RT;
    }
    else if ( arrowOfNumber == RT ) {
        info[another] = T;
        return T;
    }
}
void registerMove(int number, int arrowOfNumber) {
    int nextArrow = 0;

    if( number == 0 ) {
        if ( !isSame( 0, 1, 2) ) {
            nextArrow = regiInfo(1, arrowOfNumber);
            //2,3
            if ( !isSame(1, 2, 2)) {
                nextArrow = regiInfo(2, nextArrow);
                if( !isSame( 2, 3, 2)) {
                    regiInfo(3, nextArrow);
                }
            }
        }

        if( arrowOfNumber == T ) moveRight(number);
        else if ( arrowOfNumber == RT ) moveLeft(number);
    }
    else if ( number == 1 ) {
        for(int itr = 0; itr < 2; itr++) {
            int another = 1 + arr[itr];
            if( !isSame(1, another, arrNum[itr]) ) {
                nextArrow = regiInfo(another, arrowOfNumber);
                if( another == 2 ) {
                    if( !isSame(2, 3, 2)) {
                        regiInfo(3, nextArrow);
                    }
                }
            }
        }

        if( arrowOfNumber == T ) moveRight(number);
        else if ( arrowOfNumber == RT ) moveLeft(number);
    }
    else if ( number == 2 ) {
        for(int itr = 0; itr < 2; itr++) {
            int another = 2 + arr[itr];
            if( !isSame(2, another, arrNum[itr]) ) {
//                printf("%d %d\n", number, another);
                nextArrow = regiInfo(another, arrowOfNumber);
                if( another == 1 ) {
                    if( !isSame(1, 0, 6)) {
                        regiInfo(0, nextArrow);
                    }
                }
            }
        }

        if( arrowOfNumber == T ) moveRight(number);
        else if ( arrowOfNumber == RT ) moveLeft(number);
    }
    else if ( number == 3 ) {
        if (!isSame(3, 2, 6)) {
            nextArrow = regiInfo(2, arrowOfNumber);
            //2,3
            if (!isSame(2, 1, 6)) {
                nextArrow = regiInfo(1, nextArrow);
                if (!isSame(1, 0, 6)) {
                    regiInfo(0, nextArrow);
                }
            }
        }

        if (arrowOfNumber == T) moveRight(number);
        else if (arrowOfNumber == RT) moveLeft(number);
    }

}



int main() {
    for(int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < 8; j++) {
            topni[i].push_back( str[j]-'0');
        }
    }

    int k = 0;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        input.push_back( {a,b});
    }

    for( int i = 0; i < input.size(); i++) {
        int number = input[i].first - 1;
        int MV = input[i].second;
//        printf("%d %d\n", number, MV);
        registerMove(number, MV);

        for(int topniNumber = 0; topniNumber < info.size(); topniNumber++) {
            int MVV = info[topniNumber];
//            printf("topniNumber : %d , %d\n", topniNumber, MVV);
            if( MVV == T ) moveRight(topniNumber);
            else if ( MVV == RT ) moveLeft(topniNumber);
        }
//        info.clear();
        for(int j = 0; j < info.size(); j++) {
            info[j] = 0;
        }
    }

    int answer = 0;
    answer += topni[0][0] * 1;
    answer += topni[1][0] * 2;
    answer += topni[2][0] * 4;
    answer += topni[3][0] * 8;

    printf("%d\n", answer);
    return 0;
}