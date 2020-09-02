#include <iostream>
#include <vector>

using namespace std;

int main() {
    int start = 0, end = 0;
    vector<int> vec;

    int N = 0, M = 0;
    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        int input = 0;
        scanf("%d", &input);
        vec.push_back(input);
    }
    int sum = 0, cnt = 0;

    for(int start = 0; start < vec.size(); start++) {

        while( end < N && sum < M ) {
            sum += vec[end];
            end++;
        }
        if ( sum == M ) cnt++;
        sum -= vec[start];
    }

    printf("%d", cnt);
    return 0;
}
