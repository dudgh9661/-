#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// output : 가장 큰 홀수와 짝수의 합을 리턴해라.
int solution(vector<int> &A) {
    int odd = 0;
    int even = 0;

    for (int i = 0; i < A.size(); i++) {
        int num = A[i];
        if (num % 2 == 0) {
            even = max(even, num);
        } else {
            odd = max(odd,num);
        }
    }

    return even + odd;
}

int main() {
    vector<int> tmp = {1,1,2};
    int ans = solution(tmp);
    cout << "ans : " << ans << endl;

    return 0;
}
