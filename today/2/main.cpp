#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> vec;

int answer = 0;

void init() {
    cin >> N;
    int input;

    for(int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
    }

    sort(vec.begin(), vec.end(), less<>());
}

void DFS(int remain, int start, int end) {
    if ( remain < 4) {
        if ( remain == 3 ) {
            answer += vec[2];

            answer += vec[start];

            answer += vec[1];
        } else if ( remain == 2 ) {
            answer += vec[1];
        }

        return;
    }
    // cross the most faster
    answer += vec[start + 1];
    //come back 1st
    answer += vec[start];

    // cross the most slower
    answer += vec[end];
    //come back 2st
    answer += vec[start + 1];

    DFS(remain - 2, 0, end - 2);
}
int main() {
    init();
    DFS(vec.size(), 0, vec.size()-1);
    cout << answer << endl;
    return 0;
}
