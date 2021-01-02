#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int flag = 0;
string number;

vector<string> vec{"1","2","3"};
vector<string> goodNum;

bool even(string num) {

    for(int i = num.size()-1; i > num.size()/2-1; i--) {
        int center = i - 1;
        string right = num.substr(i, string::npos);
        int leftSize = num.size() - i;
        string left = num.substr( center - leftSize + 1, leftSize);

//        cout << "even : " << left << " < " << center << " > " << right << endl;
        if( left == right ) return false;
    }
    return true;

}
bool odd(string num) {
    for(int i = num.size()-1; i > num.size()/2; i--) {
        int center = i - 1;
        string right = num.substr(i, string::npos);
        int leftSize = num.size() - i;
        string left = num.substr( center - leftSize + 1, leftSize);

//        cout << "odd : " << left << " < " << center << " > " << right << endl;
        if( left == right ) return false;
    }
    return true;
}
bool good(string num) {
    if( num[num.size()-1] == num[num.size()-2] ) return false; //case 33, 3 == 3

    int arrow = num.size() % 2;
    if( arrow == 0 ) {
        return even(num);
    } else if ( arrow == 1 ) {
        return odd(num);
    }

}
void DFS(int cnt) {
    if( flag == 1 ) return;
    if( cnt == N ) {
//        cout << "***good : " << number << endl;
        goodNum.push_back(number);
        flag = 1;
        return;
    }

    for(int i = 0; i < vec.size(); i++) {
        number += vec[i];
        if( !good(number) ) {
//            cout << "***bad : " << number << endl;
            number.pop_back();
            continue;
        }

        DFS(cnt + 1);

        number.pop_back();
    }
}

int main() {
    cin >> N;
    DFS(0);

    for(int i = 0; i < goodNum.size(); i++) {
        cout << goodNum[i];
    }
    return 0;
}
