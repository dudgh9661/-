#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
int N, M = 0;

vector<int> vec;

void init() {
    cin >> N >> M;

    int input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
    }
}

void sol() {
    int s = 0, e = 0;
    int sum = 0;

    while ( s <= e )  {

        if( sum >= M ) {
            if( sum == M) {
                ans++;
            }
            sum -= vec[s++];
        }

        else if ( e >= N ) s++;
        else {
            sum += vec[e];
            e++;
        }

    }
}
int main() {
    init();
//    cout << vec[0] << endl;
    sol();
    cout << ans << endl;
    return 0;
}
