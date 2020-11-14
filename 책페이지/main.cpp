#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

vector<int> cnt(10, 0);

void pushNum(int number) {
    int mok = 0;
    int remain = 0;

    while(1 ) {
        if( number == 0 ) {
            // cnt[remain] += 1;
            break;
        }
        mok = number / 10;
        remain = number % 10;
        number = mok;
        cnt[remain] += 1;

        // printf("mok, remain (%d, %d)\n", mok, remain);
    }
}

int main() {

    int N = 0;
    scanf("%d", &N);
    
    string number;

    // printf("%d", '10');

    // printf("size : %lu", cnt.size());

    for(int i = 1; i <= N; i++) {

        pushNum(i);
        
    }

    for(int i = 0; i < cnt.size(); i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}
