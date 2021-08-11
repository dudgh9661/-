// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num, target;
int cnt = 0;

vector<int> vec;

void init() {
    cin >> num >> target;

    int a;
    for(int i = 0; i < num; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

void sol() {
    int sum = 0;
    int start = 0, end = 0;

    // 맨 끝 이외에 중간 과정에서 end == start가 되는 경우가 있음.
    // 그러므로 start가 vec.size()가 되는 순간 모든 경우의 수에 대한 계산은 끝난
    while ( start < vec.size()) {
        if ( end >= vec.size() ) {
            sum -= vec[start++];
        } else {
            if (target > sum) sum += vec[end++];
            else sum -= vec[start++];
        }

        if ( target == sum ) cnt++;
    }
}

int main()
{
    init();
    sol();
    cout << cnt;
}
