#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<int> notUse;

//계산했을 때 notUse가 아닌지 확인하는 함수
bool isUse(int target) {
    if( target < 0 ) return false;
    string str = to_string(target);
    for(int i = 0; i < str.length(); i++) {
        int input = str[i] - '0';
        for(int j = 0; j < notUse.size(); j++) {
            if( input == notUse[j] ) return false;
        }
    }
    return true;
}

int Use(int target) {
    int n = 0;

    int num1 = 0, num2 = 0;
    while(true) {
        if( isUse(target-n) ) {
            return target-n;
        } else if ( isUse(target+n) ) {
            return target+n;
        }
        else n++;
    }
}
int main() {

    int channel = 100;
    int target = 0;
    cin >> target;
    int notCnt = 0;
    cin >> notCnt;

    for(int i = 0; i < notCnt; i++) {
        int input = 0;
        cin >> input;
        notUse.push_back(input);
    }
    if(notUse.size() == 10 ) {
        cout <<  (abs(100-target)) << endl;
        return 0;
    }

    if( target == channel ) {
        cout << "0" << endl;
        return 0;
    }

    int isMin = abs(100-target);

    int res = Use(target);
//    cout << "res : " << Use(target) << endl;
    string str = to_string(res);
    int size = str.size();
    int ans = target - res;
    ans = abs(ans);
    ans += size;
    if( ans > isMin ) ans = isMin;
    cout  << ans << endl;


    return 0;
}
