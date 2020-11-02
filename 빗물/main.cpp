#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int row, col = 0;
int ans = 0;

vector<int> vec;

void init() {
    cin >> col >> row;
    for(int i = 0; i < row; i++) {
        int input = 0;
        cin >> input;
        vec.push_back(input);
    }
}
void sol() {
    init();
    for(int i = 1; i < vec.size()-1; i++) {
        int left = *max_element(vec.begin(), vec.begin()+i);
        int right = *max_element(vec.begin()+i+1, vec.end());
        int MIN = min(left,right);
        if( MIN == 0 || MIN - vec[i] < 0 ) continue;
//        cout << " i : " << i << " " << left <<"," << right << " MAX : " << MAX << endl;

        ans += MIN - vec[i];
        vec[i] += MIN - vec[i];
    }

    cout << ans << endl;
}
int main() {
    sol();
    return 0;

}
