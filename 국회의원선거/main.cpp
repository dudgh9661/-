#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;

vector<int> vec;

void init() {
    cin >> N;
    int input;

    for(int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
    }
}
int sol() {
    int CNT = 0;

    while( 1 ) {
        int MAX = *max_element(vec.begin(), vec.end());
        int maxIdx = max_element(vec.begin(), vec.end()) - vec.begin();

        if (MAX == vec[0]) {
            for (int i = 1; i < vec.size(); i++) {
                if (MAX == vec[i]) {
                    CNT++;
                    return CNT;
                }
            }
            return CNT;
        }

        vec[maxIdx]--;
        vec[0]++;
        CNT++;
    }
}
int main() {
    init();
    cout << sol() << endl;

    return 0;
}