#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int target;
vector<int> broken;

void init() {
    int itr;
    cin >> target;
    cin >> itr;

    int input;
    for(int i = 0; i < itr; i++) {
        cin >> input;
        broken.push_back(input);
    }
}
bool isPossible(int num) {
    if( num < 0 ) return false;
    string numStr = to_string(num);
    //고장난 버튼을 눌러야하는 경우인지
    for(int i = 0; i < numStr.size(); i++) {
        for (int j = 0; j < broken.size(); j++) {
            if( numStr[i] - '0' == broken[j] ) return false;
        }
    }

    return true;
}
int button() { //10개 버튼이 다 고장나지 않은 경우를 전제로 한다.
    int targetPlus = target;
    int targetMinus = target;

    int cnt = 0;

    while(1) {
        if ( isPossible(targetMinus - cnt) ) {
            return to_string(targetMinus - cnt).size() + abs(targetMinus - cnt - target);
        } else if( isPossible(targetPlus + cnt) ) {
            return to_string(targetPlus+cnt).size() + abs(targetPlus + cnt - target);
        }
        else cnt++;

    }
}
int main() {
    init();
    int answer;
    int _default = abs(target - 100);
    if( _default == 0 ) {
        cout << "0" << endl;
        return 0;
    }
    if( broken.size() == 10 ) {
        answer = _default;
        cout << answer << endl;
        return 0;
    }
    int res = button();
    answer = min(_default, res);
    cout << answer << endl;
    return 0;
}

