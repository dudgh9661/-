#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2001
using namespace std;

int answer = -100;

bool visited[MAX] = {false};


void init() {
    for(int i = 0; i <= MAX; i++) {
        visited[i] = false;
    }
}

int newCheck(int start, int end, vector<int> X, vector<int> Y)  {
    int cnt = 0;
    for(int idx = 0; idx < X.size(); idx++) { //배수 관계일 때,
            int resX = X[idx];
            int resY = Y[idx];
            if( resX == 0 || resY == 0 ) continue;

            if( ( (resX / start) == (resY / end) ) == 0 || ( ( start / resX ) == ( end / resY) ) == 0 ) {
                continue;
            }
            if( ( (resX / start) == (resY / end) ) && (resX % start == 0 && resY % end == 0 ) ) {
                cout << "mul : " << resX << resY << endl;
                cnt++;

            } else if( ( ( start / resX ) == ( end / resY) ) && ( start % resX == 0 && end % resY  == 0 ) ) {
                cout << "div : " << resX << resY << endl;
                cnt++;
            }
    }

    return cnt;

}

int solution(vector<int> &X, vector<int> &Y) {

    for(int i = 0; i < X.size(); i++) {
        int x = X[i];
        int y = Y[i];
        if( x == 0 || y == 0 ) continue;
        cout << "기준 : " << x << y << endl;
        int output = newCheck(x,y,X,Y);
        cout << "output : " << output << endl;
        if ( answer < output ) answer = output;
        init();
        cout << endl;
    }

    cout << answer << endl;

}

int main() {
    //1,2,3,1,2 || 2,4,6,5,10

//        vector<int> X{4,4,7,1,2};
//        vector<int> Y{4,4,8,1,2};
    vector<int> X{1,2,3,1,2};
    vector<int> Y{2,4,6,5,10};
//    vector<int> X{1,2000000000};
//    vector<int> Y{1,2000000000};
    solution(X,Y);

    return 0;
}
