#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

set<int, greater<>> st;

void twoPointer(vector<int> fruitWeights, int k) {
    int start = 0, end = 0;

    int cnt = 0;
    while ( start < fruitWeights.size() ) {
        if ( cnt < k ) {
            end++;
            cnt++;
        } else if ( cnt >= k ) {
            if ( cnt == k ) {
                st.insert(*max_element(fruitWeights.begin() + start, fruitWeights.begin() + end));
            }
            start++;
            cnt--;
        }

    }
}
vector<int> solution(vector<int> fruitWeights, int k) {
    twoPointer(fruitWeights, k);
    vector<int> answer;
    for(auto i = st.begin(); i != st.end(); i++) {
        answer.push_back(*i);
    }

    for(int i : answer) {
        cout << i << " ";
    }
    return answer;
}

int main() {
    //{10, 20, 30, 40, 50}
    //{30, 40, 10, 20, 30}
    solution({30, 40, 10, 20, 30}, 3);
    return 0;
}