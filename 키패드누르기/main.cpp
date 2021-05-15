#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string arr[4][3] = {{"1","2","3"},
                 {"4","5","6"},
                 {"7","8","9"},
                 {"*","0","#"}};
typedef struct pos {
    int r, c;
} POS;

POS _left{3,0};
POS _right{3,2};

int getDistance(POS from, POS to) {
    int d = abs(from.r - to.r) + abs(from.c - to.c);
    return d;
}
string getCloser(POS target, string hand) {
    int LD = getDistance(_left, target);
    int RD = getDistance(_right, target);
    if( LD > RD ) return "R";
    else if ( LD < RD ) return "L";
    else {
        if( hand == "right") return "R";
        else return "L";
    }
}

void getRowCol(int &r, int &c, int number) {
    for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if( to_string(number) == arr[i][j] ) {
                    r = i;
                    c = j;
                }
            }
    } 
}

string getFinger(int number, string hand) {
    int r, c;
    if( number == 1 || number == 4 || number == 7 ) {
        getRowCol(r,c, number);
        _left.r = r; 
        _left.c = c;
        return "L";
    }
    else if ( number == 3 || number == 6 || number == 9 ) {
        getRowCol(r,c, number);
        _right.r = r;
        _right.c = c;
        return "R";
    }
    else {
        //find r,c
        getRowCol(r,c, number);        
        POS target{r,c};
        string res = getCloser(target, hand);
        if( res == "L") {
            _left.r = r; 
            _left.c = c;
        } else {
            _right.r = r;
            _right.c = c;
        }
        return res;
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int i = 0; i < numbers.size(); i++) { 
        string res = getFinger(numbers[i], hand);
        // cout << numbers[i] << " : " << res << endl;
        answer += res;
    }
    return answer;
}
