#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> lis;
vector<int> last;
vector<int> vec;
vector<int> tmp;

void init() {
    cin >> N;

    int input;
    for(int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
    }
}

void LIS(int pos) {
    for(int i = tmp.size() - 1; i >= 0 ; i--) {
        if( pos == tmp[i] ) {
            last.push_back(vec[i]);
            pos--;
        }
    }
    reverse(last.begin(), last.end());
}


void sol() {
    int pos = 0;
    for(int i = 0; i < vec.size(); i++) {
        if( lis.empty() ) {
            lis.push_back(vec[i]);
            tmp.push_back(pos);
        }
        else {
            if( lis.back() > vec[i] ) {
                int idx = lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin();
                lis[idx] = vec[i];
                tmp.push_back(idx);
            } else {
                lis.push_back(vec[i]);
                tmp.push_back(++pos);
            }
        }
    }
    LIS(pos);
}
void solution() {
    init();
    sol();
}
int main() {
    solution();
    for(int i = 0; i < last.size(); i++) cout << last[i] << " ";
    return 0;
}
