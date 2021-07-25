#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> vec;

int main() {
    cin >> N;

    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for( int i : vec ) cout << i << " ";
    return 0;
}
