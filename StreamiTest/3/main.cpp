#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MIN = 1e9;
vector<int> C;
vector<int> vec;
int solution(vector<int> &A, vector<int> &B) {
    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > B[i]) {
            C.push_back(A[i]);
            vec.push_back(B[i]);
//            MIN = min(MIN, B[i]);
        }
        else {
            C.push_back(B[i]);
            vec.push_back(A[i]);
            MIN = min(MIN, A[i]);
        }
    }
//    for (int n : vec) {
//        cout << n << endl;
//    }
    sort(vec.begin(), vec.end(), less<>());
//    cout << "min : " << MIN << endl;
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
//    cout << "unique" << endl;
//    for (int n : vec) {
//        cout << n << endl;
//    }
//    cout << endl;
    for (int n : vec) {
        if (find(C.begin(), C.end(), n) == C.end()) return n;
    }

    if (find(C.begin(), C.end(), MIN) == C.end()) return MIN;
    else return *max_element(C.begin(), C.end())+1;
}

int main() {
    vector<int> a = {1};
    vector<int> b = {1};
    cout << solution(a,b);
    return 0;
}
