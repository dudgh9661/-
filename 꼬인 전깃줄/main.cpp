#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> vec;
vector<int> lis;
void sol() {
    for(int i = 0; i < vec.size(); i++) {
        if (lis.empty()) lis.push_back(vec[i]);
        else {
            if (vec[i] > lis.back()) {
                lis.push_back(vec[i]);
            } else {
                int idx = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
                lis[idx] = vec[i];
            }
        }
    }
//    for(int i = 0; i < lis.size(); i++) {
//        cout << lis[i] << " ";
//    }
    cout << N - lis.size() << endl;

}
void input() {
    cin >> N;

    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        vec.push_back(a);
    }
}
int main() {
    input();
    sol();
    return 0;
}
