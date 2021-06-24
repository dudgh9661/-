#include <iostream>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int num;
    while( n > 0) {
        num = n % 3;
        n = n / 3;
        if( num == 0 ) n--;
        if( num == 0 ) answer.insert(0, "4");
        else if( num == 1 ) answer.insert(0, to_string(num));
        else if( num == 2 ) answer.insert(0, to_string(num));
    }
//    cout << answer << endl;
    return answer;
}

int main() {
    solution(7);
    return 0;
}

