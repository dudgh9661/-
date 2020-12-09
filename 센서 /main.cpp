#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K;
vector<int> vec;
vector<int> dif;

int main() {

    int sum = 0;

    cin >> N;
    cin >> K;

    int input;
    for(int i = 0; i < N; i++ ) {
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end(), less<>());

    for(int i = 0; i < N - 1 ; i++) {
        int diff = abs(vec[i] - vec[i+1]);
        dif.push_back(diff);
    }

    if( N == 1  ) {

        for(int i = 0; i < dif.size(); i++) {
            sum += dif[i];
        }
        cout << sum << endl;
        return 0;
    }
    else if ( N <= K ) {
        cout << 0 << endl;
        return 0;
    }

    sort(dif.begin(), dif.end(), greater<>());
    int start = K - 1;
    for(int i = start; i < dif.size(); i++) {
        sum += dif[i];
    }
    cout << sum << endl;
    return 0;
}
