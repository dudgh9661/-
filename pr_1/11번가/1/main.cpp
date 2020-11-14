#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

int visited[MAX] = { 0 };

vector<int> ans;
int answer = -100;

void init() {
    for(int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
}
int len(int x, vector<int> A) {
    vector<int> left;
    vector<int> right;

    for(int i = 0; i < A.size(); i++) {

        if( x > A[i] && visited[A[i]] == 0) {
            left.push_back(A[i]);
//            cout << "left : " << A[i] << endl;
            visited[A[i]] += 1;
        } else if ( x > A[i] && visited[A[i]] == 1 ) {
            right.push_back(A[i]);
//            cout << "right : " << A[i] << endl;
            visited[A[i]] += 1;
        }
    }

    sort(left.begin(), left.end(), less<int>());
    sort(right.begin(), right.end(), greater<int>());
    int length = left.size() + right.size() + 1;

    for(int i = 0; i < left.size(); i++) {
        ans.push_back(left[i]);
    }
    ans.push_back(x);
    for(int i = 0; i < right.size(); i++) {
        ans.push_back(right[i]);
    }

    return length;
}
//A로부터 만들어질 수 있는 가장 긴 길이의 spike를 출력해
int solution(vector<int> &A) {
//    answer = len(5,A);
    for(int i = 0; i < A.size(); i++) {
        int output = len(A[i],A);
        if (answer < output) {
            answer = output;
        }
        init();
    }

}

int main() {
    vector<int> A{1,2,3,2};
//    vector<int> A{2,5,3,2,4,1};
    solution(A);
    cout << answer << endl;
//    cout << ans.size();
//    for(int i = 0; i < ans.size(); i++) {
//        cout << ans[i] << " ";
//    }
}
