#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char input[81];

    for(int i = 0; i < N; i++) {
        int ans = 0;
        int cnt = 1;

        scanf("%s", input);
//        printf("%s", input);

        for(int itr = 0; itr < strlen(input); itr++) {
            if( input[itr] == 'O') {
                ans += cnt++;
            }
            else if ( input[itr] == 'X') {
                cnt = 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
    //1. O가 나오면 총 점수에 더해주고 cnt++를 해준다.
    //2. 다음으로 X가 나오면 cnt = 1로 바꿔준다.

