#include <iostream>
#include <vector>

using namespace std;

int N;
int ans = 0;

vector<int> vec;
int arr[3] = {0,1,2};
void init() {
    cin >> N;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
    }
}

void sol() {
    int idx = 0;

    for(int i = 0; i < vec.size(); i++) {
        if( vec[i] == arr[idx] ) {
            idx++;
            ans++;
        }
        if( idx == 3 ) idx = 0;
    }
}
int main() {
    init();
    sol();
    cout << ans << endl;
    return 0;
}
