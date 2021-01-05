#include <iostream>
#include <vector>
#include <string>

using namespace std;

string input;

//X의 개수에서 4로 나눈 나머지만 B로 변환한다.
void CONVERT(int s, int e) {
    if( s >= e ) {
        return;
    }

    for(int i = s; i <= e; i++) {;
        int cnt = e - s + 1;
        int Acnt = (cnt / 4) * 4;
        for(int A = s; A < s + Acnt; A++) input[A] = 'A';
        for(int B = s+Acnt; B <= e; B++) input[B] = 'B';
    }
}

//.을 기준으로 X의 개수가 짝수가 아니면 만들 수 없음
bool isPossible() {
    int i = 0;
    int cnt = 0;
    while ( i < input.size() ) {
        if( input[i] == 'X') cnt++;
        else if (input[i] == '.' ) {
            if( cnt % 2 != 0 ) return false;
            else cnt = 0;
        }
        i++;
    }
    if( cnt != 0 && cnt % 2 != 0 ) return false;
    return true;
}

int main() {
    cin >> input;

    if( !isPossible() ) {
        cout << -1 << endl;
        return 0;
    }

    int start = 0;
    int comma = 0;
    int flag = 0;

    for(int i = 0; i < input.size(); i++) {
        if( input[i] == '.' ) {
            comma = i;
            CONVERT(start, i-1);
            start = i + 1;
        }
    }

    //XX.XXX에서 마지막 XXX에 대한 처리
    if( start >= comma ) {
        CONVERT(start, input.size()-1);
    }
    cout << input << endl;
    return 0;
}
