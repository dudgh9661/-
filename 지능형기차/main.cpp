#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace  std;

int main() {
    vector<int> station;
    //1. 각 역 별로 현재 탑승 인원을 저장한다.
    int input, output;
//    scanf("%d %d", &input, &output);
//    int number = output - input;
//    printf("%d\n", number);
    int number = 0;
//    station.push_back(number);

    for(int i = 0; i < 4; i++) {
        scanf("%d %d", &input, &output);
        number = number + (output - input);
//        printf("%d\n", number);
        station.push_back(number);
    }

    sort(station.begin(), station.end(), greater<int>());
    printf("%d\n", station[0]);
    //2.최대값을 뽑는다.

    return 0;
}
