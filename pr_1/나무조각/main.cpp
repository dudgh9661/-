#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void Print(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}
int main() {
    vector<int> vec;

    for(int i = 0; i < 5; i++) {
        int input = 0;
        scanf("%d", &input);
        vec.push_back(input);
    }

//    Print(vec);
    int flag = 1;
    int cnt = 0;
    while( cnt != 4 ) {
        cnt = 0;
        for (int i = 0; i < 4; i++) {
            if (vec[i] > vec[i + 1]) {
                swap(vec[i], vec[i+1]);
//                int tmp = vec[i+1];
//                vec[i+1] = vec[i];
//                vec[i] = tmp;

                flag = 1;
                Print(vec);
                continue;
            } else {
                cnt++;
            }
        }
    }

    return 0;
}
