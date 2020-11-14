#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num = 0;
    scanf("%d", &num);

    vector<int> A;
    vector<int> B;

    int inputA = 0;
    int inputB = 0;
    for(int i = 0; i < num; i++) {
        scanf("%d", &inputA);
        A.push_back(inputA); 
    }

    for(int i = 0; i < num; i++) {
        scanf("%d", &inputB);
        B.push_back(inputB); 
    }

    sort(A.begin(), A.end(), less<int>());
    cout << A[0] << endl;
    sort(B.begin(), B.end(), greater<int>());

    int total = 0;
    int sum = 0;

    for(int i = 0; i < num; i++) {
        sum = A[i] * B[i];
        total += sum;
    }


    
    printf("%d\n", total);
    return 0;
}