#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> ans;

void init() {
    int input;
    for(int i = 0; i < 9; i++) {
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end(), less<int>());
}

void sol() {
    int sum = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = i+1; j < 4; j++) {
            for(int a = j+1; a < 5; a++) {
                for(int b = a+1; b < 6; b++) {
                    for(int c = b+1; c < 7; c++) {
                        for(int d = c+1; d < 8; d++) {
                            for(int e = d+1; e < 9; e++) {
                                sum = vec[i] + vec[j] + vec[a] + vec[b] + vec[c] + vec[d] + vec[e];
                                if( sum == 100 ) {
//                                    cout << "find " << endl;
                                    ans.push_back(vec[i]);
                                    ans.push_back(vec[j]);
                                    ans.push_back(vec[a]);
                                    ans.push_back(vec[b]);
                                    ans.push_back(vec[c]);
                                    ans.push_back(vec[d]);
                                    ans.push_back(vec[e]);
                                    return;
                                } else sum = 0;

                            }
                        }
                    }
                }
            }
        }
    }
}
int main() {
    init();
    sol();
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}
