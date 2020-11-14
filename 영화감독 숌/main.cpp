#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {

    int N = 0;
    scanf("%d", &N);

    int inputNumber = N - 1;
    string inputString  = to_string(inputNumber) + "666";
    // cout << front;

    cout << inputString << endl;
    return 0;
}