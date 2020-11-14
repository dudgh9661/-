#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

int MOD(int N) {
    int cnt = 0;

    int mok = N / 10;
    while( mok > 0 ) {
        cnt++;
        int nextMok = mok;
        mok = nextMok / 10;
    }
    return cnt;
}

int main() {
    int N;
    scanf("%d", &N);

    int mod = MOD(N);
//    printf("mod : %d\n", mod);

    int cnt = 0;

    //mod는 몫의 자리수, N은 마지막 수
    cnt = ( mod + 1) * ( N - (int)pow(10, mod) + 1 );
//    printf("init cnt : %d\n", cnt);

    for(int i = mod - 1; i >= 0; i--) {
        int n = (int)pow(10, i + 1) - 1;
        cnt += ( i + 1 ) * ( n - (int)pow(10, i) + 1);
//        printf("i : %d n : %d cnt : %d\n", i, n, cnt);
    }
    printf("%d\n",cnt);
    return 0;
}
