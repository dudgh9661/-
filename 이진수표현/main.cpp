#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;

int main() {

    int TC = 0;
    cin >> TC;
    for(int tc = 1; tc <= TC; tc++) {
        vector<int> vec;

        int N, M;
        cin >> N >> M;
        int vCnt = 0;

        while (true) {
            int mok = M / 2;
            int rem = M % 2;
            vec.push_back(rem);
            vCnt++;

            M = mok;
            if (mok == 0 || vCnt == N ) break;
        }

        int flag = 0;
        for (int i = 0; i < N; i++) {
            if (vec[i] != 1) {
                cout << "#" << TC << " OFF" << endl;
                flag = 1;
                break;
            }
        }
        if( flag != 1 ) {
            cout << "#" << TC << " ON" << endl;
        }
    }
    return 0;
}
